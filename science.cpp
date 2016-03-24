// science.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "science.h"
#include "NewsInfo.h"
#include "addcollection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cscienceence dialog

CNewsInfo mysci[100];
int scinum;
Cscience::Cscience(CWnd* pParent /*=NULL*/)
	: CDialog(Cscience::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cscience)
	m_editscience = _T("");
	m_stringsci = _T("");
	//}}AFX_DATA_INIT
}


void Cscience::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cscience)
	DDX_Control(pDX, IDC_LISTSCIENCE, m_listscience);
	DDX_Text(pDX, IDC_EDITSCIENCE, m_editscience);
	DDX_Text(pDX, IDC_EDIT1, m_stringsci);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cscience, CDialog)
	//{{AFX_MSG_MAP(Cscience)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTSCIENCE, OnDblclkListscience)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cscience message handlers

BOOL Cscience::OnInitDialog() 
{
	CDialog::OnInitDialog();
		m_listscience.SetTextColor(RGB(100, 0, 100));
	// TODO: Add extra initialization here
	m_listscience.DeleteAllItems();
	m_listscience.InsertColumn(0,"标题",LVCFMT_LEFT,300);         //插入列
    m_listscience.InsertColumn(1,"网站",LVCFMT_LEFT,50);
//	m_listscience.InsertColumn(2,"时间",LVCFMT_LEFT,100);
		CStdioFile mFilesci;
	if(mFilesci.Open("sci.txt",CFile::modeRead)==0)
		return FALSE; 

	int i=0;
	for(;mFilesci.ReadString(mysci[i].title);) //这里改成正序提取了
	{
		
		mFilesci.ReadString(mysci[i].web);
		mFilesci.ReadString(mysci[i].addr);
		//mFilesci.ReadString(mysci[i].time);
		m_listscience.InsertItem(0,"");
		m_listscience.SetItemText(0,0,mysci[i].title);
		m_listscience.SetItemText(0,1,mysci[i].web);
		//m_listscience.SetItemText(0,2,mysci[i].addr);
		i++;
	};
	scinum=i;
	mFilesci.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cscience::OnDblclkListscience(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
		POSITION p=m_listscience.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("没有行被选中!");
	}
	//获取刚选取的位置的下标(从0开始的) 
	int index = m_listscience.GetNextSelectedItem(p);
	CString MA=mysci[scinum-index-1].GetURL();
	int i,pos1,pos2;
	if(mysci[scinum-index-1].web=="sina"){
		i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
		//CString m_editsci;//
		pos1=MA.Find("<!-- publish_helper name='原始正文' ",pos1);//正文标志

		pos1=MA.Find("<p>",pos1);//段开头
		pos2=MA.Find("<!-- publish_helper_end -->",pos1);
		pos2=pos2-1;
		m_editscience=MA.Mid(pos1,pos2-pos1);//提取到内容

		m_editscience.Replace("<p>","\n");//替代或删除掉多余内容
		int p1=0,p2=0;
		for(;p1!=-1 && p2!=-1;)
		{
			p1=0,p2=0;
			p1=m_editscience.Find("<",0);
			p2=m_editscience.Find(">",0);
			m_editscience.Delete(p1,p2-p1+1);
		}
	
	}
	editsave=m_editscience;
	titlesave=mysci[scinum-index-1].title;
    UpdateData(FALSE);
	*pResult = 0;
}

void Cscience::OnButton4() 
{
	// TODO: Add your control notification handler code here

	m_listscience.DeleteAllItems();
		CStdioFile mFilesci;
	CString MA;
	int i,pos1,pos2;
	CStdioFile file;
	CString target,webmark;
	CString addr[10],title[10];
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置	
	if(sinascience==1){
	MA=GetURL("http://www.sina.com.cn/");
	file.Open("sci.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);	
	pos1=MA.Find("<!-- publish_helper name='科技区块'",pos1);//首页要闻部分源代码标志
	for(i=0;i<6;i++)
	{
		
	
		pos1=MA.Find("<li><a href=",pos1);//段开头
		pos1=MA.Find("http://",pos1);//定位到网址开头
		pos2=MA.Find(" target=",pos1);
		pos2=pos2-1;
		addr[i]=MA.Mid(pos1,pos2-pos1);//提取到地址
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</a>",pos1);
		title[i]=MA.Mid(pos1,pos2-pos1);//提取到标题
		if(addr[i].Find("shtml")!=-1)
				file.WriteString(title[i]+"\n"+"sina\n"+addr[i]+"\n");
	}
		file.Close();
	mFilesci.Open("sci.txt",CFile::modeRead);
    i=0;
	for(;mFilesci.ReadString(mysci[i].title);) //这里改成正序提取了
	{
		
		mFilesci.ReadString(mysci[i].web);
		mFilesci.ReadString(mysci[i].addr);
		//mFilesci.ReadString(mysci[i].time);
		m_listscience.InsertItem(0,"");
		m_listscience.SetItemText(0,0,mysci[i].title);
		m_listscience.SetItemText(0,1,mysci[i].web);
		//m_listscience.SetItemText(0,2,mysci[i].addr);
		i++;
	};
	scinum=i;
	mFilesci.Close();
	}
}

void Cscience::OnButton3() 
{
	// TODO: Add your control notification handler code here
	 Caddcollection  addcollect;
	 addcollect.DoModal();
}

void Cscience::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

       CRect   rect;   

       GetClientRect(&rect);   

       CDC   dcMem;   

       dcMem.CreateCompatibleDC(&dc);   

       CBitmap   bmpBackground;   

       bmpBackground.LoadBitmap(IDB_BITMAP2); 

//IDB_BITMAP鏄綘鑷繁鐨勫浘瀵瑰簲鐨処D 

       BITMAP   bitmap;   

       bmpBackground.GetBitmap(&bitmap);   

       CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   

       dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 

       // Do not call CDialog::OnPaint() for painting messages
}



	int a,s;

void Cscience::OnButton1()
{	
	// TODO: Add your control notification handler code here
	for(int z=0;z<19;z++)
	{
		m_listscience.SetItemState(z,0,LVIS_SELECTED|LVIS_FOCUSED);
	}

	UpdateData(true);
//	CStdioFile file;
//	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	char str[100];
	ifstream file("sci.txt");	
//	AfxMessageBox(Str);
	int b=19;
	int P=1;
	int L=1;
	
	for(;;P++)
	{
		file.getline(str,100);
		CString Str;
		Str=str;
		L=Str.Find(m_stringsci);
		if(L!=-1)
		{
			a=scinum-(P+2)/3;
			m_listscience.SetFocus();
			m_listscience.SetItemState(a, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			if(L!=-1)
			{
				s=scinum-(P+2)/3;
				m_listscience.SetFocus();
				m_listscience.SetItemState(s, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			}
		}	
		
		if (P==57){return;}
	}
		
}