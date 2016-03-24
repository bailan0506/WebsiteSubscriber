// play.cpp : implementation file
//

#include "stdafx.h"
#include "RSS.h"
#include "play.h"
#include "NewsInfo.h"
#include "RSSDlg.h"
#include "addcollection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cplay dialog

CNewsInfo myplay[100];
int playnum;
Cplay::Cplay(CWnd* pParent /*=NULL*/)
	: CDialog(Cplay::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cplay)
	m_editplay = _T("");
	m_stringplay = _T("");
	//}}AFX_DATA_INIT
}


void Cplay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cplay)
	DDX_Control(pDX, IDC_LISTPLAY, m_listplay);
	DDX_Text(pDX, IDC_EDIT3, m_editplay);
	DDX_Text(pDX, IDC_EDIT1, m_stringplay);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cplay, CDialog)
	//{{AFX_MSG_MAP(Cplay)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTPLAY, OnDblclkListplay)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cplay message handlers

BOOL Cplay::OnInitDialog() 
{
	CDialog::OnInitDialog();
		m_listplay.SetTextColor(RGB(100, 0, 100));
	// TODO: Add extra initialization here
	m_listplay.DeleteAllItems();
	m_listplay.InsertColumn(0,"����",LVCFMT_LEFT,300);         //������
    m_listplay.InsertColumn(1,"��վ",LVCFMT_LEFT,50);
	//m_listplay.InsertColumn(2,"ʱ��",LVCFMT_LEFT,100);
	CStdioFile mFileplay;
    mFileplay.Open("play.txt",CFile::modeRead);

	int i=0;
	for(;mFileplay.ReadString(myplay[i].title);) //����ĳ�������ȡ��
	{
		
		mFileplay.ReadString(myplay[i].web);
		mFileplay.ReadString(myplay[i].addr);
		//mFileplay.ReadString(myplay[i].time);
		m_listplay.InsertItem(0,"");
		m_listplay.SetItemText(0,0,myplay[i].title);
		m_listplay.SetItemText(0,1,myplay[i].web);
		//m_listplay.SetItemText(0,2,myplay[i].addr);
		i++;
	};
	playnum=i;
	mFileplay.Close();  
	
	return TRUE;
	// return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cplay::OnDblclkListplay(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
		POSITION p=m_listplay.GetFirstSelectedItemPosition();
	if (p == NULL)
	{
	TRACE("û���б�ѡ��!");
	}
	//��ȡ��ѡȡ��λ�õ��±�(��0��ʼ��) 
	int index = m_listplay.GetNextSelectedItem(p);
	CString MA=myplay[playnum-index-1].GetURL();
	int i,pos1,pos2;
	if(myplay[playnum-index-1].web=="sina"){
		i=0; pos1=0; pos2=0;//pos1ǰλ�� pos2��λ��
		//CString m_editplay;//
		pos1=MA.Find("<!-- publish_helper name='ԭʼ����' ",pos1);//���ı�־

		pos1=MA.Find("<p>",pos1);//�ο�ͷ
		pos2=MA.Find("<!-- publish_helper_end -->",pos1);
		pos2=pos2-1;
		m_editplay=MA.Mid(pos1,pos2-pos1);//��ȡ������

		m_editplay.Replace("<p>","\n");//�����ɾ������������
		int p1=0,p2=0;
		for(;p1!=-1 && p2!=-1;)
		{
			p1=0,p2=0;
			p1=m_editplay.Find("<",0);
			p2=m_editplay.Find(">",0);
			m_editplay.Delete(p1,p2-p1+1);
		}
	}
	editsave=m_editplay;
	titlesave=myplay[playnum-index-1].title;
    UpdateData(FALSE);
	*pResult = 0;
}

void Cplay::OnButton1() 
{
	// TODO: Add your control notification handler code here
	 Caddcollection  addcollect;
	 addcollect.DoModal();
}

void Cplay::OnButton2() 
{


	CString MA;
	int i,pos1,pos2;
	CStdioFile file;
	CString target,webmark;
	CString addr[10],title[10];
	i=0; pos1=0; pos2=0;//pos1ǰλ�� pos2��λ��	
		m_listplay.DeleteAllItems();
		CStdioFile mFileplay;
	// TODO: Add your control notification handler code here
	if(sinaplay==1){
	MA=GetURL("http://www.sina.com.cn/");
	file.Open("play.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	pos1=MA.Find("<!-- publish_helper name='��������'",pos1);//��ҳҪ�Ų���Դ�����־
	for(i=0;i<8;i++)
	{
		
	
		pos1=MA.Find("<li><a target=",pos1);//�ο�ͷ
		pos1=MA.Find("http://",pos1);//��λ����ַ��ͷ
		pos2=MA.Find(">",pos1);
		pos2=pos2-1;
		addr[i]=MA.Mid(pos1,pos2-pos1);//��ȡ����ַ
		pos1=MA.Find(">",pos2);
		pos1=pos1+1;
		pos2=MA.Find("</a>",pos1);
		title[i]=MA.Mid(pos1,pos2-pos1);//��ȡ������
		if(addr[i].Find("shtml")!=-1)
				file.WriteString(title[i]+"\n"+"sina\n"+addr[i]+"\n");
	}
	file.Close();

    mFileplay.Open("play.txt",CFile::modeRead);

	i=0;
	for(;mFileplay.ReadString(myplay[i].title);) //����ĳ�������ȡ��
	{
		
		mFileplay.ReadString(myplay[i].web);
		mFileplay.ReadString(myplay[i].addr);
		//mFileplay.ReadString(myplay[i].time);
		m_listplay.InsertItem(0,"");
		m_listplay.SetItemText(0,0,myplay[i].title);
		m_listplay.SetItemText(0,1,myplay[i].web);
		//m_listplay.SetItemText(0,2,myplay[i].addr);
		i++;
	};
	playnum=i;
	mFileplay.Close();  
}



}

void Cplay::OnPaint() 
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


int d,f;

void Cplay::OnButton3() 
{	
	// TODO: Add your control notification handler code here
	for(int z=0;z<19;z++)
	{
		m_listplay.SetItemState(z,0,LVIS_SELECTED|LVIS_FOCUSED);
	}

	UpdateData(true);
//	CStdioFile file;
//	file.Open("news.txt",CFile::modeCreate|/*CFile::modeNoTruncate|*/CFile::modeWrite);
	char str[100];
	ifstream file("play.txt");	
//	AfxMessageBox(Str);
	int b=19;
	int P=1;
	int L=1;
	
	for(;;P++)
	{
		file.getline(str,100);
		CString Str;
		Str=str;
		L=Str.Find(m_stringplay);
		if(L!=-1)
		{
			d=playnum-(P+2)/3;
			m_listplay.SetFocus();
			m_listplay.SetItemState(d, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			if(L!=-1)
			{
				f=playnum-(P+2)/3;
				m_listplay.SetFocus();
				m_listplay.SetItemState(f, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);	
			}
		}	
		
		if (P==57){return;}
	}
		
}
