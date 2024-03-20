#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Country dialog

class Country : public CDialogEx
{
	DECLARE_DYNAMIC(Country)

public:
	Country(CWnd* pParent = NULL);   // standard constructor
	virtual ~Country();
	void RefreshList();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list_CY;
public:
    virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddcy();
	CString m_ccode;
	CString m_cname;
	CString m_ccontin;
	afx_msg void OnBnClickedCancelcy();
	afx_msg void OnBnClickedDeletecy();
	afx_msg void OnBnClickedSearchcy();
	afx_msg void OnBnClickedModifycy();
	afx_msg void OnBnClickedrefresh();
};
