#if !defined(AFX_PLAY_H__012231DF_4F86_4CF1_BC1C_1176ACC05811__INCLUDED_)
#define AFX_PLAY_H__012231DF_4F86_4CF1_BC1C_1176ACC05811__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// play.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cplay dialog

class Cplay : public CDialog
{
// Construction
public:
	Cplay(CWnd* pParent = NULL);   // standard constructor
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
// Dialog Data
	//{{AFX_DATA(Cplay)
	enum { IDD = IDD_DIALOG5 };
	CListCtrl	m_listplay;
	CString	m_editplay;
	CString	m_stringplay;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cplay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cplay)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListplay(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnPaint();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAY_H__012231DF_4F86_4CF1_BC1C_1176ACC05811__INCLUDED_)
