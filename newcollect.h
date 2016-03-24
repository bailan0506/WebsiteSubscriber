#if !defined(AFX_NEWCOLLECT_H__726E7FFA_FE3E_4F30_9BE4_D8A1D8CB15EE__INCLUDED_)
#define AFX_NEWCOLLECT_H__726E7FFA_FE3E_4F30_9BE4_D8A1D8CB15EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// newcollect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cnewcollect dialog

class Cnewcollect : public CDialog
{
// Construction
public:
	Cnewcollect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cnewcollect)
	enum { IDD = IDD_DIALOG8 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cnewcollect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cnewcollect)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWCOLLECT_H__726E7FFA_FE3E_4F30_9BE4_D8A1D8CB15EE__INCLUDED_)
