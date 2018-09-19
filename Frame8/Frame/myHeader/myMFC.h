#pragma once
#ifndef _MYMFC_
#define _MYMFC_

#include "MFC.h"

class CMyFrameWnd;

class CMyWinApp : public CWinApp
{
public:
	CMyWinApp () {
		cout << "CMyWinApp Constructor \n";
	}
	~CMyWinApp () {
		cout << "CMyWinApp Destructor \n";
	}
public:
	virtual BOOL m_InitInstance ( );
public:
	DECLARE_MESSAGE_MAP ( )
};

class CMyFrameWnd : public CFrameWnd
{
public:
	CMyFrameWnd () {
		cout << "CMyFrameWnd Constructor \n";
		this->CFrameWnd::m_Create ();
	}
	~CMyFrameWnd () {
		cout << "CMyFrameWnd Destructor \n";
	}
public:
	DECLARE_MESSAGE_MAP ( )
};

class CMyDoc : public CDocument
{
public:
	CMyDoc ( ) {
		cout << "CMyDoc Constructor \n";
	}
	~CMyDoc ( ) {
		cout << "CMyDoc Destructor \n";
	}
public:
	DECLARE_MESSAGE_MAP ( )
};

class CMyView : public CView
{
public:
	CMyView ( ) {
		cout << "CMyView Constructor \n";
	}
	~CMyView ( ) {
		cout << "CMyView Destructor \n";
	}
public:
	DECLARE_MESSAGE_MAP ( )
};

inline BOOL 
CMyWinApp::m_InitInstance ( )
{
	cout << "CMyWinApp::InitInstance \n";
	m_mainWnd = new CMyFrameWnd;
	return TRUE;
}

#endif