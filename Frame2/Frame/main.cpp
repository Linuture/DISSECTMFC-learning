// Frame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"myHeader/myMFC.h"
using namespace std;

CMyWinApp theApp;

int main()
{
	CWinApp * thisApp = AfxGetApp ();

	thisApp->m_InitApplication ();
	thisApp->m_InitInstance ();
	thisApp->m_Run ();

	return 0;
}