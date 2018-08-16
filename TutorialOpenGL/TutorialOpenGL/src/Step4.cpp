#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

int main4(void)
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

	//Triangles are the primitive drawing unit so say if we want to draw a square we need two right handed triangles
	float positions[12] =
	{
		-0.5f, -0.5,
		 0.5f, -0.5f,
		 0.5f,  0.5f,

		 0.5f,  0.5,
		-0.5f,  0.5f,
		-0.5f, -0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), &positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
	unsigned int shader = CreateShader(source.VertexShader, source.FragmentShader);
	glUseProgram(shader);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}