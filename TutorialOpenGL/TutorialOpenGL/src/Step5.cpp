#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//In the previous square example two coordinates are repeated in positions which means we can optimize it further
//In cases where complex model is displayed this minor change plays a big role
//Index buffer is used to achieve this result

#define ASSERT(x) if (!x) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* program, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ") : " << program << " : " << line << std::endl;
		return false;
	}
	return true;
}

struct ShaderProgramSource
{
	std::string VertexShader;
	std::string FragmentShader;
};

static ShaderProgramSource ParseShader(const std::string &filepath)
{
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	std::ifstream stream(filepath);
	std::stringstream ss[2];
	std::string line;
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
			ss[(int)type] << line << "\n";
	}

	return{ ss[0].str(), ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " <<
			(type == GL_VERTEX_SHADER ? "vertex" : "fragment") <<
			std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);

		return 0;
	}

	return id;
}

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vertShader = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fragShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	return program;
}

int main5(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[] =
	{
		-0.5f, -0.5,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
	};

	unsigned int indices[] = 
	{
		0, 1, 2,
		2, 3, 0
	};

	unsigned int buffer;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), &positions, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0));

	unsigned int ibo;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * 2 * sizeof(unsigned int), &indices, GL_STATIC_DRAW));

	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
	unsigned int shader = CreateShader(source.VertexShader, source.FragmentShader);
	GLCall(glUseProgram(shader));

	while (!glfwWindowShouldClose(window))
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	GLCall(glDeleteProgram(shader));

	glfwTerminate();
	return 0;
}