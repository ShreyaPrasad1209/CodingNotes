#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw_gl3.h"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Scene", NULL, NULL);
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

	//texture coordinates are required to tell which pixel has which color
	float positions[] =
	{
		//texCoordinates here 0,0 means bottom left part
		-50.0f, -50.0f, 0.0f, 0.0f,
		 50.0f, -50.0f, 1.0f, 0.0f,
		 50.0f,  50.0f, 1.0f, 1.0f,
		-50.0f,  50.0f, 0.0f, 1.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_BLEND));

	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);
	
	Shader shader("res/shaders/Basic3.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

	glm::mat4 proj = glm::ortho(0.0f, (float)SCREEN_WIDTH, 0.0f, (float)SCREEN_HEIGHT, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	shader.SetUniformMat4f("u_MVP", proj * view);

	Texture texture("res/textures/pikachu.png");

	//At the time of bind slot is defined 0 to 32 (max) in mobile devices it may be like 8
	//Slots are used to draw textures overlapping
	//Uniform value is same as the slot of the texture
	texture.Bind(0);
	shader.SetUniform1i("u_Texture", 0);

	Renderer renderer;

	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();
		
	float r = 0.8f;
	float increment = 0.01f;
	glm::vec3 translationA(0, 0, 0);
	glm::vec3 translationB(100, 0, 0);

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		ImGui_ImplGlfwGL3_NewFrame();

		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);

			shader.Bind();
			shader.SetUniformMat4f("u_MVP", proj * view * model);
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ib, shader);
		}

		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);

			shader.Bind();
			shader.SetUniformMat4f("u_MVP", proj * view * model);
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ib, shader);
		}

		r += increment;
		if (r >= 1.0f || r <= 0.0f)
			increment *= -1;

		{
			ImGui::SliderFloat3("TranslationA", &translationA.x, 0.0f, SCREEN_WIDTH);
			ImGui::SliderFloat3("TranslationB", &translationB.x, 0.0f, SCREEN_WIDTH);
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		}

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();

	return 0;
}
