#pragma once
#include "afxcmn.h"


// Activitie dialog

class Activitie : public CDialogEx
{
	DECLARE_DYNAMIC(Activitie)

public:
	Activitie(CWnd* pParent = NULL);   // standard constructor
	virtual ~Activitie();
	void RefreshList();
	void RefreshAssoc();
// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list_AC;
public:
    virtual BOOL OnInitDialog();
	int m_free;
	afx_msg void OnBnClickedDeleteac();
	afx_msg void OnBnClickedCancelac();
	afx_msg void OnBnClickedSearchac();
	afx_msg void OnBnClickedAddac();
	afx_msg void OnBnClickedModifyac();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedlistbyvill();
	CString m_acode;
	CString m_aname;
	CString m_avi;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CString m_ca;
	CListCtrl list_SETT;
	afx_msg void OnBnClickedaa();
	afx_msg void OnBnClickedda();
	afx_msg void OnBnClickedma();
	afx_msg void OnBnClickedsa();
	afx_msg void OnBnClickedRef();
	afx_msg void OnBnClickedfaa();
	afx_msg void OnBnClickedpaa();
};
