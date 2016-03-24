#if !defined(AFX_HELP_H__0C6D6459_CC6B_46F1_91B7_3C78A2AB5936__INCLUDED_)
#define AFX_HELP_H__0C6D6459_CC6B_46F1_91B7_3C78A2AB5936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// help.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Chelp dialog

class Chelp : public CDialog
{
// Construction
public:
	Chelp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Chelp)
	enum { IDD = IDD_DIALOG10 };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Chelp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Chelp)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELP_H__0C6D6459_CC6B_46F1_91B7_3C78A2AB5936__INCLUDED_)
