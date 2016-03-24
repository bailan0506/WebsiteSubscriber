// addcollection.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "addcollection.h"
#include "Shlwapi.h"
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Caddcollection dialog


Caddcollection::Caddcollection(CWnd* pParent /*=NULL*/)
	: CDialog(Caddcollection::IDD, pParent)
{
	//{{AFX_DATA_INIT(Caddcollection)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void Caddcollection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Caddcollection)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Caddcollection, CDialog)
	//{{AFX_MSG_MAP(Caddcollection)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Caddcollection message handlers

void Caddcollection::OnOK() 
{
	// TODO: Add extra validation here
		CDialog::OnOK();
	UpdateData(TRUE);
	editsave=editsave+"\n"+"ÎÒµÄÆÀÂÛ£º"+"\n"+m_edit;
//	CString m_strFolderPath=_T("C:\\Users\\Public\\RSSCOLLECTION");
  char* path1=new char [10000];
	GetCurrentDirectory(20000,path1);
    path=path1;

	CString	m_strFolderPath=_T(path+"\\RSSCOLLECTION");
	if(!PathIsDirectory(m_strFolderPath))		
		CreateDirectory(m_strFolderPath,NULL);
	CFile mFile(_T(path+"\\RSSCOLLECTION\\"+titlesave+".txt"), CFile::modeWrite|CFile::modeCreate);
	mFile.Write(editsave,editsave.GetLength());
	mFile.Flush();
	mFile.Close();
}
