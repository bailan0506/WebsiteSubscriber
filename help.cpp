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
	CString str1="1.����л������������ṩ5�����Ķ�����Ŀ������ҳ��ײ��ı�ǩ���а���л���";
	CString str2="2.������£����±�����ʾ������б��С�˫��ѡ�б������»���ʾ���Ҳ��ı����С�";
	CString str3="3.���������ı���������ؼ��ʣ���ȷ�ϣ�������عؼ��ʵı���ᱻѡ�С�";
	CString str4="4��ˢ�£����������½�ˢ�°�ťˢ�±����б�";
	CString str5="5����ӵ��ղأ����������ϲ�������£��������½���ӵ��ղأ������Ի���";
	CString str6="   ���ı�����д��������ۣ�Ȼ�󵥻�OK�����»ᱻ��txt��ʽ����RSS�����ļ��е�RSSCOLLECTION�ļ����£��ļ�����Ϊ���±��⡣������ۻᱻ��������ĺ�";
	CString str7="6.���Ĺ���ͨ����ѡ��ѡ��ѡ������Ŀ���޸�֮�󣬵���OK���ٵ����Ӧ����ˢ�°�ť�����ɷ��ֶ�����Ŀ�ѱ��ı䡣";
	CString str8="7.�ղؼУ��������Ķ��������ղ���Ŀ��";
	m_edit=str1+str+str2+str+str3+str+str4+str+str5+str+str6+str+str7+str+str8+str;

	UpdateData(FALSE);
 







	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
