#pragma once
#include "afxcmn.h"
#include <afxdao.h>

// Village dialog

class Village : public CDialogEx
{
	DECLARE_DYNAMIC(Village)

public:
	Village(CWnd* pParent = NULL);   // standard constructor
	virtual ~Village();
    void RefreshList();
// Dialog Data
	enum { IDD = IDD_DIALOG1 };
private:
    CDaoDatabase db;
	CDaoRecordset recset;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CListCtrl list_VI;
public:
    virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddvi();
	CString m_vcode;
	CString m_vname;
	CString m_vco;
	afx_msg void OnBnClickedDeletevi();
	afx_msg void OnBnClickedModifyvi();
	afx_msg void OnBnClickedSearchvi();
	afx_msg void OnBnClickedCancelvi();
	afx_msg void OnBnClickedrefresh();
};
