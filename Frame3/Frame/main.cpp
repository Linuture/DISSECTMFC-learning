// Frame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"myHeader/myMFC.h"
using namespace std;

CMyWinApp theApp;

void PrintAllClasses ()
{
	CRuntimeClass * pClass;

	// just walk through the simple list of registered classes
	for (pClass = CRuntimeClass::firstClass; pClass != nullptr;
		pClass = pClass->m_nextClass)
	{
		cout << pClass->m_className << "\n";
		cout << pClass->m_objectSize << "\n";
		cout << pClass->m_schema << "\n";
	}
}

int main()
{
	CWinApp * thisApp = AfxGetApp ();

	thisApp->m_InitApplication ();
	thisApp->m_InitInstance ();
	thisApp->m_Run ();

	PrintAllClasses ();

	return 0;
}