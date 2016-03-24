// RSSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "RSSDlg.h"
#include "news.h"
#include "management.h"
#include "set.h"
#include "collection.h"
#include "NewsInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSSDlg dialog

CRSSDlg::CRSSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRSSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRSSDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRSSDlg)
	DDX_Control(pDX, IDC_TAB, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRSSDlg, CDialog)
	//{{AFX_MSG_MAP(CRSSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_MANAGEMENT, OnManagement)
//	ON_BN_CLICKED(IDC_COllECTION, OnCOllECTION)
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_BN_CLICKED(IDC_INTRO, OnIntro)
	ON_BN_CLICKED(IDC_collection, Oncollection)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSSDlg message handlers

BOOL CRSSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString MA;
	int i,pos1,pos2;
	CStdioFile file;
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
	CString target,webmark;
	CString addr[10],title[10];
  ////////////////////////////////////////////////////////////////////////////////新浪要闻
	CNewsInfo newssina[8]; 
	MA=GetURL("http://www.sina.com.cn/");
	pos1=MA.Find("<!-- publish_helper name='要闻-新闻",pos1);//首页要闻部分源代码标志
  
	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	for(i=0;i<8;i++)
	{		
		newssina[i].web="sina";
		pos1=MA.Find("<li><a href=",pos1);//段开头
		pos1=MA.Find("http://news.sina.com.cn/",pos1);//定位到网址开头
		pos2=MA.Find(" target=",pos1);
		pos2=pos2-1;
		newssina[i].addr=MA.Mid(pos1,pos2-pos1);//提取到地址
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</a>",pos1);
		newssina[i].title=MA.Mid(pos1,pos2-pos1);//提取到标题
		if(newssina[i].addr.Find("shtml")!=-1)
			if(newssina[i].title.GetLength()>=5)
				file.WriteString(newssina[i].title+"\n"+"sina\n"+newssina[i].addr+"\n");
	}

    file.Close();

