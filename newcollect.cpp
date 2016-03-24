// newcollect.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "newcollect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cnewcollect dialog


Cnewcollect::Cnewcollect(CWnd* pParent /*=NULL*/)
	: CDialog(Cnewcollect::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cnewcollect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cnewcollect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cnewcollect)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cnewcollect, CDialog)
	//{{AFX_MSG_MAP(Cnewcollect)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cnewcollect message handlers
