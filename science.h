#if !defined(AFX_SCIENCE_H__F36C499B_CB50_4BE3_A93E_3DD3DFC201FF__INCLUDED_)
#define AFX_SCIENCE_H__F36C499B_CB50_4BE3_A93E_3DD3DFC201FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// science.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cscience dialog

class Cscience : public CDialog
{
// Construction
public:
	Cscience(CWnd* pParent = NULL);   // standard constructor
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
	//{{AFX_DATA(Cscience)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_listscience;
	CString	m_editscience;
	CString	m_stringsci;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cscience)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cscience)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListscience(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton4();
	afx_msg void OnButton3();
	afx_msg void OnPaint();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCIENCE_H__F36C499B_CB50_4BE3_A93E_3DD3DFC201FF__INCLUDED_)
