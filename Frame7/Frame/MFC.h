#pragma once
#ifndef _MFC_
#define _MFC_

#define TRUE 1
#define FALSE 0

typedef char * LPSTR;
typedef const char * LPCSTR;

typedef unsigned long  DWORD;
typedef int            BOOL;
typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef int            INT;
typedef unsigned int   UINT;
typedef long           LONG;

#define WM_COMMAND             0x0111
#define CObjectid              0xffff
#define   CCmdTargetid         1
#define     CWinThreadid       11
#define       CWinAppid        111
#define         CMyWinAppid    1111
#define     CWndid             12
#define       CFrameWndid      121
#define         CMyFrameWndid  1211
#define       CViewid          122
#define         CMyViewid      1221
#define     CDocumentid        13
#define       CMyDocid         131

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
// Window message map handling

struct AFX_MSGMAP_ENTRY;       // declared below after CWnd

struct AFX_MSGMAP
{
	AFX_MSGMAP * m_baseMessageMap;
	AFX_MSGMAP_ENTRY * m_entries;
};

#define DECLARE_MESSAGE_MAP() \
        static AFX_MSGMAP_ENTRY m_messageEntries[]; \
        static AFX_MSGMAP m_messageMap; \
        virtual AFX_MSGMAP * m_GetMessageMap() const;

#define BEGIN_MESSAGE_MAP(theClass, baseClass) \
        AFX_MSGMAP * theClass::m_GetMessageMap() const \
                { return &(theClass::m_messageMap); } \
        AFX_MSGMAP theClass::m_messageMap = \
        { &(baseClass::m_messageMap), \
                (AFX_MSGMAP_ENTRY *) &(theClass::m_messageEntries) }; \
        AFX_MSGMAP_ENTRY theClass::m_messageEntries[] = \
        {

#define END_MESSAGE_MAP() \
        { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
        };

// Message map signature values and macros in separate header
#include "afxmsg_.h"

class CObject
{
public:
	CObject () {
		cout << "CObject Constructor \n";
	}
	~CObject () {
		cout << "CObject Destructor \n";
	}
};

class CCmdTarget : public CObject
{
public:
	CCmdTarget () {
		cout << "CCmdTarget Constructor \n";
	}
	~CCmdTarget () {
		cout << "CCmdTarget Destructor \n";
	}
public:
	DECLARE_MESSAGE_MAP ( )       // base class - no {{ }} macros
};

typedef void (CCmdTarget::*AFX_PMSG)(void);

struct AFX_MSGMAP_ENTRY  // MFC 4.0
{
	UINT nMessage; // windows message
	UINT nCode;    // control code or WM_NOTIFY code
	UINT nID;      // control ID (or 0 for windows messages)
	UINT nLastID;  // used for entries specifying a range of control id's
	UINT nSig;     // signature type (action) or pointer to message #
	AFX_PMSG pfn;  // routine to call (or special value)
};

class CWinThread : public CCmdTarget
{
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
public:
	CWinApp * m_currentWinApp;
	CWnd * m_mainWnd;

public:
	CWinApp () {
		cout << "CWinApp Constructor \n";
		m_currentWinApp = this;
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
public:
	DECLARE_MESSAGE_MAP ( )
};

typedef void (CWnd::*AFX_PMSGW)(void);
// like 'AFX_PMSG' but for CWnd derived classes only

class CDocument : public CCmdTarget
{
public:
	CDocument () {
		cout << "CDocument Constructor \n";
	}

	~CDocument () {
		cout << "CDocument Destructor \n";
	}
public:
	DECLARE_MESSAGE_MAP ( )
};


class CWnd : public CCmdTarget
{
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
public:
	DECLARE_MESSAGE_MAP ( )
};

class CFrameWnd : public CWnd
{
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
public:
	DECLARE_MESSAGE_MAP ( )
};

class CView : public CWnd
{
public:
	CView () {
		cout << "CView Constructor \n";
	}
	~CView () {
		cout << "CView Destructor \n";
	}
public:
	DECLARE_MESSAGE_MAP ( )
};


inline AFX_MSGMAP * 
CCmdTarget::m_GetMessageMap ( ) const  // JJHOU: in MFC 40 cmdtarg.cpp
{
	return &CCmdTarget::m_messageMap;
}

// global function

CWinApp * AfxGetApp ();

#endif