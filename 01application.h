//1.单例类全局唯一实例
#pragma once
#include<iostream>
#define Mapp Application::getInstance()
#include<glad/glad.h>
#include<GLFW/glfw3.h>

class Application
{
public:
	
	~Application();
	//用于访问实例的静态函数
	static Application* getInstance();
	void test() { std::cout << "test" << std::endl; }

	uint32_t getWidth()const { return mWidth; }
private:
	//全局唯一的静态变量实例
	static Application* mInstance;

	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };

	Application();
};

