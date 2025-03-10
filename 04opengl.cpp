#include<iostream>
using namespace std;
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<assert.h>
#include"wrapper/checkError.h"
#include"application/application.h"
//response window change function
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	cout << "window size:" << width << "," << height << endl;
	glViewport(0, 0, width, height);
}
//check error
void checkError()
{
	string error = "";
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR)
	{
		switch (errorCode)
		{
		case GL_INVALID_ENUM:error = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:error = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:error = "INVALID_OPERATION"; break;
		case GL_OUT_OF_MEMORY:error = "OUT_OF_MOMORY"; break;

		default:
			error = "UNKNOW ERROR!";
			break;
		}
		cout << error << endl;
		assert(false);
	}

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

	Mapp->test();
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

	//load opengl function
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Fail to initialize GLAD!" << endl;
		return -1;
	}

	//set opengl viewport and clean collor
	GL_CALL(glViewport(0, 0, 600, 800));
	GL_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));


	//window cycle
	while (!glfwWindowShouldClose(window))
	{
		//receive and sent news
		glfwPollEvents();

		//clean opengl canvas  operation
		//glClear(GL_COLOR_BUFFER_BIT);
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
		
		

		//render

		//double buffer
		glfwSwapBuffers(window);

	

	}

	//exit window clean
	glfwTerminate();

	return 0;
}