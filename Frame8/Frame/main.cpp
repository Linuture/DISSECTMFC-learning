// Frame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"myHeader/myMFC.h"
using namespace std;

CMyWinApp theApp;

void PrintlpEntries (AFX_MSGMAP_ENTRY * theEntry)
{
	struct {
		INT m_classID;
		LPCSTR m_className;
	} classInfo[ ] = {
						CCmdTargetid ,  "CCmdTarget   ",
						CWinThreadid ,  "CWinThread   ",
						CWinAppid    ,  "CWinApp      ",
						CMyWinAppid  ,  "CMyWinApp    ",
						CWndid       ,  "CWnd         ",
						CFrameWndid  ,  "CFrameWnd    ",
						CMyFrameWndid,  "CMyFrameWnd  ",
						CViewid      ,  "CView        ",
						CMyViewid    ,  "CMyView      ",
						CDocumentid  ,  "CDocument    ",
						CMyDocid     ,  "CMyDoc       ",
						0            ,  "             "
	};

	for (int i = 0; classInfo[i].m_classID != 0; i++)
	{
		if (classInfo[i].m_classID == theEntry->nID)
		{
			cout << classInfo[i].m_classID << "    ";
			cout << classInfo[i].m_className << endl;
			break;//now the break here is equvalent to the return
		}
	}

	return;
}

void MsgMapPrinting (AFX_MSGMAP * theMessageMap)
{
	for (; theMessageMap != nullptr; theMessageMap = theMessageMap->m_baseMessageMap) 
	{
		AFX_MSGMAP_ENTRY * thisEntry = theMessageMap->m_entries;
		PrintlpEntries (thisEntry);
	}
}

int main()
{
	CWinApp * thisApp = AfxGetApp ();

	thisApp->CWinApp::m_InitApplication ();
	thisApp->m_InitInstance ();
	thisApp->CWinApp::m_Run ();

	CMyDoc* pMyDoc = new CMyDoc;
	CMyView* pMyView = new CMyView;
	CFrameWnd* pMyFrame = (CFrameWnd*)thisApp->m_mainWnd;
	pMyFrame->m_viewActive = pMyView;
	pMyView->m_document = pMyDoc;

	// test Message Routing
	cout << endl << "pMyFrame receive WM_CREATE, ";
	cout << "routing path and call stack:" << endl;
	AfxWndProc (0, WM_CREATE, 0, 0, pMyFrame);

	cout << endl << "pMyView receive WM_PAINT, ";
	cout << "routing path and call stack:" << endl;
	AfxWndProc (0, WM_PAINT, 0, 0, pMyView);

	cout << endl << "pMyView receive WM_COMMAND, ";
	cout << "routing path and call stack:" << endl;
	AfxWndProc (0, WM_COMMAND, 0, 0, pMyView);

	cout << endl << "pMyFrame receive WM_COMMAND, ";
	cout << "routing path and call stack:" << endl;
	AfxWndProc (0, WM_COMMAND, 0, 0, pMyFrame);
}