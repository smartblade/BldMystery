// mfcDoc.cpp : implementation of the CmfcDoc class
//

#include "stdafx.h"
#include "mfc.h"

#include "mfcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcDoc

IMPLEMENT_DYNCREATE(CmfcDoc, CDocument)

BEGIN_MESSAGE_MAP(CmfcDoc, CDocument)
END_MESSAGE_MAP()


// CmfcDoc construction/destruction

CmfcDoc::CmfcDoc()
{
	// TODO: add one-time construction code here

}

CmfcDoc::~CmfcDoc()
{
}

BOOL CmfcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CmfcDoc serialization

void CmfcDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CmfcDoc diagnostics

#ifdef _DEBUG
void CmfcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmfcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmfcDoc commands
