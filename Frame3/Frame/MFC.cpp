#include "pch.h"
#include "MFC.h"
#include "myHeader/myMFC.h"  // it should be mfc.h, but for CMyWinApp definition, so...

extern CMyWinApp theApp;

static char szCObject[] = "CObject";
struct CRuntimeClass CObject::classCObject =
{ szCObject, sizeof (CObject), 0xffff, nullptr, nullptr, nullptr };
static AFX_CLASSINIT _init_CObject (&CObject::classCObject);

CRuntimeClass * CRuntimeClass::firstClass = nullptr;

CRuntimeClass * CObject::m_GetRuntimeClass () const
{
	return &CObject::classCObject;
}

CWinApp * AfxGetApp ()
{
	return theApp.m_currentWinApp;
}

IMPLEMENT_DYNAMIC (CCmdTarget, CObject)
IMPLEMENT_DYNAMIC (CWinThread, CCmdTarget)
IMPLEMENT_DYNAMIC (CWinApp, CWinThread)
IMPLEMENT_DYNAMIC (CWnd, CCmdTarget)
IMPLEMENT_DYNAMIC (CFrameWnd, CWnd)
IMPLEMENT_DYNAMIC (CDocument, CCmdTarget)
IMPLEMENT_DYNAMIC (CView, CWnd)