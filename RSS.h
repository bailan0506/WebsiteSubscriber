// RSS.h : main header file for the RSS application
//

#if !defined(AFX_RSS_H__A3C1E5F2_7557_4F6F_ABF9_B07ED840AFC6__INCLUDED_)
#define AFX_RSS_H__A3C1E5F2_7557_4F6F_ABF9_B07ED840AFC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRSSApp:
// See RSS.cpp for the implementation of this class
//

class CRSSApp : public CWinApp
{
public:
	CRSSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRSSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSS_H__A3C1E5F2_7557_4F6F_ABF9_B07ED840AFC6__INCLUDED_)
