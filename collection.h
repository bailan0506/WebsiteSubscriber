#if !defined(AFX_COLLECTION_H__BE39B333_6041_469D_B90F_F7FCB97E321A__INCLUDED_)
#define AFX_COLLECTION_H__BE39B333_6041_469D_B90F_F7FCB97E321A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// collection.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ccollection dialog

class Ccollection : public CDialog
{
// Construction
public:
	Ccollection(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ccollection)
	enum { IDD = IDD_COLLECTION };
	CListCtrl	m_list;
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ccollection)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ccollection)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLLECTION_H__BE39B333_6041_469D_B90F_F7FCB97E321A__INCLUDED_)
