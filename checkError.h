#pragma once

void checkError();

//Ԥ�����
#ifdef DEBUG
#define GL_CALL(func) func;checkError();
#else
#define GL_CALL(func) func;
#endif



