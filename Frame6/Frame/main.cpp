// Frame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "MFC.h"
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
	/* //Frame4
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
	*/
	
	//Test Dynamic Creation

	while (1)
	{
		char szClassName[64];
		cout << "Please enter a class name...  ";
		cin >> szClassName;

		CRuntimeClass * classRef;
		classRef = CRuntimeClass::Load (szClassName);
		if (classRef == nullptr)
		{
			TRACE1 ("Error: Class not found: %s \n", szClassName);
			break;
		}
		else 
		{
			CObject * myObject;
			myObject = classRef->m_CreateObject ();
			if (myObject != nullptr)
			{
				cout << "Hello, "<<classRef->m_className << endl;
			}
			else
			{
				TRACE1 ("Error: Trying to create object which is not "
						"DECLARE_DYNCREATE \nor DECLARE_SERIAL: %hs.\n",
						classRef->m_className);
			}
		}
		
	}

	return 0;
}