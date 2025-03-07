#include<iostream>
using namespace std;
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	//init window
	glfwInit();

	//set major/minor veision (4.6)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//SET CORE(NOT  immediately render)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//set window
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLStudy", NULL, NULL);

	//render window
	glfwMakeContextCurrent(window);

	//window cycle
	while (!glfwWindowShouldClose(window))
	{
		//receive and sent news
		glfwPollEvents();
	}

	//exit window clean
	glfwTerminate();

	return 0;
}