/////////////////////////////////////////////////////////////////搜狐要闻
	MA=GetURL("http://news.sohu.com/");
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置	
	CString sohunewsaddr[11],sohunewstitle[11];
	pos1=MA.Find("<DIV class=focus>",pos1);//首页要闻部分源代码标志
  file.Open("news.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
   file.SeekToEnd();
	for(i=0;i<11;i++)
	{
		pos1=MA.Find("<LI><A ",pos1);//段开头
		pos1=MA.Find("http://",pos1);//定位到网址开头
		pos2=MA.Find("target=_blank",pos1);
		pos2=pos2-2;
		sohunewsaddr[i]=MA.Mid(pos1,pos2-pos1);//提取到地址
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</A>",pos1);
		sohunewstitle[i]=MA.Mid(pos1,pos2-pos1);//提取到标题
	       if(	sohunewsaddr[i].Find("shtml")!=-1)
             file.WriteString(sohunewstitle[i]+"\n"+"sohu\n"+sohunewsaddr[i]+"\n");
	}
		file.Close();


//////////////////////////////////////////////





	///////////////////////////////////////////////////////////////渣浪娱乐
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置	
	MA=GetURL("http://www.sina.com.cn/");
	file.Open("play.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	pos1=MA.Find("<!-- publish_helper name='娱乐区块'",pos1);//首页要闻部分源代码标志

	for(i=0;i<8;i++)
	{
		
	
		pos1=MA.Find("<li><a target=",pos1);//段开头
		pos1=MA.Find("http://",pos1);//定位到网址开头
		pos2=MA.Find(">",pos1);
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

//////////////////////////////////////////////////////////////////////////////////渣浪科技

	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置	
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



	//i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
//	CString target,webmark;

	/*MA=GetURL("http://www.sina.com.cn/");
	pos1=MA.Find("<!-- publish_helper name='博主订阅'",pos1);//首页要闻部分源代码标志
	file.Open("blog.txt",CFile::modeCreate|/*CFile::modeNoTruncate|CFile::modeWrite);
	for(i=0;i<6;i++)
	{
		
	
		pos1=MA.Find("<li><a href=",pos1);//段开头
		pos1=MA.Find("http://",pos1);//定位到网址开头
		pos2=MA.Find(">",pos1);
		pos2=pos2-1;
		addr[i]=MA.Mid(pos1,pos2-pos1);//提取到地址
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</a>",pos1);
		title[i]=MA.Mid(pos1,pos2-pos1);//提取到标题
		if(addr[i].Find("html")!=-1)
				file.WriteString(title[i]+"\n"+"sina\n"+addr[i]+"\n");
	}

    file.Close();*/



//sohu  http://news.sohu.com/ 今日时评

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
		file.WriteString(commsohutitle[i]+"\n"+"sohu"+"\n"+commsohuaddr[i]+"\n");
	}
		file.Close();
	//m_szHTML=commsohutitle[0];

//////////////////////////////////////////////

//////////////////////////////////////////////

	//sohu  http://news.sohu.com/ 历史
	MA=GetURL("http://news.sohu.com/");
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
	CString hissohuaddr[8],hissohutitle[8];
	pos1=MA.Find("<span>历史</span>",pos1);//首页要闻部分源代码标志
file.Open("history.txt",CFile::modeCreate|CFile::modeWrite);

	for(i=0;i<8;i++)
	{
		pos1=MA.Find("<li><a href=",pos1);//段开头
		pos1=MA.Find("http://",pos1);//定位到网址开头
		pos2=MA.Find(" target=",pos1);
		pos2=pos2-1;
		hissohuaddr[i]=MA.Mid(pos1,pos2-pos1);//提取到地址
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</",pos1);
		hissohutitle[i]=MA.Mid(pos1,pos2-pos1);//提取到标题
file.WriteString(hissohutitle[i]+"\n"+"sohu\n"+hissohuaddr[i]+"\n");
	}
		file.Close();
	//m_szHTML=hissohutitle[0];


	// Add "About..." menu item to system menu.
	m_tab.InsertItem(0,"要闻");  //添加新闻选项卡 
	//m_tab.InsertItem(1,"评论");  //添加评论选项卡 
	m_tab.InsertItem(1,"科技");  //添加科技选项卡
    //m_tab.InsertItem(3,"体育");
	m_tab.InsertItem(2,"娱乐");
	m_tab.InsertItem(3,"历史");
    m_tab.InsertItem(4,"博客");
	m_news.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB)); 
    m_comments.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB)); 
	m_science.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB)); 
	m_sports.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB));
	m_play.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB));
	m_history.Create(IDD_DIALOG6,GetDlgItem(IDC_TAB));
	m_blog.Create(IDD_DIALOG7,GetDlgItem(IDC_TAB));
	CRect rs; 
	m_tab.GetClientRect(&rs); 
	//调整子对话框在父窗口中的位置 
	rs.top+=1; 
	rs.bottom-=60; 
	rs.left+=1; 
	rs.right-=2; 
	//设置子对话框尺寸并移动到指定位置 
	m_news.MoveWindow(&rs); 
	m_comments.MoveWindow(&rs); 
 
 
	//分别设置隐藏和显示 
	m_news.ShowWindow(true); 
	m_comments.ShowWindow(false);  
 
	//设置默认的选项卡 
	m_tab.SetCurSel(0);

	


	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRSSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRSSDlg::OnPaint() 

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRSSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRSSDlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int CurSel = m_tab.GetCurSel(); 
	 switch(CurSel) 
	{ 
	case 0: 
			m_news.ShowWindow(true); 
			m_comments.ShowWindow(false);
			m_science.ShowWindow(false);
			m_sports.ShowWindow(false);
			m_play.ShowWindow(false);
			m_history.ShowWindow(false);
			m_blog.ShowWindow(false);
	break; 
	case 1: 
			m_news.ShowWindow(false); 
			m_comments.ShowWindow(false);
			m_science.ShowWindow(true);
			m_sports.ShowWindow(false);
			m_play.ShowWindow(false);
			m_history.ShowWindow(false);
			m_blog.ShowWindow(false);
	break; 
	case 2: 
			m_news.ShowWindow(false); 
			m_comments.ShowWindow(false);
			m_science.ShowWindow(false);
			m_sports.ShowWindow(false);
			m_play.ShowWindow(true);
			m_history.ShowWindow(false);
			m_blog.ShowWindow(false);
	break; 
	case 3: 
			m_news.ShowWindow(false); 
			m_comments.ShowWindow(false);
			m_science.ShowWindow(false);
			m_sports.ShowWindow(false);
			m_play.ShowWindow(false);
			m_history.ShowWindow(true);
			m_blog.ShowWindow(false);
	break; 
	case 4: 
			m_news.ShowWindow(false); 
			m_comments.ShowWindow(false);
			m_science.ShowWindow(false);
			m_sports.ShowWindow(false);
			m_play.ShowWindow(false);
			m_history.ShowWindow(false);
			m_blog.ShowWindow(true);
	break; 
	

	default: 
         ; 
     }     
 
	*pResult = 0;
}


void CRSSDlg::OnManagement() 
{
	// TODO: Add your control notification handler code here

	 Dlg1.DoModal();
}

void CRSSDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	 Cset  Dlg2;
	 Dlg2.DoModal();
}

void CRSSDlg::OnCOllECTION() 
{
	// TODO: Add your control notification handler code here
	Ccollection  Dlg3;
	Dlg3.DoModal();
}




void CRSSDlg::OnIntro() 
{
	// TODO: Add your control notification handler code here
	Dlg4.DoModal();
}

void CRSSDlg::Oncollection() 
{
	// TODO: Add your control notification handler code here
		Dlg5.DoModal();
}
