#include<iostream>
using namespace std;
#include<glad/glad.h>
#include<GLFW/glfw3.h>

//response window change function
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	cout << "window size:" << width << "," << height << endl;

}

//define keyboard callback function
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A)
	{
		cout << "press A" << endl;
	}
	if (action == GLFW_PRESS)
	{
		cout << "Press!" << endl;
	}
	cout << "mods: " << mods << endl;

}
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

	//monitor window change news
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);

	//monitor window keyboard news
	glfwSetKeyCallback(window, keyCallBack);

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