#pragma once


// AboutUs dialog

class AboutUs : public CDialogEx
{
	DECLARE_DYNAMIC(AboutUs)

public:
	AboutUs(CWnd* pParent = NULL);   // standard constructor
	virtual ~AboutUs();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
};
