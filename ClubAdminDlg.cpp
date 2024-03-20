
// ClubAdminDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "ClubAdminDlg.h"
#include "afxdialogex.h"
#include "Village.h"
#include "Activitie.h"
#include "Language.h"
#include "Country.h"
#include "AboutUs.h"
#include "Continents.h"
#include <afxdao.h>
CDaoDatabase db;
CDaoRecordset recset(&db);

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClubAdminDlg dialog




CClubAdminDlg::CClubAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClubAdminDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClubAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CClubAdminDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CClubAdminDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClubAdminDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CClubAdminDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CClubAdminDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CClubAdminDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CClubAdminDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CClubAdminDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &CClubAdminDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CClubAdminDlg message handlers

BOOL CClubAdminDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON1);
	 pButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 pButton->ModifyStyle(0, BS_TOP);
pButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1));
CButton* aButton = (CButton*)GetDlgItem(IDC_BUTTON2);
	 aButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 aButton->ModifyStyle(0, BS_TOP);
aButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON2));

CButton* bButton = (CButton*)GetDlgItem(IDC_BUTTON3);
	 bButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 bButton->ModifyStyle(0, BS_TOP);
bButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON3));
CButton* cButton = (CButton*)GetDlgItem(IDC_BUTTON4);
	 cButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 cButton->ModifyStyle(0, BS_TOP);
cButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON4));

CButton* dButton = (CButton*)GetDlgItem(IDC_BUTTON6);
	 dButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 dButton->ModifyStyle(0, BS_TOP);
dButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON5));
CButton* eButton = (CButton*)GetDlgItem(IDC_BUTTON7);
	 eButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 eButton->ModifyStyle(0, BS_TOP);
eButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON6));

CButton* fButton = (CButton*)GetDlgItem(IDC_BUTTON8);
	 fButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 fButton->ModifyStyle(0, BS_TOP);
fButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON8));

CButton* gButton = (CButton*)GetDlgItem(IDC_BUTTON9);
	 gButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
	 gButton->ModifyStyle(0, BS_TOP);
gButton->SetIcon(AfxGetApp()->LoadIcon(IDI_CONTINENT));





	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClubAdminDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClubAdminDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClubAdminDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClubAdminDlg::OnBnClickedButton1()
{
	Village v;
	v.DoModal();
	
	// TODO: Add your control notification handler code here
}


void CClubAdminDlg::OnBnClickedButton2()
{
	Activitie a;
	a.DoModal();
	// TODO: Add your control notification handler code here
}


void CClubAdminDlg::OnBnClickedButton3()
{
	Language l;
	l.DoModal();
	// TODO: Add your control notification handler code here
}



void CClubAdminDlg::OnBnClickedButton4()
{
	Country c;
	c.DoModal();
	// TODO: Add your control notification handler code here
}


void CClubAdminDlg::OnBnClickedButton6()
{
	CString lpszFile = L"GestionVillages.mdb"; 
	db.Create(lpszFile);
	CString creation_continents=L"CREATE TABLE Continents (id AUTOINCREMENT, code_continent varchar(30) PRIMARY KEY, continent varchar(30))";
	CString creation_countries=L"CREATE TABLE Countries (id AUTOINCREMENT, code_country varchar(30) PRIMARY KEY, country varchar(30), code_continent varchar(30) REFERENCES Continents( code_continent)) ";
	CString creation_villages=L"CREATE TABLE Villages (id AUTOINCREMENT, code_village varchar(30) PRIMARY KEY, village varchar(30), code_country varchar(30) REFERENCES Countries( code_country)) ";
    CString creation_activities=L"CREATE TABLE Activities (id AUTOINCREMENT , code_activity varchar(30) PRIMARY KEY, activity varchar(30))";
	CString creation_languages=L"CREATE TABLE Languages (id AUTOINCREMENT, code_langue varchar(30) PRIMARY KEY, language varchar(30))";
	CString creation_speak = L"CREATE TABLE Speak(no AUTOINCREMENT, "
                               L"code_V VARCHAR(30) REFERENCES Villages(code_village) , "
                               L"code_L VARCHAR(30) REFERENCES Languages(code_langue), "
	                           L"PRIMARY KEY (code_V, code_L));";
	CString creation_offer =  L"CREATE TABLE Offer("
                                 L"no AUTOINCREMENT, "
                                 L"code_V VARCHAR(30) REFERENCES Villages(code_village), "
                                 L"code_A VARCHAR(30) REFERENCES Activities(code_activity), "
								 L"free_status varchar(30), "
	                             L"PRIMARY KEY (code_V, code_A));";
	db.Open(lpszFile);
	db.Execute(creation_continents);
	db.Execute(creation_countries);
	db.Execute(creation_villages);
    db.Execute(creation_activities);
	db.Execute(creation_languages);
	db.Execute(creation_speak);
	db.Execute(creation_offer);
	db.Close();
}


void CClubAdminDlg::OnBnClickedButton7()
{
	AboutUs au;
	au.DoModal();
	// TODO: Add your control notification handler code here
}


void CClubAdminDlg::OnBnClickedButton9()
{
	Continents con;
	con.DoModal();
	// TODO: Add your control notification handler code here
}


void CClubAdminDlg::OnBnClickedButton8()
{
	OnOK();
	// TODO: Add your control notification handler code here
}
