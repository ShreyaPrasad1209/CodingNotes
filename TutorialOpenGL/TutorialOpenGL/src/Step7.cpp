#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define ASSERT(x) if (!(x)) __debugbreak();
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

int main7(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	//Default profile is compat profile
	//In compatibility profile there is a vertex array object defined already so if after binding vertex attribute if
	//we bind again with 0 id which means default defined only in compat mode then it will give error in core mode at runtime
	//Error will assert at glEnableVertexAttribArray(0)
	//The compatibility openGL profile makes VAO object 0 a default object. The core openGL makes VAO object 0 not an object at all
	//So to fix this we need to create a VAO object (Vertex Array Object) manually in core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

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

	//Vertex Array Object encapsulates all the vertexBuffers, Index buffers and layout specifications so if you need to draw
	//a mesh then binding a vertex array object will take care of all bindings
	unsigned int vao;
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));

	//Vertex Buffers are added
	unsigned int buffer;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), &positions, GL_STATIC_DRAW));

	//Defining vertex attribute i.e. 2 coordinates are there they are called attribute
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0));

	//Index buffer is added
	unsigned int ibo;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), &indices, GL_STATIC_DRAW));

	ShaderProgramSource source = ParseShader("res/shaders/Basic2.shader");
	unsigned int shader = CreateShader(source.VertexShader, source.FragmentShader);
	GLCall(glUseProgram(shader));

	int location = glGetUniformLocation(shader, "u_Color");
	ASSERT(location != -1)
		GLCall(glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f));

	//GLCall(glUseProgram(0));
	//GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	//GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

	float r = 0.8f;
	float increment = 0.01f;

	while (!glfwWindowShouldClose(window))
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		//GLCall(glUseProgram(shader));
		GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));

		//No need to bind the buffer or vertex attribarray it's all there in VAO which is binded

		//GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
		//GLCall(glEnableVertexAttribArray(0));
		//GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
		//GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));

		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		r += increment;
		if (r >= 1.0f || r <= 0.0f)
			increment *= -1;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	GLCall(glDeleteProgram(shader));

	glfwTerminate();
	return 0;
}

//So with this only vertex array object is needed to binded and ofcurse shader