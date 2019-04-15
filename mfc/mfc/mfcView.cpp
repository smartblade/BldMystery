// mfcView.cpp : implementation of the CmfcView class
//

#include "stdafx.h"
#include "mfc.h"

#include "mfcDoc.h"
#include "mfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcView

IMPLEMENT_DYNCREATE(CmfcView, CView)

BEGIN_MESSAGE_MAP(CmfcView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmfcView construction/destruction

CmfcView::CmfcView()
{
	// TODO: add construction code here

}

CmfcView::~CmfcView()
{
}

BOOL CmfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CmfcView drawing

void CmfcView::OnDraw(CDC* /*pDC*/)
{
	CmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CmfcView printing

BOOL CmfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CmfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CmfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CmfcView diagnostics

#ifdef _DEBUG
void CmfcView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcDoc* CmfcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcDoc)));
	return (CmfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcView message handlers
