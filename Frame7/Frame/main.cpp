// Frame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"myHeader/myMFC.h"
using namespace std;

CMyWinApp theApp;

void  printlpEntries (AFX_MSGMAP_ENTRY * theEntry)
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
			break;
		}
	}

	return;
}

void MsgMapPrinting (AFX_MSGMAP * theMessageMap)
{
	for (; theMessageMap != NULL; theMessageMap = theMessageMap->m_baseMessageMap) {
		AFX_MSGMAP_ENTRY * thisEntry = theMessageMap->m_entries;
		printlpEntries (thisEntry);
	}
}

int main()
{
	CWinApp * thisApp = AfxGetApp ();

	thisApp->CWinApp::m_InitApplication ();
	thisApp->m_InitInstance ();
	thisApp->CWinApp::m_Run ();

	CMyDoc * pMyDoc = new CMyDoc;
	CMyView * pMyView = new CMyView;
	CFrameWnd * pMyFrame = (CFrameWnd *)thisApp->m_mainWnd;

	// output Message Map construction
	AFX_MSGMAP * pMessageMap = pMyView->m_GetMessageMap ( );
	cout << endl << "CMyView Message Map : " << endl;
	MsgMapPrinting (pMessageMap);

	pMessageMap = pMyDoc->m_GetMessageMap ( );
	cout << endl << "CMyDoc Message Map : " << endl;
	MsgMapPrinting (pMessageMap);

	pMessageMap = pMyFrame->m_GetMessageMap ( );
	cout << endl << "CMyFrameWnd Message Map : " << endl;
	MsgMapPrinting (pMessageMap);

	pMessageMap = thisApp->m_GetMessageMap ( );
	cout << endl << "CMyWinApp Message Map : " << endl;
	MsgMapPrinting (pMessageMap);

	return 0;
}