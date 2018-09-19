#include "pch.h"
#include "myHeader/myMFC.h"

BEGIN_MESSAGE_MAP (CMyWinApp, CWinApp)
	ON_COMMAND (CMyWinAppid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CMyFrameWnd, CFrameWnd)
	ON_COMMAND (CMyFrameWndid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CMyDoc, CDocument)
	ON_COMMAND (CMyDocid, 0)
END_MESSAGE_MAP ( )

BEGIN_MESSAGE_MAP (CMyView, CView)
	ON_COMMAND (CMyViewid, 0)
END_MESSAGE_MAP ( )