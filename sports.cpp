// sports.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "sports.h"
#include "NewsInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Csports dialog


Csports::Csports(CWnd* pParent /*=NULL*/)
	: CDialog(Csports::IDD, pParent)
{
	//{{AFX_DATA_INIT(Csports)
	m_editsports = _T("");
	//}}AFX_DATA_INIT
}


void Csports::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Csports)
	DDX_Control(pDX, IDC_LISTSPORTS, m_listsports);
	DDX_Text(pDX, IDC_EDITSPORTS, m_editsports);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Csports, CDialog)
	//{{AFX_MSG_MAP(Csports)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTSPORTS, OnDblclkListsports)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Csports message handlers
CNewsInfo mysports[2000];
int sportsnum;
BOOL Csports::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_listsports.SetTextColor(RGB(100, 0, 100));
	m_listsports.DeleteAllItems();
	m_listsports.InsertColumn(0,"标题",LVCFMT_LEFT,300);         //插入列
    m_listsports.InsertColumn(1,"网站",LVCFMT_LEFT,50);
	m_listsports.InsertColumn(2,"时间",LVCFMT_LEFT,100);
		// TODO: Add extra initialization here
	CStdioFile mFilesports;
	if(mFilesports.Open("sport.txt",CFile::modeRead)==0)
		return FALSE; 

	int i=0;
	for(;mFilesports.ReadString(mysports[i].title);) //这里改成正序提取了
	{
		
		mFilesports.ReadString(mysports[i].web);
		mFilesports.ReadString(mysports[i].addr);
		//mFilesports.ReadString(mysports[i].time);
		m_listsports.InsertItem(0,"");
		m_listsports.SetItemText(0,0,mysports[i].title);
		m_listsports.SetItemText(0,1,mysports[i].web);
		//m_listsports.SetItemText(0,2,mysports[i].addr);
		i++;
	};
	sportsnum=i;
	mFilesports.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Csports::OnDblclkListsports(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POSITION p=m_listsports.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("没有行被选中!");
	}
	//获取刚选取的位置的下标(从0开始的) 
	int index = m_listsports.GetNextSelectedItem(p);
	m_editsports=mysports[sportsnum-index-1].GetURL();
	
    UpdateData(FALSE);
	
	*pResult = 0;
}
