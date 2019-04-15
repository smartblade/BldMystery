// mfcView.h : interface of the CmfcView class
//


#pragma once


class CmfcView : public CView
{
protected: // create from serialization only
	CmfcView();
	DECLARE_DYNCREATE(CmfcView)

// Attributes
public:
	CmfcDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CmfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfcView.cpp
inline CmfcDoc* CmfcView::GetDocument() const
   { return reinterpret_cast<CmfcDoc*>(m_pDocument); }
#endif

