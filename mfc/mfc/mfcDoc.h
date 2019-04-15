// mfcDoc.h : interface of the CmfcDoc class
//


#pragma once


class CmfcDoc : public CDocument
{
protected: // create from serialization only
	CmfcDoc();
	DECLARE_DYNCREATE(CmfcDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CmfcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


