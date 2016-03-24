// news.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "RSSDlg.h"
#include "news.h"
#include "NewsInfo.h"
#include "addcollection.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cnews dialog


Cnews::Cnews(CWnd* pParent /*=NULL*/)
	: CDialog(Cnews::IDD, pParent)
{
   

	//{{AFX_DATA_INIT(Cnews)
	m_editnews = _T("");
	m_stringnews = _T("");
	//}}AFX_DATA_INIT
}


void Cnews::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cnews)
	DDX_Control(pDX, IDC_LISTNEWS, m_listnews);
	DDX_Text(pDX, IDC_EDIT1, m_editnews);
	DDX_Text(pDX, IDC_EDIT2, m_stringnews);
	//}}AFX_DATA_MAP
}




BEGIN_MESSAGE_MAP(Cnews, CDialog)
	//{{AFX_MSG_MAP(Cnews)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTNEWS, OnDblclkListnews)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Cnews message handlers
CNewsInfo mynews[2000];
BOOL Cnews::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_listnews.SetTextColor(RGB(100, 0, 100));
	// TODO: Add extra initialization here
	m_listnews.DeleteAllItems();
	m_listnews.InsertColumn(0,"����",LVCFMT_LEFT,150);         //������
    m_listnews.InsertColumn(1,"��Դ",LVCFMT_LEFT,50);
	//m_listnews.InsertColumn(2,"��ַ",LVCFMT_LEFT,50);
	CStdioFile mFilenews;
	if(mFilenews.Open("news.txt",CFile::modeRead)==0)
		return FALSE; 

	int i=0;
	for(;mFilenews.ReadString(mynews[i].title);) //����ĳ�������ȡ��
	{
		
		mFilenews.ReadString(mynews[i].web);
		mFilenews.ReadString(mynews[i].addr);
		//mFilenews.ReadString(mynews[i].time);
		m_listnews.InsertItem(0,"");
		m_listnews.SetItemText(0,0,mynews[i].title);
		m_listnews.SetItemText(0,1,mynews[i].web);
		//m_listnews.SetItemText(0,2,mynews[i].addr);
		i++;
	};
	newsnum=i;
	mFilenews.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cnews::OnDblclkListnews(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POSITION p=m_listnews.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("û���б�ѡ��!");
	}
	//��ȡ��ѡȡ��λ�õ��±�(��0��ʼ��) 
	int index = m_listnews.GetNextSelectedItem(p);
	CString MA=mynews[newsnum-index-1].GetURL();
	int i,pos1,pos2;
	if(mynews[newsnum-index-1].web=="sina"){
		i=0; pos1=0; pos2=0;//pos1ǰλ�� pos2��λ��
		//CString m_editnews;//
		pos1=MA.Find("<!-- publish_helper name='ԭʼ����' ",pos1);//���ı�־

		pos1=MA.Find("<p>",pos1);//�ο�ͷ
		pos2=MA.Find("<!-- publish_helper_end -->",pos1);
		pos2=pos2-1;
		m_editnews=MA.Mid(pos1,pos2-pos1);//��ȡ������

		m_editnews.Replace("<p>","\n");//�����ɾ������������
		int p1=0,p2=0;
		for(;p1!=-1 && p2!=-1;)
		{
			p1=0,p2=0;
			p1=m_editnews.Find("<",0);
			p2=m_editnews.Find(">",0);
			m_editnews.Delete(p1,p2-p1+1);
		}
	
	}
    if(mynews[newsnum-index-1].web=="sohu"){
	i=0; pos1=0; pos2=0;//pos1ǰλ�� pos2��λ��
	//CString m_editnews;//
	pos1=MA.Find("<!-- ���� -->",pos1);//���ı�־

	pos2=MA.Find("<script type=",pos1);
	pos2=pos2-1;
	m_editnews=MA.Mid(pos1,pos2-pos1+1);//��ȡ������

	m_editnews.Replace("<div class=\"text clear\" id=\"contentText\">","\r\n");//�����ɾ������������
	
	int p1=0,p2=0;
	for(;p1!=-1 && p2!=-1;)
	{
		p1=0,p2=0;
		p1=m_editnews.Find("<",0);
		p2=m_editnews.Find(">",0);
		m_editnews.Delete(p1,p2-p1+1);
	}
		
	}
	editsave=m_editnews;
	titlesave=mynews[newsnum-index-1].title;
    UpdateData(FALSE);
	*pResult = 0;
}



void Cnews::OnButton1() 
{
	// TODO: Add your control notification handler code here
	 Caddcollection  addcollect;
	 addcollect.DoModal();
}

void Cnews::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString MA;
	int i,pos1,pos2;
	CStdioFile file;
	i=0; pos1=0; pos2=0;//pos1ǰλ�� pos2��λ��
	CString target,webmark;
	CString addr[10],title[10];
	m_listnews.DeleteAllItems();
	CStdioFile mFilenews;
