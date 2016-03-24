#if !defined(AFX_HISTORY2_H__A5E650F7_EBAE_4D20_910C_A5D2598AC2D6__INCLUDED_)
#define AFX_HISTORY2_H__A5E650F7_EBAE_4D20_910C_A5D2598AC2D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// history2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Chistory dialog

class Chistory : public CDialog
{
// Construction
public:
	Chistory(CWnd* pParent = NULL);   // standard constructor
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
	//{{AFX_DATA(Chistory)
	enum { IDD = IDD_DIALOG6 };
	CListCtrl	m_listhistory;
	CString	m_edithistory;
	CString	m_stringhistory;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Chistory)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Chistory)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListhistory(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnPaint();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORY2_H__A5E650F7_EBAE_4D20_910C_A5D2598AC2D6__INCLUDED_)
