// RSSDlg.h : header file
//

#if !defined(AFX_RSSDLG_H__080B8430_86C7_4811_AC4B_A85156155BDC__INCLUDED_)
#define AFX_RSSDLG_H__080B8430_86C7_4811_AC4B_A85156155BDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRSSDlg dialog
#include "news.h"
#include "commets.h"
#include "science.h"
#include "sports.h"
#include "history2.h"
#include "play.h"
#include "blog.h"
#include "management.h"
#include "help.h"
#include "collection.h"

class CRSSDlg : public CDialog
{
// Construction
public:
	CRSSDlg(CWnd* pParent = NULL);	// standard constructor
	Cnews m_news;
	Ccommets m_comments;
	Cscience m_science;
	Csports m_sports;
	Cplay m_play;
	Chistory m_history;
	Cblog m_blog;
	 Cmanagement  Dlg1;
   Chelp Dlg4;
   Ccollection Dlg5;
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
	/////////////////////////////////////////////////////////
    
	// Dialog Data
	//{{AFX_DATA(CRSSDlg)
	enum { IDD = IDD_RSS_DIALOG };
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRSSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnManagement();
	afx_msg void OnCOllECTION();
	afx_msg void OnSet();
	afx_msg void OnIntro();
	afx_msg void Oncollection();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSSDLG_H__080B8430_86C7_4811_AC4B_A85156155BDC__INCLUDED_)
