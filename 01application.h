//1.������ȫ��Ψһʵ��
#pragma once
#include<iostream>
#define Mapp Application::getInstance()
#include<glad/glad.h>
#include<GLFW/glfw3.h>

class Application
{
public:
	
	~Application();
	//���ڷ���ʵ���ľ�̬����
	static Application* getInstance();
	void test() { std::cout << "test" << std::endl; }

	uint32_t getWidth()const { return mWidth; }
private:
	//ȫ��Ψһ�ľ�̬����ʵ��
	static Application* mInstance;

	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };

	Application();
};

