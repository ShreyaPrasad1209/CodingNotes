#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

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

	//Entire screen draw part is in a scope before GLFW terminate function called because the stack allocated class objects
	//Of index and vertex buffer will not be destroyed and GLFW window will get destroyed first so an error will show
	//We can also do heap allocation and then delete manually before glfw termination
	{
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

		VertexArray va;
		VertexBuffer vb(positions, 4 * 2 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);
		
		Shader shader("res/shaders/Basic2.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		Renderer renderer;
		
		float r = 0.8f;
		float increment = 0.01f;

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
			renderer.Draw(va, ib, shader);

			r += increment;
			if (r >= 1.0f || r <= 0.0f)
				increment *= -1;

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}
