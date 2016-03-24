#if !defined(AFX_COMMETS_H__FB30E516_2D5A_4AB9_BC5C_586BD5A9FBC2__INCLUDED_)
#define AFX_COMMETS_H__FB30E516_2D5A_4AB9_BC5C_586BD5A9FBC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// commets.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ccommets dialog

class Ccommets : public CDialog
{
// Construction
public:
	Ccommets(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ccommets)
	enum { IDD = IDD_DIALOG2 };
	CListCtrl	m_listcomments;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ccommets)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ccommets)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMETS_H__FB30E516_2D5A_4AB9_BC5C_586BD5A9FBC2__INCLUDED_)
