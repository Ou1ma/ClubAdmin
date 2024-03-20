#pragma once
#include "afxcmn.h"
//#include <afxdao.h>


// Continents dialog

class Continents : public CDialogEx
{
	DECLARE_DYNAMIC(Continents)

public:
	Continents(CWnd* pParent = NULL);   // standard constructor
	virtual ~Continents();
	void RefreshList();

// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();



    // other declarations

public:
	afx_msg void OnEnChangeEdit1();
	CListCtrl list_CO;
	CString m_code;
	CString m_name;
	afx_msg void OnBnClickedAddco();
	afx_msg void OnBnClickedDeleteco();
	afx_msg void OnBnClickedCancelco();
	afx_msg void OnBnClickedModifyco();
	afx_msg void OnBnClickedSearchco();
	afx_msg void OnBnClickedCancelco2();
};
