#if !defined(AFX_SPORTS_H__9DF60F43_0240_461C_817E_996BCD1356E8__INCLUDED_)
#define AFX_SPORTS_H__9DF60F43_0240_461C_817E_996BCD1356E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// sports.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Csports dialog

class Csports : public CDialog
{
// Construction
public:
	Csports(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Csports)
	enum { IDD = IDD_DIALOG4 };
	CListCtrl	m_listsports;
	CString	m_editsports;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Csports)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Csports)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListsports(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPORTS_H__9DF60F43_0240_461C_817E_996BCD1356E8__INCLUDED_)
