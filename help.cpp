// help.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "help.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Chelp dialog


Chelp::Chelp(CWnd* pParent /*=NULL*/)
	: CDialog(Chelp::IDD, pParent)
{
	//{{AFX_DATA_INIT(Chelp)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void Chelp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Chelp)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Chelp, CDialog)
	//{{AFX_MSG_MAP(Chelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Chelp message handlers

BOOL Chelp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str="\r\n";
	CString str1="1.版块切换：本订阅器提供5个版块的订阅项目，单击页面底部的标签进行版块切换。";
	CString str2="2.浏览文章：文章标题显示在左侧列表中。双击选中标题文章会显示在右侧文本框中。";
	CString str3="3.搜索：在文本框中输入关键词，点确认，含有相关关键词的标题会被选中。";
	CString str4="4，刷新：单击击右下角刷新按钮刷新标题列表。";
	CString str5="5，添加到收藏：如果遇到你喜欢的文章，单击右下角添加到收藏，弹出对话框";
	CString str6="   在文本框中写下你的评论，然后单击OK，文章会被以txt格式存在RSS程序文件夹的RSSCOLLECTION文件夹下，文件名称为文章标题。你的评论会被添加在正文后。";
	CString str7="6.订阅管理：通过勾选复选框选择订阅项目。修改之后，单击OK，再点击相应版块的刷新按钮，即可发现订阅项目已被改变。";
	CString str8="7.收藏夹：单击可阅读所有已收藏项目。";
	m_edit=str1+str+str2+str+str3+str+str4+str+str5+str+str6+str+str7+str+str8+str;

	UpdateData(FALSE);
 







	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
