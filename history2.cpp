// history2.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "history2.h"
#include "NewsInfo.h"
#include "addcollection.h"
#include "RSSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Chistory dialog

CNewsInfo myhistory[100];
int historynum;
Chistory::Chistory(CWnd* pParent /*=NULL*/)
	: CDialog(Chistory::IDD, pParent)
{
	//{{AFX_DATA_INIT(Chistory)
	m_edithistory = _T("");
	m_stringhistory = _T("");
	//}}AFX_DATA_INIT
}


void Chistory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Chistory)
	DDX_Control(pDX, IDC_LISTHISTORY, m_listhistory);
	DDX_Text(pDX, IDC_EDIT4, m_edithistory);
	DDX_Text(pDX, IDC_EDIT2, m_stringhistory);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Chistory, CDialog)
	//{{AFX_MSG_MAP(Chistory)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTHISTORY, OnDblclkListhistory)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Chistory message handlers

BOOL Chistory::OnInitDialog() 
{
	CDialog::OnInitDialog();
		m_listhistory.SetTextColor(RGB(100, 0, 100));
	// TODO: Add extra initialization here
	m_listhistory.DeleteAllItems();
	m_listhistory.InsertColumn(0,"标题",LVCFMT_LEFT,300);         //插入列
    m_listhistory.InsertColumn(1,"网站",LVCFMT_LEFT,50);
	//m_listhistory.InsertColumn(2,"时间",LVCFMT_LEFT,100);
		CStdioFile mFilehistory;
	if(mFilehistory.Open("history.txt",CFile::modeRead)==0)
		return FALSE; 

	int i=0;
	for(;mFilehistory.ReadString(myhistory[i].title);) //这里改成正序提取了
	{
		
		mFilehistory.ReadString(myhistory[i].web);
		mFilehistory.ReadString(myhistory[i].addr);
		//mFilehistory.ReadString(myhistory[i].time);
		m_listhistory.InsertItem(0,"");
		m_listhistory.SetItemText(0,0,myhistory[i].title);
		m_listhistory.SetItemText(0,1,myhistory[i].web);
		//m_listhistory.SetItemText(0,2,myhistory[i].addr);
		i++;
	};
	historynum=i;
	mFilehistory.Close();






	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Chistory::OnDblclkListhistory(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POSITION p=m_listhistory.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("没有行被选中!");
	}
	//获取刚选取的位置的下标(从0开始的) 
	int index = m_listhistory.GetNextSelectedItem(p);
	CString MA=myhistory[historynum-index-1].GetURL();
	int i,pos1,pos2;
	i=0; pos1=0; pos2=0;//pos1前位置 pos2后位置
	
	pos1=MA.Find("<!-- 正文 -->",pos1);//正文标志
	pos1=MA.Find("jQuery);",pos1);//正文标志
	pos1=pos1+8;

	pos2=MA.Find("<div class=\"pages\">",pos1);
	pos2=pos2-1;
	m_edithistory=MA.Mid(pos1,pos2-pos1);//提取到内容

	m_edithistory.Replace("<div class=\"text clear\" id=\"contentText\">","\n");//替代或删除掉多余内容
	int p1=0,p2=0;
	for(;p1!=-1 && p2!=-1;)
	{
		p1=0,p2=0;
		p1=m_edithistory.Find("<",0);
		p2=m_edithistory.Find(">",0);
		m_edithistory.Delete(p1,p2-p1+1);
	}
	editsave=m_edithistory;
	titlesave=myhistory[historynum-index-1].title;
	
	
	UpdateData(FALSE);




	*pResult = 0;
}

void Chistory::OnButton1() 
{
	// TODO: Add your control notification handler code here
	 Caddcollection  addcollect;
	 addcollect.DoModal();
}

void Chistory::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString MA;
	int i,pos1,pos2;
	CStdioFile file;
	CString target,webmark;
	CStdioFile mFilehistory;
    m_listhistory.DeleteAllItems();

	if(sohuhistory==1){
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
	mFilehistory.Open("history.txt",CFile::modeRead);
	i=0;
	for(;mFilehistory.ReadString(myhistory[i].title);) //这里改成正序提取了
	{
		
		mFilehistory.ReadString(myhistory[i].web);
		mFilehistory.ReadString(myhistory[i].addr);
		//mFilehistory.ReadString(myhistory[i].time);
		m_listhistory.InsertItem(0,"");
		m_listhistory.SetItemText(0,0,myhistory[i].title);
		m_listhistory.SetItemText(0,1,myhistory[i].web);
		//m_listhistory.SetItemText(0,2,myhistory[i].addr);
		i++;
	};
	historynum=i;
	mFilehistory.Close();
	}	

}

void Chistory::OnPaint() 
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

 
int g,h;

void Chistory::OnButton3() 
{	
	// TODO: Add your control notification handler code here
	for(int z=0;z<19;z++)
	{
		m_listhistory.SetItemState(z,0,LVIS_SELECTED|LVIS_FOCUSED);
	}

	UpdateData(true);
//	CStdioFile file;
//	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	char str[100];
	ifstream file("history.txt");	
//	AfxMessageBox(Str);
	int b=19;
	int P=1;
	int L=1;
	
	for(;;P++)
	{
		file.getline(str,100);
		CString Str;
		Str=str;
		L=Str.Find(m_stringhistory);
		if(L!=-1)
		{
			g=historynum-(P+2)/3;
			m_listhistory.SetFocus();
			m_listhistory.SetItemState(g, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			if(L!=-1)
			{
				h=historynum-(P+2)/3;
				m_listhistory.SetFocus();
				m_listhistory.SetItemState(h, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			}
		}	
		
		if (P==57){return;}
	}
		
}

