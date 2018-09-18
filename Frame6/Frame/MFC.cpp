#include "pch.h"
#include "MFC.h"
#include "myHeader/myMFC.h"  // it should be mfc.h, but for CMyWinApp definition, so...

extern CMyWinApp theApp;

static char szCObject[] = "CObject";
struct CRuntimeClass CObject::classCObject =
{ szCObject, sizeof (CObject), 0xffff, nullptr, nullptr, nullptr };
static AFX_CLASSINIT _init_CObject (&CObject::classCObject);

CRuntimeClass * CRuntimeClass::firstClass = nullptr;

CWinApp * AfxGetApp ()
{
	return theApp.m_currentWinApp;
}

CObject * CRuntimeClass::m_CreateObject ()
{
	if (this->m_createObject == nullptr)
	{
		return nullptr;
	}
	else
	{
		CObject * newObject = nullptr;
		newObject = (*(this->m_createObject))();

		return newObject;
	}
}

CRuntimeClass * PASCAL CRuntimeClass::Load (char * myClassName)
{
	// JJHOU : instead of Load from file, we Load from cin.

	CRuntimeClass * myClass = CRuntimeClass::firstClass;

	while (myClass != nullptr)
	{
		if (strcmp (myClassName, myClass->m_className) == 0)
		{
			return myClass;
		}
		else
		{
			myClass = myClass->m_nextClass;
		}
	}

	return nullptr; // not found

/*	for (myClass = CRuntimeClass::firstClass; 
		 myClass != nullptr; 
		 myClass = myClass->m_nextClass)
	{
		if (strcmp (myClassName, myClass->m_className) == 0)
		{
			return myClass;
		}
	}*/
}

IMPLEMENT_DYNAMIC (CCmdTarget, CObject)
IMPLEMENT_DYNAMIC (CWinThread, CCmdTarget)
IMPLEMENT_DYNAMIC (CWinApp, CWinThread)
IMPLEMENT_DYNCREATE (CWnd, CCmdTarget)
IMPLEMENT_DYNCREATE (CFrameWnd, CWnd)
IMPLEMENT_DYNAMIC (CView, CWnd)
IMPLEMENT_DYNAMIC (CDocument, CCmdTarget)