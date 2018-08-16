#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main1(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	//vertext is not equivalent to coordinates.
	//A vertex also includes more informations like tangents, normals, texture coordinates, etc.
	float positions[6] =
	{
		-0.5f, -0.5,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	//state of a buffer like 1, 2, 3. 0 is an invalid state.
	//It's also can be called as an id of that buffer or later shader (any object)
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	//Binding buffer means that it will be used so glDrawArrays will use this buffer only
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions, GL_STATIC_DRAW);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		/*
		Legacy OpenGL
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		*/

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}