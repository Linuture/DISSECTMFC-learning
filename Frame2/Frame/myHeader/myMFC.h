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
	virtual BOOL m_InitInstance ();
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
};

inline BOOL 
CMyWinApp::m_InitInstance ()
{
	cout << "CMyWinApp::InitInstance \n";
	m_mainWnd = new CMyFrameWnd;
	return TRUE;
}

#endif