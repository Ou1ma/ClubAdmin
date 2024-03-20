// Continents.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "Continents.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include <afxdao.h>


// Continents dialog

IMPLEMENT_DYNAMIC(Continents, CDialogEx)

Continents::Continents(CWnd* pParent /*=NULL*/)
    : CDialogEx(Continents::IDD, pParent)
	, m_code(_T(""))
	, m_name(_T(""))
{
}

Continents::~Continents()
{
}

void Continents::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_CO);
	DDX_Text(pDX, IDC_CO1, m_code);
	DDX_Text(pDX, IDC_CO2, m_name);
}

BEGIN_MESSAGE_MAP(Continents, CDialogEx)
    ON_EN_CHANGE(IDC_EDIT1, &Continents::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_ADDCO, &Continents::OnBnClickedAddco)
	ON_BN_CLICKED(IDC_DELETECO, &Continents::OnBnClickedDeleteco)
	ON_BN_CLICKED(IDC_CANCELCO, &Continents::OnBnClickedCancelco)
	ON_BN_CLICKED(IDC_MODIFYCO, &Continents::OnBnClickedModifyco)
	ON_BN_CLICKED(IDC_SEARCHCO, &Continents::OnBnClickedSearchco)
	ON_BN_CLICKED(IDC_CANCELCO2, &Continents::OnBnClickedCancelco2)
END_MESSAGE_MAP()

BOOL Continents::OnInitDialog()
{
    CDialogEx::OnInitDialog();

CButton* aButton = (CButton*)GetDlgItem(IDC_ADDCO);
aButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
aButton->ModifyStyle(0, BS_TOP);
aButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* bButton = (CButton*)GetDlgItem(IDC_DELETECO);
bButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
bButton->ModifyStyle(0, BS_TOP);
bButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* cButton = (CButton*)GetDlgItem(IDC_MODIFYCO);
cButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
cButton->ModifyStyle(0, BS_TOP);
cButton->SetIcon(AfxGetApp()->LoadIcon(IDI_MODIFY));

CButton* dButton = (CButton*)GetDlgItem(IDC_SEARCHCO);
dButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
dButton->ModifyStyle(0, BS_TOP);
dButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));

CButton* eButton = (CButton*)GetDlgItem(IDC_CANCELCO);
eButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
eButton->ModifyStyle(0, BS_TOP);
eButton->SetIcon(AfxGetApp()->LoadIcon(IDI_lcancel));

CButton* zButton = (CButton*)GetDlgItem(IDC_CANCELCO2);
zButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zButton->ModifyStyle(0, BS_TOP);
zButton->SetIcon(AfxGetApp()->LoadIcon(IDI_refresh));




    // Add initialization code here

    // Set the icon for this dialog
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);

		list_CO.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_CO.InsertColumn(1, L"CODE", LVCFMT_CENTER, 130, -1);
list_CO.InsertColumn(2, L"CONTINENT", LVCFMT_CENTER, 130, -1);
ListView_SetExtendedListViewStyle(list_CO, LVS_EX_GRIDLINES);
list_CO.SetBkColor(RGB(200,200,200));
RefreshList();
    return TRUE;

}

void Continents::RefreshList()
{	
    CDaoDatabase db;
    CDaoRecordset recset(&db);
       COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
        CString idc, codec, namec;//end variables
        list_CO.DeleteAllItems();//clear list
       db.Open(L"GestionVillages.mdb");  
        recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Continents",NULL);
   while(!recset.IsEOF())  //do until eof
  {int i=0;
       recset.GetFieldValue(L"id", var);
        idc.Format(L"%d",(LPCWSTR)var.pbstrVal);
        recset.GetFieldValue(L"code_continent",var);
	    codec=(LPCWSTR)var.pbstrVal;
       recset.GetFieldValue(L"continent",var);
	    namec=(LPCWSTR)var.pbstrVal;
        list_CO.InsertItem(i,idc,0); //filling the list fields 
       list_CO.SetItemText(i,1,codec);
	   list_CO.SetItemText(i,2,namec);
	i=i++;
	recset.MoveNext();   }
        db.Close();
}


