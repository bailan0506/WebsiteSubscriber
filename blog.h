#if !defined(AFX_BLOG_H__8C89D2CD_9AE8_4A1D_B997_9C8702BDB0A2__INCLUDED_)
#define AFX_BLOG_H__8C89D2CD_9AE8_4A1D_B997_9C8702BDB0A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// blog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cblog dialog

class Cblog : public CDialog
{
// Construction
public:
	Cblog(CWnd* pParent = NULL);   // standard constructor
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
	//{{AFX_DATA(Cblog)
	enum { IDD = IDD_DIALOG7 };
	CListCtrl	m_listblog;
	CString	m_editblog;
	CString	m_stringblog;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cblog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cblog)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListblog(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnPaint();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLOG_H__8C89D2CD_9AE8_4A1D_B997_9C8702BDB0A2__INCLUDED_)
