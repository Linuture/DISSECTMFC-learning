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
	DECLARE_DYNAMIC (CMyFrameWnd)
public:
	CMyFrameWnd () {
		cout << "CMyFrameWnd Constructor \n";
		this->CFrameWnd::m_Create ();
	}
	~CMyFrameWnd () {
		cout << "CMyFrameWnd Destructor \n";
	}
};

class CMyDoc : public CDocument
{
	DECLARE_DYNAMIC (CMyDoc)
public:
	CMyDoc () {
	}
	~CMyDoc () {
	}
};

class CMyView : public CView
{
	DECLARE_DYNAMIC (CMyView)
public:
	CMyView () {
	}
	~CMyView () {
	}
};

//--------------------------------------
inline BOOL 
CMyWinApp::m_InitInstance ()
{
	cout << "CMyWinApp::InitInstance \n";
	m_mainWnd = new CMyFrameWnd;
	return TRUE;
}

#endif