#include"checkError.h"
//check error
#include<glad/glad.h>
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

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