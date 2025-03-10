#include"application.h"


//初始化Application的静态变量
Application* Application::mInstance = nullptr;
Application* Application::getInstance()
{
	//如果mInstance已经实例化就直接返回
	//否则实例化后再返回
	if (mInstance == nullptr)
	{
		mInstance = new Application();
	}
	return mInstance;

}
Application::~Application()
{

}

Application::Application()
{

}