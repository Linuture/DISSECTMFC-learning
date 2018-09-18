#pragma once
#ifndef _MFC_
#define _MFC_

#define BOOL int
#define TRUE 1
#define FALSE 0

#define LPCSTR  LPSTR
typedef char*   LPSTR;
#define UINT int
#define PASCAL _stdcall
#define TRACE1 printf

#include <iostream>
using namespace std;

class CObject;

struct CRuntimeClass
{
	// Attributes
	LPCSTR m_className;
	int m_objectSize;
	UINT m_schema; // schema number of the loaded class
	CObject * (PASCAL * m_createObject)(); // NULL => abstract class
	CRuntimeClass * m_baseClass;

	CObject * m_CreateObject ();
	static CRuntimeClass * PASCAL Load (char * myClassName);

	// CRuntimeClass objects linked together in simple list
	static CRuntimeClass * firstClass; // start of class list
	CRuntimeClass * m_nextClass;       // linked list of registered classes
};

struct AFX_CLASSINIT
{
	AFX_CLASSINIT (CRuntimeClass * newClass)
	{
		newClass->m_nextClass = CRuntimeClass::firstClass;
		CRuntimeClass::firstClass = newClass;
	}
};

#define RUNTIME_CLASS(class_name) \
        (&class_name::class##class_name)

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
        static char _lpsz##class_name[] = #class_name; \
        CRuntimeClass class_name::class##class_name = { \
                _lpsz##class_name, sizeof(class_name), wSchema, pfnNew, \
                        RUNTIME_CLASS(base_class_name), nullptr }; \
        static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
        CRuntimeClass * class_name::m_GetRuntimeClass() const \
                { return &class_name::class##class_name; } \

#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
        _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xffff, nullptr)

#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
        CObject * PASCAL class_name::CreateObject() \
                { return new class_name; } \
        _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xffff, \
                class_name::CreateObject)

#define DECLARE_DYNAMIC(class_name) \
public: \
        static CRuntimeClass class##class_name; \
        virtual CRuntimeClass * m_GetRuntimeClass() const;

#define DECLARE_DYNCREATE(class_name) \
        DECLARE_DYNAMIC(class_name) \
        static CObject * PASCAL CreateObject();

class CObject
{
public:
	static CRuntimeClass classCObject;
public:
	CObject () {
		cout << "CObject Constructor \n";
	}
	~CObject () {
		cout << "CObject Destructor \n";
	}
public:
	virtual CRuntimeClass * m_GetRuntimeClass () const
	{
		return &CObject::classCObject;
	}
	BOOL IsKindOf (const CRuntimeClass * anotherClass) const
	{
		CRuntimeClass * thisClass = m_GetRuntimeClass ();

		while (thisClass != nullptr)
		{
			if (thisClass == anotherClass)
			{
				return TRUE;
			}
			else
			{
				thisClass = thisClass->m_baseClass;
			}
		}
		return FALSE;       // walked to the top, no match
	}
public:

};

class CCmdTarget : public CObject
{
	DECLARE_DYNAMIC (CCmdTarget)
public:
	CCmdTarget () {
		cout << "CCmdTarget Constructor \n";
	}
	~CCmdTarget () {
		cout << "CCmdTarget Destructor \n";
	}
};

class CWinThread : public CCmdTarget
{
	DECLARE_DYNAMIC (CWinThread)
public:
	CWinThread () {
		cout << "CWinThread Constructor \n";
	}
	~CWinThread () {
		cout << "CWinThread Destructor \n";
	}
public:
	virtual BOOL m_InitInstance () {
		cout << "CWinThread::InitInstance \n";
		return TRUE;
	}
	virtual int m_Run () {
		cout << "CWinThread::Run \n";
		return 1;
	}
};

class CWnd;

class CWinApp : public CWinThread
{
	DECLARE_DYNAMIC (CWinApp)
public:
	CWinApp * m_currentWinApp;
	CWnd* m_mainWnd;

public:
	CWinApp () {
		cout << "CWinApp Constructor \n";
		this->m_currentWinApp = this;
	}
	~CWinApp () {
		cout << "CWinApp Destructor \n";
	}
public:
	BOOL m_InitApplication () {
		cout << "CWinApp::InitApplication \n";
		return TRUE;
	}
	virtual BOOL m_InitInstance () {
		cout << "CWinApp::InitInstance \n";
		return TRUE;
	}
	virtual int m_Run () {
		cout << "CWinApp::Run \n";
		return CWinThread::m_Run ();
	}
};



class CDocument : public CCmdTarget
{
	DECLARE_DYNAMIC (CDocument)
public:
	CDocument () {
		cout << "CDocument Constructor \n";
	}

	~CDocument () {
		cout << "CDocument Destructor \n";
	}
};


class CWnd : public CCmdTarget
{
	DECLARE_DYNCREATE (CWnd)
public:
	CWnd () {
		cout << "CWnd Constructor \n";
	}
	~CWnd () {
		cout << "CWnd Destructor \n";
	}
public:
	virtual BOOL m_Create ()
	{
		cout << "CWnd::Create \n";
		return TRUE;
	}
	BOOL m_CreateEx ()
	{
		cout << "CWnd::CreateEx \n";
		this->m_PreCreateWindow ();
		return TRUE;
	}
	virtual BOOL m_PreCreateWindow ()
	{
		cout << "CWnd::PreCreateWindow \n";
		return TRUE;
	}
};

class CFrameWnd : public CWnd
{
	DECLARE_DYNCREATE (CFrameWnd)
public:
	CFrameWnd () {
		cout << "CFrameWnd Constructor \n";
	}
	~CFrameWnd () {
		cout << "CFrameWnd Destructor \n";
	}
public:
	BOOL m_Create ()
	{
		cout << "CFrameWnd::Create \n";
		this->CWnd::m_CreateEx ();
		return TRUE;
	}
	virtual BOOL m_PreCreateWindow ()
	{
		cout << "CFrameWnd::PreCreateWindow \n";
		return TRUE;
	}
};

class CView : public CWnd
{
	DECLARE_DYNAMIC (CView)
public:
	CView () {
		cout << "CView Constructor \n";
	}
	~CView () {
		cout << "CView Destructor \n";
	}
};


// global function

CWinApp * AfxGetApp ();

#endif