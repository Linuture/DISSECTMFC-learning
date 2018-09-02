#include "pch.h"
#include "MFC.h"  // it should be mfc.h, but for CMyWinApp definition, so...
#include "myHeader/myMFC.h"

extern CMyWinApp theApp;

CWinApp * AfxGetApp ()
{
	return theApp.m_currentWinApp;
}