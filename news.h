#if !defined(AFX_NEWS_H__31379CF1_D319_4235_A55A_E00F42299F42__INCLUDED_)
#define AFX_NEWS_H__31379CF1_D319_4235_A55A_E00F42299F42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// news.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cnews dialog

class Cnews : public CDialog
{
// Construction
public:
	int newsnum;
	Cnews(CWnd* pParent = NULL);   // standard constructor
	// Dialog Data
	//{{AFX_DATA(Cnews)
	enum { IDD = IDD_DIALOG1 };
	CScrollBar	m_scrollbarnews;
	CListCtrl	m_listnews;
	CString	m_editnews;
	CString	m_stringnews;
	//}}AFX_DATA
		CString GetURL(CString address)
	{
		//UpdateData();
		CInternetSession sess;//建立会话
		CHttpFile* pF=(CHttpFile*)sess.OpenURL(address);//打开文件
		CString szData,szAllData,m_szHTML;
		while(pF->ReadString(szData)){//读取文件
			szAllData+="\r\n";
			szAllData+=szData;
		}
		pF->Close();
		sess.Close();
		m_szHTML=szAllData;
		return m_szHTML;
		//UpdateData(FALSE);
	}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cnews)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cnews)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListnews(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnPaint();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWS_H__31379CF1_D319_4235_A55A_E00F42299F42__INCLUDED_)
