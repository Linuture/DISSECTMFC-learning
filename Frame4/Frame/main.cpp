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

	//PrintAllClasses (); //Frame3

	CMyDoc * myDoc = new CMyDoc;
	CMyView * myView = new CMyView;
	CWnd * myWnd = thisApp->m_mainWnd;

	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CMyDoc))     " << myDoc->IsKindOf (RUNTIME_CLASS (CMyDoc)) << "\n";
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CDocument))  " << myDoc->IsKindOf (RUNTIME_CLASS (CDocument)) << "\n";
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CCmdTarget)) " << myDoc->IsKindOf (RUNTIME_CLASS (CCmdTarget)) << "\n";
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CObject))    " << myDoc->IsKindOf (RUNTIME_CLASS (CObject)) << "\n";
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CWinApp))    " << myDoc->IsKindOf (RUNTIME_CLASS (CWinApp)) << "\n";
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CView))      " << myDoc->IsKindOf (RUNTIME_CLASS (CView)) << "\n";

	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CView))     " << myView->IsKindOf (RUNTIME_CLASS (CView)) << "\n";
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CObject))   " << myView->IsKindOf (RUNTIME_CLASS (CObject)) << "\n";
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CWnd))      " << myView->IsKindOf (RUNTIME_CLASS (CWnd)) << "\n";
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CFrameWnd)) " << myView->IsKindOf (RUNTIME_CLASS (CFrameWnd)) << "\n";

	cout << "pMyWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))  " << myWnd->IsKindOf (RUNTIME_CLASS (CFrameWnd)) << "\n";
	cout << "pMyWnd->IsKindOf(RUNTIME_CLASS(CWnd))       " << myWnd->IsKindOf (RUNTIME_CLASS (CWnd)) << "\n";
	cout << "pMyWnd->IsKindOf(RUNTIME_CLASS(CObject))    " << myWnd->IsKindOf (RUNTIME_CLASS (CObject)) << "\n";
	cout << "pMyWnd->IsKindOf(RUNTIME_CLASS(CDocument))  " << myWnd->IsKindOf (RUNTIME_CLASS (CDocument)) << "\n";

	delete myDoc;
	delete myView;

	return 0;
}