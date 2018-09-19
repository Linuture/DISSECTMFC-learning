#include "pch.h"
#include "MFC.h"
#include "myHeader/myMFC.h"  // it should be mfc.h, but for CMyWinApp definition, so...

extern CMyWinApp theApp;

extern void PrintlpEntries (AFX_MSGMAP_ENTRY * theEntry);
extern void MsgMapPrinting (AFX_MSGMAP * theMessageMap);

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

BOOL CCmdTarget::m_OnCmdMsg (UINT nID, int nCode)
{
	cout << "CCmdTarget::OnCmdMsg()" << endl;
	// Now look through message map to see if it applies to us
	AFX_MSGMAP * pMessageMap = this->m_GetMessageMap ( );

	MsgMapPrinting (pMessageMap);

	return FALSE;   // not handled
}

LRESULT CWnd::m_WindowProc (UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	cout << "CWnd::WindowProc()" << endl;
	if (nMsg == WM_COMMAND) // special case for commands
	{
		if (this->m_OnCommand (wParam, lParam))
			return 1L; // command handled
		else
			return (LRESULT)this->CWnd::m_DefWindowProc (nMsg, wParam, lParam);
	}
	else
	{
		AFX_MSGMAP * pMessageMap = this->m_GetMessageMap ( );

		MsgMapPrinting (pMessageMap);

		return 0;  // J.J.Hou: if find, should call lpEntry->pfn,
				   // otherwise should call DefWindowProc.
				   // for simplization¡A we just return 0.
	}
}

BOOL CFrameWnd::m_OnCmdMsg (UINT nID, int nCode)
{
	cout << "CFrameWnd::OnCmdMsg()" << endl;
	// pump through current view FIRST
	CView * pView = this->m_GetActiveView ( );

	if (pView->m_OnCmdMsg (nID, nCode))
		return TRUE;

	// then pump through frame
	if (this->CCmdTarget::m_OnCmdMsg (nID, nCode))
		return TRUE;

	// last but not least, pump through app
	CWinApp * pApp = AfxGetApp ( );

	if (pApp->CCmdTarget::m_OnCmdMsg (nID, nCode))
		return TRUE;

	return FALSE;
}

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

LRESULT AfxWndProc (HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam,
					CWnd *pWnd)  // last param. pWnd is added by JJHou.
{
	cout << "AfxWndProc()" << endl;
	return AfxCallWndProc (pWnd, hWnd, nMsg, wParam, lParam);
}

LRESULT AfxCallWndProc (CWnd* pWnd, HWND hWnd, UINT nMsg,
						WPARAM wParam, LPARAM lParam)
{
	cout << "AfxCallWndProc()" << endl;
	LRESULT lResult = pWnd->CWnd::m_WindowProc (nMsg, wParam, lParam);
	return lResult;
}