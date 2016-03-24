// commets.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "commets.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ccommets dialog


Ccommets::Ccommets(CWnd* pParent /*=NULL*/)
	: CDialog(Ccommets::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ccommets)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Ccommets::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ccommets)
	DDX_Control(pDX, IDC_LISTCOMMENTS, m_listcomments);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ccommets, CDialog)
	//{{AFX_MSG_MAP(Ccommets)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ccommets message handlers

BOOL Ccommets::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_listcomments.SetTextColor(RGB(100, 0, 100));
	// TODO: Add extra initialization here
	m_listcomments.DeleteAllItems();
	m_listcomments.InsertColumn(0,"标题",LVCFMT_LEFT,300);         //插入列
    m_listcomments.InsertColumn(1,"网站",LVCFMT_LEFT,50);
	m_listcomments.InsertColumn(2,"时间",LVCFMT_LEFT,100);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
