#if !defined(AFX_ADDCOLLECTION_H__24B30CE3_E0BE_44C6_A69A_4564F6F80A24__INCLUDED_)
#define AFX_ADDCOLLECTION_H__24B30CE3_E0BE_44C6_A69A_4564F6F80A24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// addcollection.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Caddcollection dialog

class Caddcollection : public CDialog
{
// Construction
public:
	Caddcollection(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Caddcollection)
	enum { IDD = IDD_DIALOG9 };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Caddcollection)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Caddcollection)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCOLLECTION_H__24B30CE3_E0BE_44C6_A69A_4564F6F80A24__INCLUDED_)