////////////////////////////////////////////////////////////////////////////////����Ҫ��

	CNewsInfo newssina[8]; 
	MA=GetURL("http://www.sina.com.cn/");
	pos1=MA.Find("<!-- publish_helper name='Ҫ��-����",pos1);//��ҳҪ�Ų���Դ�����־
    if(sinanews==1){
	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	for(i=0;i<8;i++)
	{		
		newssina[i].web="sina";
		pos1=MA.Find("<li><a href=",pos1);//�ο�ͷ
		pos1=MA.Find("http://news.sina.com.cn/",pos1);//��λ����ַ��ͷ
		pos2=MA.Find(" target=",pos1);
		pos2=pos2-1;
		newssina[i].addr=MA.Mid(pos1,pos2-pos1);//��ȡ����ַ
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</a>",pos1);
		newssina[i].title=MA.Mid(pos1,pos2-pos1);//��ȡ������
		if(newssina[i].addr.Find("shtml")!=-1)
			if(newssina[i].title.GetLength()>=5)
				file.WriteString(newssina[i].title+"\n"+"sina\n"+newssina[i].addr+"\n");
	}

    file.Close();	
	}
	if(sohunews==1){
		MA=GetURL("http://news.sohu.com/");
	i=0; pos1=0; pos2=0;//pos1ǰλ�� pos2��λ��	
	CString sohunewsaddr[11],sohunewstitle[11];
	pos1=MA.Find("<DIV class=focus>",pos1);//��ҳҪ�Ų���Դ�����־
	if(sinanews==1){
	file.Open("news.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
    file.SeekToEnd();}
	else
		file.Open("news.txt",CFile::modeCreate|CFile::modeWrite);
	for(i=0;i<11;i++)
	{
		pos1=MA.Find("<LI><A ",pos1);//�ο�ͷ
		pos1=MA.Find("http://",pos1);//��λ����ַ��ͷ
		pos2=MA.Find("target=_blank",pos1);
		pos2=pos2-2;
		sohunewsaddr[i]=MA.Mid(pos1,pos2-pos1);//��ȡ����ַ
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</A>",pos1);
		sohunewstitle[i]=MA.Mid(pos1,pos2-pos1);//��ȡ������
	       if(	sohunewsaddr[i].Find("shtml")!=-1)
             file.WriteString(sohunewstitle[i]+"\n"+"sohu\n"+sohunewsaddr[i]+"\n");
	}
		file.Close();
	}
	


	mFilenews.Open("news.txt",CFile::modeRead);
	

	i=0;
	for(;mFilenews.ReadString(mynews[i].title);) //����ĳ�������ȡ��
	{
		
		mFilenews.ReadString(mynews[i].web);
		mFilenews.ReadString(mynews[i].addr);
		//mFilenews.ReadString(mynews[i].time);
		m_listnews.InsertItem(0,"");
		m_listnews.SetItemText(0,0,mynews[i].title);
		m_listnews.SetItemText(0,1,mynews[i].web);
		//m_listnews.SetItemText(0,2,mynews[i].addr);
		i++;
	};
	newsnum=i;
	mFilenews.Close();
}

void Cnews::OnPaint() 
{
CPaintDC dc(this); // device context for painting

       CRect   rect;   

       GetClientRect(&rect);   

       CDC   dcMem;   

       dcMem.CreateCompatibleDC(&dc);   

       CBitmap   bmpBackground;   

       bmpBackground.LoadBitmap(IDB_BITMAP2); 

//IDB_BITMAP是你自己的图对应的ID 

       BITMAP   bitmap;   

       bmpBackground.GetBitmap(&bitmap);   

       CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   

       dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 

       // Do not call CDialog::OnPaint() for painting messages
}

	int M,N;

void Cnews::OnButton3() 
{	
	// TODO: Add your control notification handler code here
	for(int z=0;z<19;z++)
	{
		m_listnews.SetItemState(z,0,LVIS_SELECTED|LVIS_FOCUSED);
	}

	UpdateData(true);
//	CStdioFile file;
//	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	char str[100];
	ifstream file("news.txt");	
//	AfxMessageBox(Str);
	int b=19;
	int P=1;
	int L=1;
	
	for(;;P++)
	{
		file.getline(str,100);
		CString Str;
		Str=str;
		L=Str.Find(m_stringnews);
		if(L!=-1)
		{
			
			M=newsnum-(P+2)/3;
			m_listnews.SetFocus();
			m_listnews.SetItemState(M, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			if(L!=-1)
			{
				N=newsnum-(P+2)/3;
				m_listnews.SetFocus();
				m_listnews.SetItemState(N, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			}
		}	
		
		if (P==57){return;}
	}
		
}
