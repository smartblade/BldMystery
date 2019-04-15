// mfc.h : main header file for the mfc application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CmfcApp:
// See mfc.cpp for the implementation of this class
//

class CmfcApp : public CWinApp
{
public:
	CmfcApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CmfcApp theApp;