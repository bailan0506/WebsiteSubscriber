// blog.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "blog.h"
#include "NewsInfo.h"
#include "addcollection.h"
#include "RSSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cblog dialog
    

Cblog::Cblog(CWnd* pParent /*=NULL*/)
	: CDialog(Cblog::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cblog)
	m_editblog = _T("");
	m_stringblog = _T("");
	//}}AFX_DATA_INIT
}


void Cblog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cblog)
	DDX_Control(pDX, IDC_LISTBLOG, m_listblog);
	DDX_Text(pDX, IDC_EDIT2, m_editblog);
	DDX_Text(pDX, IDC_EDIT1, m_stringblog);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cblog, CDialog)
	//{{AFX_MSG_MAP(Cblog)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTBLOG, OnDblclkListblog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cblog message handlers
CNewsInfo myblog[100];
int blognum;
BOOL Cblog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_listblog.SetTextColor(RGB(100, 0, 100));
	// TODO: Add extra initialization here
	m_listblog.DeleteAllItems();
	m_listblog.InsertColumn(0,"标题",LVCFMT_LEFT,300);         //插入列
    m_listblog.InsertColumn(1,"网站",LVCFMT_LEFT,50);
//	m_listblog.InsertColumn(2,"时间",LVCFMT_LEFT,100);
	CStdioFile mFileblog;
	if(mFileblog.Open("blog.txt",CFile::modeRead)==0)
		return FALSE; 

	int i=0;
	for(;mFileblog.ReadString(myblog[i].title);) //这里改成正序提取了
	{
		
		mFileblog.ReadString(myblog[i].web);
		mFileblog.ReadString(myblog[i].addr);
		//mFileblog.ReadString(myblog[i].time);
		m_listblog.InsertItem(0,"");
		m_listblog.SetItemText(0,0,myblog[i].title);
		m_listblog.SetItemText(0,1,myblog[i].web);
		//m_listblog.SetItemText(0,2,myblog[i].addr);
		i++;
	};
	blognum=i;
	mFileblog.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cblog::OnDblclkListblog(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
		POSITION p=m_listblog.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("没有行被选中!");
	}
	//获取刚选取的位置的下标(从0开始的) 
	int index = m_listblog.GetNextSelectedItem(p);
	CString MA=myblog[blognum-index-1].GetURL();
	m_editblog=MA;
	int i,pos1,pos2;
	if(myblog[blognum-index-1].web=="sohu"){
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
	pos1=MA.Find("日志正文",pos1);//正文标志

	pos2=MA.Find("<script type=",pos1);
	pos2=pos2-1;
	m_editblog=MA.Mid(pos1,pos2-pos1+1);//提取到内容

	m_editblog.Replace("<div class=\"text clear\" id=\"contentText\">","\n");//替代或删除掉多余内容
	int p1=0,p2=0;
	for(;p1!=-1 && p2!=-1;)
	{
		p1=0,p2=0;
		p1=m_editblog.Find("<",0);
		p2=m_editblog.Find(">",0);
		m_editblog.Delete(p1,p2-p1+1);
	}
	for(;p1!=-1 && p2!=-1;)
	{
		p1=0,p2=0;
		p1=m_editblog.Find("&",0);
		p2=m_editblog.Find(";",0);
		m_editblog.Delete(p1,p2-p1+1);
	}
	}
	editsave=m_editblog;
	titlesave=myblog[blognum-index-1].title;
    UpdateData(FALSE);
	*pResult = 0;
}

void Cblog::OnButton1() 
{
	// TODO: Add your control notification handler code here
		 Caddcollection  addcollect;
	 addcollect.DoModal();
}

void Cblog::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CStdioFile mFileblog;
	CString MA;
	int i,pos1,pos2;
	CStdioFile file;
	i=0; pos1=0; pos2=0;
		if(sohucomments==1){
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
	MA=GetURL("http://news.sohu.com/");
	CString commsohuaddr[4],commsohutitle[4];
	pos1=MA.Find("<h2><span>今日时评</span></h2>",pos1);//首页要闻部分源代码标志
   file.Open("blog.txt",CFile::modeCreate/*|CFile::modeNoTruncate*/|CFile::modeWrite);

	for(i=0;i<8;i++)
	{
		pos1=MA.Find("<LI><A href=",pos1);//段开头
		pos1=MA.Find("http://",pos1);//定位到网址开头
		pos2=MA.Find(" target=",pos1);
		pos2=pos2-1;
		commsohuaddr[i]=MA.Mid(pos1,pos2-pos1);//提取到地址
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</A></LI>",pos1);
		commsohutitle[i]=MA.Mid(pos1,pos2-pos1);//提取到标题
        if(commsohuaddr[i].Find("shtml")==-1)
		file.WriteString(commsohutitle[i]+"\n"+"sohu时评\n"+commsohuaddr[i]+"\n");
	}
	file.Close();
	
	mFileblog.Open("blog.txt",CFile::modeRead);

   i=0;
	for(;mFileblog.ReadString(myblog[i].title);) //这里改成正序提取了
	{
		
		mFileblog.ReadString(myblog[i].web);
		mFileblog.ReadString(myblog[i].addr);
		//mFileblog.ReadString(myblog[i].time);
		m_listblog.InsertItem(0,"");
		m_listblog.SetItemText(0,0,myblog[i].title);
		m_listblog.SetItemText(0,1,myblog[i].web);
		//m_listblog.SetItemText(0,2,myblog[i].addr);
		i++;
	};
	blognum=i;
	mFileblog.Close();
		}
}




void Cblog::OnPaint() 
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



int j,k;

void Cblog::OnButton3()  
{	
	// TODO: Add your control notification handler code here
	for(int z=0;z<19;z++)
	{
		m_listblog.SetItemState(z,0,LVIS_SELECTED|LVIS_FOCUSED);
	}

	UpdateData(true);
//	CStdioFile file;
//	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	char str[100];
	ifstream file("blog.txt");	
//	AfxMessageBox(Str);
	int b=19;
	int P=1;
	int L=1;
	
	for(;;P++)
	{
		file.getline(str,100);
		CString Str;
		Str=str;
		L=Str.Find(m_stringblog);
		if(L!=-1)
		{
			j=blognum-(P+2)/3;
			m_listblog.SetFocus();
			m_listblog.SetItemState(j, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			if(L!=-1)
			{
				k=blognum-(P+2)/3;
				m_listblog.SetFocus();
				m_listblog.SetItemState(k, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			}
		}	
		
		if (P==57){return;}
	}
		
}

