// PythonEmbedding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Python.h>
#include <Windows.h>
#include <assert.h>
typedef int (__cdecl *MYPROC)(const char *); 

int _tmain(int argc, _TCHAR* argv[])
{
	/*HMODULE mod = LoadLibrary(L"Python27.dll");
	//HMODULE mod2 = LoadLibrary(L"../site-packages/PIL/_imaging.pyd");
	assert(mod != NULL);
   
	FARPROC Py_Initialize = (FARPROC)GetProcAddress(mod, "Py_Initialize");
	MYPROC PyRun_SimpleString = (MYPROC)GetProcAddress(mod, "PyRun_SimpleString");
	FARPROC Py_Finalize = (FARPROC)GetProcAddress(mod, "Py_Finalize");
	FARPROC PyErr_Print = (FARPROC)GetProcAddress(mod, "PyErr_Print");
	assert(NULL != Py_Initialize);*/

	Py_Initialize ();

	PyRun_SimpleString(
		"import sys, os\n"
		//"sys.path = ['../site-packages','../python-lib']\n"
		//"print os.getcwd()\n"
		//"from time import time,ctime\n"
		//"import sys\n"
		//"print 'Today is',ctime(time())\n"
		//"sys.path=['C:\\dev\\Python27', 'C:\\dev\\Python27\\Lib\\idlelib', 'C:\\Windows\\system32\\python27.zip', 'C:\\Dev\\Python27\\DLLs', 'C:\\Dev\\Python27\\lib', 'C:\\Dev\\Python27\\lib\\plat-win', 'C:\\Dev\\Python27\\lib\\lib-tk', 'C:\\Dev\\Python27', 'C:\\Dev\\Python27\\lib\\site-packages', 'C:\\Dev\\Python27\\lib\\site-packages\\PIL']\n"
		"print sys.path\n"
		//"import encodings.cp850\n"
		//"import _imaging\n"
		"from PIL import Image\n"
		"im = Image.new(\"RGB\",(255,255))\n"
		"im.save('test.png')\n"
		"print 'Saved test.png'\n"
		"import numpy as np\n"
		"a = np.array([[1,2],[3,4]])\n"
		"print 'Numpy test:', a.sum()\n"
		"import wx\n"
		);
	PyErr_Print();
	Py_Finalize();

	//BOOL fFreeResult = FreeLibrary(mod); 

	return 0;
}

