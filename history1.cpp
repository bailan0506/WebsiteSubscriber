// history1.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "history1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Chistory dialog


Chistory::Chistory(CWnd* pParent /*=NULL*/)
	: CDialog(Chistory::IDD, pParent)
{
	//{{AFX_DATA_INIT(Chistory)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Chistory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Chistory)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Chistory, CDialog)
	//{{AFX_MSG_MAP(Chistory)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Chistory message handlers
