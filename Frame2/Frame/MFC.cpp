#include "pch.h"
#include "MFC.h"
#include "myHeader/myMFC.h"  // it should be mfc.h, but for CMyWinApp definition, so...

extern CMyWinApp theApp;

CWinApp * AfxGetApp ()
{
	return theApp.m_currentWinApp;
}