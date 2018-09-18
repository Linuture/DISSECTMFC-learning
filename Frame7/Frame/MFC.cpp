#include "pch.h"
#include "MFC.h"
#include "myHeader/myMFC.h"  // it should be mfc.h, but for CMyWinApp definition, so...

extern CMyWinApp theApp;

CWinApp * AfxGetApp ()
{
	return theApp.m_currentWinApp;
}

AFX_MSGMAP CCmdTarget::m_messageMap =   // JJHOU: in MFC 40 cmdtarg.cpp
{
		nullptr,
		&CCmdTarget::m_messageEntries[0]
};

AFX_MSGMAP_ENTRY CCmdTarget::m_messageEntries[ ] = // JJHOU: in in MFC 40 cmdtarg.cpp
{
	// { 0, 0, 0, 0, AfxSig_end, 0 }     // nothing here
	   { 0, 0, CCmdTargetid, 0, AfxSig_end, 0 }
};

BEGIN_MESSAGE_MAP (CWnd, CCmdTarget)
	ON_COMMAND (CWndid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CFrameWnd, CWnd)
	ON_COMMAND (CFrameWndid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CDocument, CCmdTarget)
	ON_COMMAND (CDocumentid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CView, CWnd)
	ON_COMMAND (CViewid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CWinApp, CCmdTarget)
	ON_COMMAND (CWinAppid, 0)
END_MESSAGE_MAP ( )