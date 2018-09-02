#pragma once
#ifndef _MFC_
#define _MFC_

#define BOOL int
#define TRUE 1
#define FALSE 0

#include <iostream>
using namespace std;

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
	CWnd* m_mainWnd;

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
};



class CDocument : public CCmdTarget
{
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