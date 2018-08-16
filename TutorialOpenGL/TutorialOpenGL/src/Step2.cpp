#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//Instead of specifying through OpenGL that it's a triangle we can specify it more flexibly
int main2(void)
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

	float positions[6] =
	{
		-0.5f, -0.5,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	//Once buffer binded
	//1) index is the index of the vertex attribute
	//2) size is the size of values we have like here 2 floats for the coordinates
	//3) stride is the memory size needed to go from one vertex to another here only coordinates
	//   are considered say if normals also then that also would been added
	//4) pointer is the offset of memory needed to go to other attribute like from coordinates to
	//   normals here only coordinates so 0
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	//Enabling of array vertex attrib can be done before also since open GL is a state machine it won't
	//check if it is enabled or not it will just perform it as long as the buffer is binded

	//Running program will still work since some GPU provides shaders if there is no shader added
	while (!glfwWindowShouldClose(window))
	{

		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}