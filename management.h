#if !defined(AFX_MANAGEMENT_H__E0B779E5_768B_466F_9C52_D8DCA4B559DB__INCLUDED_)
#define AFX_MANAGEMENT_H__E0B779E5_768B_466F_9C52_D8DCA4B559DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// management.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cmanagement dialog

class Cmanagement : public CDialog
{
// Construction
public:
	Cmanagement(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cmanagement)
	enum { IDD = IDD_MANAGEMENT };
	BOOL	m_sinanews;
	BOOL	m_sohunews;
	BOOL	m_sinascience;
	BOOL	m_sinaplay;
	BOOL	m_sohuhistory;
	BOOL	m_sohucomments;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cmanagement)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cmanagement)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEMENT_H__E0B779E5_768B_466F_9C52_D8DCA4B559DB__INCLUDED_)