void Continents::OnEnChangeEdit1()
{
    // Handle the change in the edit control
}


void Continents::OnBnClickedAddco()
{
    CDaoDatabase db;
    CDaoRecordset recset(&db);
// TODO: Add your control notification handler code here
CString idc, codec, namec;
GetDlgItemText(IDC_CO1,codec);
GetDlgItemText(IDC_CO2,namec);
db.Open(L"C://Users/DELL/Documents/Visual Studio 2010/Projects/ClubAdmin/ClubAdmin/GestionVillages.mdb");
recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Continents",NULL);
recset.AddNew();
recset.SetFieldValue(L"code_continent",(LPCWSTR)codec);
recset.SetFieldValue(L"continent",(LPCWSTR)namec);
recset.Update();
db.Close();
RefreshList();
m_name=L"";
m_code=L"";
UpdateData(false);
}


	// TODO: Add your control notification handler code here


void Continents::OnBnClickedDeleteco()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	//CDaoRecordset recset1(&db);
	db.Open(L"GestionVillages.mdb");
	CString codec;
	GetDlgItemText(IDC_CO1,codec);
	//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Countries WHERE code_continent='"+codec+"'");
	//recset1.Delete();
	//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Continents WHERE code_continent='"+codec+"'");
	//strSQL.Format(L"DELETE FROM Continents WHERE code_continent='%s'",codec);
	CString strSQLCountries;
strSQLCountries.Format(L"DELETE FROM Countries WHERE code_continent='%s'", codec);
db.Execute(strSQLCountries);

// Delete records from Continents table
CString strSQLContinents;
strSQLContinents.Format(L"DELETE FROM Continents WHERE code_continent='%s'", codec);
db.Execute(strSQLContinents);
	//recset.Delete();
     RefreshList();
    //AfxMessageBox(L"THE CONTINENT HAS BEEN DELETED SUCCESSFULLY!",MB_ICONINFORMATION|MB_OK);  
	// TODO: Add your control notification handler code here
}


void Continents::OnBnClickedCancelco()
{
	
    OnOK();
	 //TODO: Add your control notification handler code here
}


void Continents::OnBnClickedModifyco()
{
	CDaoDatabase db;
CDaoRecordset recset(&db);
db.Open(L"GestionVillages.mdb");
CString c,n;
GetDlgItemText(IDC_CO1,c);
GetDlgItemText(IDC_CO2,n);
CString strSql;
strSql.Format(L"UPDATE Continents SET continent='%s' WHERE code_continent='%s'", n, c);
db.Execute(strSql);
//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"UPDATE Continents SET continent = '"+n+"' WHERE code_continent = '"+c+"'",NULL);
//recset.SetFieldValue(L"code_continent",(LPCWSTR)c);
//recset.SetFieldValue(L"continent",(LPCWSTR)n);
RefreshList();
AfxMessageBox(L"Les informations du continent "+c+" "+n+" \n a été mis à jour avec succès !",MB_ICONINFORMATION|MB_OK);
}

	// TODO: Add your control notification handler code here


void Continents::OnBnClickedSearchco()
{
	CDaoDatabase db;
CDaoRecordset recset(&db);
db.Open(L"GestionVillages.mdb");
	CString d,c,cc;// variant
GetDlgItemText(IDC_CO1,c);
COleVariant var;
var.ChangeType(VT_BSTR,NULL);
list_CO.DeleteAllItems(); //effacer la list
recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Continents WHERE code_continent='"+c+"' ",NULL);
recset.GetFieldValue(L"id",var);
d.Format(L"%d",(LPCWSTR)var.pbstrVal);
list_CO.InsertItem(0,d,0);
recset.GetFieldValue(L"code_continent",var);
c=(LPCWSTR)var.pbstrVal;
list_CO.SetItemText(0,1,c);
recset.GetFieldValue(L"continent",var);
cc=(LPCWSTR)var.pbstrVal;
list_CO.SetItemText(0,2,cc);
recset.Close();
db.Close();
}
// TODO: Add your control notification handler code here

void Continents::OnBnClickedCancelco2()
{
	RefreshList();
	// TODO: Add your control notification handler code here
}
