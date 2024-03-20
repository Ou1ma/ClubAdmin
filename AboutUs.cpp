// AboutUs.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "AboutUs.h"
#include "afxdialogex.h"


// AboutUs dialog

IMPLEMENT_DYNAMIC(AboutUs, CDialogEx)

AboutUs::AboutUs(CWnd* pParent /*=NULL*/)
	: CDialogEx(AboutUs::IDD, pParent)
{

}

AboutUs::~AboutUs()
{
}

void AboutUs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutUs, CDialogEx)
END_MESSAGE_MAP()
BOOL AboutUs::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Add initialization code here

    // Set the icon for this dialog
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);

    return TRUE;
}

// AboutUs message handlers
