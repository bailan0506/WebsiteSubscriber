// management.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "management.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cmanagement dialog


Cmanagement::Cmanagement(CWnd* pParent /*=NULL*/)
	: CDialog(Cmanagement::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cmanagement)
	m_sinanews = TRUE;
	m_sohunews = TRUE;
	m_sinascience = TRUE;
	m_sinaplay = TRUE;
	m_sohuhistory = TRUE;
	m_sohucomments = TRUE;
	//}}AFX_DATA_INIT
}


void Cmanagement::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cmanagement)
	DDX_Check(pDX, IDC_CHECK1, m_sinanews);
	DDX_Check(pDX, IDC_CHECK2, m_sohunews);
	DDX_Check(pDX, IDC_CHECK3, m_sinascience);
	DDX_Check(pDX, IDC_CHECK4, m_sinaplay);
	DDX_Check(pDX, IDC_CHECK5, m_sohuhistory);
	DDX_Check(pDX, IDC_CHECK6, m_sohucomments);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cmanagement, CDialog)
	//{{AFX_MSG_MAP(Cmanagement)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cmanagement message handlers

void Cmanagement::OnOK() 
{
	// TODO: Add extra validation here
	
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	int state = pBtn->GetCheck();
	sinanews=state;
	pBtn->SetCheck(state);
 	pBtn=(CButton*)GetDlgItem(IDC_CHECK2);
	state = pBtn->GetCheck();
 	pBtn->SetCheck(state);
	sohunews=state;
	pBtn=(CButton*)GetDlgItem(IDC_CHECK3);
	state = pBtn->GetCheck();
	pBtn->SetCheck(state);
	sinascience=state;
	pBtn=(CButton*)GetDlgItem(IDC_CHECK4);
	state = pBtn->GetCheck();
	pBtn->SetCheck(state);
	sinaplay=state;
	pBtn=(CButton*)GetDlgItem(IDC_CHECK5);
	state = pBtn->GetCheck();
	pBtn->SetCheck(state);
	sohuhistory=state;
	pBtn=(CButton*)GetDlgItem(IDC_CHECK6);
	state = pBtn->GetCheck();
	pBtn->SetCheck(state);
	sohucomments=state;
	CDialog::OnOK();
}
