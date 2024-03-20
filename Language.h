#pragma once
#include "afxcmn.h"


// Language dialog

class Language : public CDialogEx
{
	DECLARE_DYNAMIC(Language)

public:
	Language(CWnd* pParent = NULL);   // standard constructor
	virtual ~Language();
	void RefreshList();
	void RrefreshAsso();
// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list_LA;
public:
    virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancella();
	afx_msg void OnBnClickedAddla();
	CString m_lcode;
	CString m_lname;
	CString m_lvi;
	afx_msg void OnBnClickedDeletela();
	afx_msg void OnBnClickedModifyla();
	afx_msg void OnBnClickedSearchla();
	afx_msg void OnBnClickedLalist();
	afx_msg void OnBnClickedVilist();
	CString m_lac;
	CListCtrl list_SET;
	afx_msg void OnBnClickedal();
	afx_msg void OnBnClickeddl();
	afx_msg void OnBnClickedml();
	afx_msg void OnBnClickedsl();
	afx_msg void OnBnClickedrefresh();
};
