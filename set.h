#if !defined(AFX_SET_H__A55C2DD1_18B8_40E6_A48E_35446C053B7C__INCLUDED_)
#define AFX_SET_H__A55C2DD1_18B8_40E6_A48E_35446C053B7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cset dialog

class Cset : public CDialog
{
// Construction
public:
	Cset(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cset)
	enum { IDD = IDD_SET };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cset)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cset)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_H__A55C2DD1_18B8_40E6_A48E_35446C053B7C__INCLUDED_)
