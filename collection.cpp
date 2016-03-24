// collection.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "collection.h"
#include "Shlwapi.h"
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ccollection dialog


Ccollection::Ccollection(CWnd* pParent /*=NULL*/)
	: CDialog(Ccollection::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ccollection)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void Ccollection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ccollection)
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ccollection, CDialog)
	//{{AFX_MSG_MAP(Ccollection)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ccollection message handlers
int article;
 CString strPath[200];
BOOL Ccollection::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		m_list.SetTextColor(RGB(100, 0, 100));
	
	m_list.DeleteAllItems();
	m_list.InsertColumn(0,"标题",LVCFMT_LEFT,200);         //插入列
  
	//m_listnews.InsertColumn(2,"网址",LVCFMT_LEFT,50);
    int i=0;
    CFileFind ff;
    char* path1=new char [10000];
	GetCurrentDirectory(20000,path1);
    path=path1;

    BOOL ret = ff.FindFile(path+"\\RSSCOLLECTION\\*.txt");
    while(ret)
    {
        ret = ff.FindNextFile();
        strPath[i] = ff.GetFileName();
		m_list.InsertItem(0,"");
		m_list.SetItemText(0,0,strPath[i]);
		i++;
    }
    ff.Close();

	article=i;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ccollection::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POSITION p=m_list.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("没有行被选中!");
	}
	//获取刚选取的位置的下标(从0开始的) 
	int index = m_list.GetNextSelectedItem(p);	
	CFile mFile;
	CString openpath=_T(path+"\\RSSCOLLECTION\\"+strPath[article-index-1]);
	mFile.Open(openpath,CFile::modeRead);
	char *edit;
	int n=mFile.GetLength();
	edit=new char[n];
	mFile.Read(edit,n);
	m_edit=edit;
	UpdateData(FALSE);
	*pResult = 0;
}
