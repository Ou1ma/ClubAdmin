// Country.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "Country.h"
#include "afxdialogex.h"
#include <afxdao.h>
//#include <stdio.h>

// Country dialog

IMPLEMENT_DYNAMIC(Country, CDialogEx)

Country::Country(CWnd* pParent /*=NULL*/)
	: CDialogEx(Country::IDD, pParent)
	, m_ccode(_T(""))
	, m_cname(_T(""))
	, m_ccontin(_T(""))
{

}

Country::~Country()
{
}

void Country::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_CY);
	DDX_Text(pDX, IDC_Cy1, m_ccode);
	DDX_Text(pDX, IDC_CY2, m_cname);
	DDX_Text(pDX, IDC_CY3, m_ccontin);
}


BEGIN_MESSAGE_MAP(Country, CDialogEx)
	ON_BN_CLICKED(IDC_ADDCY, &Country::OnBnClickedAddcy)
	ON_BN_CLICKED(IDC_CANCELCY, &Country::OnBnClickedCancelcy)
	ON_BN_CLICKED(IDC_DELETECY, &Country::OnBnClickedDeletecy)
	ON_BN_CLICKED(IDC_SEARCHCY, &Country::OnBnClickedSearchcy)
	ON_BN_CLICKED(IDC_MODIFYCY, &Country::OnBnClickedModifycy)
	ON_BN_CLICKED(IDC_refresh, &Country::OnBnClickedrefresh)
END_MESSAGE_MAP()

BOOL Country::OnInitDialog()
{
    CDialogEx::OnInitDialog();

CButton* iButton = (CButton*)GetDlgItem(IDC_ADDCY);
iButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
iButton->ModifyStyle(0, BS_TOP);
iButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* gButton = (CButton*)GetDlgItem(IDC_DELETECY);
gButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
gButton->ModifyStyle(0, BS_TOP);
gButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* hButton = (CButton*)GetDlgItem(IDC_MODIFYCY);
hButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
hButton->ModifyStyle(0, BS_TOP);
hButton->SetIcon(AfxGetApp()->LoadIcon(IDI_MODIFY));

CButton* jButton = (CButton*)GetDlgItem(IDC_SEARCHCY);
jButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
jButton->ModifyStyle(0, BS_TOP);
jButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));

CButton* kButton = (CButton*)GetDlgItem(IDC_CANCELCY);
kButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
kButton->ModifyStyle(0, BS_TOP);
kButton->SetIcon(AfxGetApp()->LoadIcon(IDI_lcancel));

CButton* ooButton = (CButton*)GetDlgItem(IDC_refresh);
ooButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
ooButton->ModifyStyle(0, BS_TOP);
ooButton->SetIcon(AfxGetApp()->LoadIcon(IDI_refresh));

    // Add initialization code here

    // Set the icon for this dialog
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);

		list_CY.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_CY.InsertColumn(1, L"CODE", LVCFMT_CENTER, 100, -1);
list_CY.InsertColumn(2, L"COUNTRY", LVCFMT_CENTER, 100, -1);
list_CY.InsertColumn(3, L"CONTINENT", LVCFMT_CENTER, 100, -1);
ListView_SetExtendedListViewStyle(list_CY, LVS_EX_GRIDLINES);
list_CY.SetBkColor(RGB(200,200,200));
RefreshList();
    return TRUE;
}
void Country::RefreshList()
{	
    CDaoDatabase db;
    CDaoRecordset recset(&db);
       COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
        CString idc, codec, namec, cont;//end variables
        list_CY.DeleteAllItems();//clear list
       db.Open(L"GestionVillages.mdb");  
	   CString strSQL = L"SELECT Countries.id, Countries.code_country, Countries.country, Continents.continent "
                  L"FROM Countries INNER JOIN Continents ON countries.code_continent = Continents.code_continent";

		/*CString strSQL = L"SELECT Countries.id, Countries.code_country, Countries.country, Continents.continent"
                     L"FROM Countries INNER JOIN Continents ON countries.code_continent = Continents.code_continent";*/
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
   while(!recset.IsEOF())  //do until eof
  {int i=0;
       recset.GetFieldValue(L"id", var);
        idc.Format(L"%d",(LPCWSTR)var.pbstrVal);
        recset.GetFieldValue(L"code_country",var);
	    codec=(LPCWSTR)var.pbstrVal;
       recset.GetFieldValue(L"country",var);
	    namec=(LPCWSTR)var.pbstrVal;
		recset.GetFieldValue(L"continent",var);
	    cont=(LPCWSTR)var.pbstrVal;
        list_CY.InsertItem(i,idc,0); //filling the list fields 
       list_CY.SetItemText(i,1,codec);
	   list_CY.SetItemText(i,2,namec);
	   list_CY.SetItemText(i,3,cont);
	i=i++;
	recset.MoveNext();   }
        db.Close();
}

// Country message handlers


void Country::OnBnClickedAddcy()
{
    CDaoDatabase db;
    CDaoRecordset recContinent(&db);
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    // TODO: Add your control notification handler code here
    CString codec, namec, conti;
    GetDlgItemText(IDC_Cy1, codec);
    GetDlgItemText(IDC_CY2, namec);
    GetDlgItemText(IDC_CY3, conti);
    db.Open(L"GestionVillages.mdb");
	CString strSQLContinent = L"SELECT code_continent FROM Continents WHERE continent = '" + conti + "'";
        recContinent.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLContinent, NULL);
            CString c;
			recContinent.GetFieldValue(L"code_continent",var);
	        c=(LPCWSTR)var.pbstrVal;
            //recContinent.GetFieldValue(L"code_continent", c);
    //CString strSQL = L"SELECT Countries.id, Countries.code_country, Countries.country, Continents.code_continent"
                     //L"FROM Countries INNER JOIN Continents ON conti = Continents.continent";
		//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE, L"SELECT * FROM Countries", NULL);
        recset.AddNew();
        recset.SetFieldValue(L"code_country", (LPCWSTR)codec);
        recset.SetFieldValue(L"country", (LPCWSTR)namec);
        recset.SetFieldValue(L"code_continent", (LPCWSTR)c);
        recset.Update();
        db.Close();
        RefreshList();
        m_cname = L"";
        m_ccode = L"";
        m_ccontin = L"";
        UpdateData(false);
}


void Country::OnBnClickedCancelcy()
{
	OnOK();
	// TODO: Add your control notification handler code here
}


void Country::OnBnClickedDeletecy()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	db.Open(L"GestionVillages.mdb");
	CString codec;
	GetDlgItemText(IDC_Cy1,codec);
	CString strSqlVillage;
strSqlVillage.Format(L"DELETE FROM Villages WHERE code_country='%s'", codec);
db.Execute(strSqlVillage);

// Delete records from Countries table
CString strSqlCountries;
strSqlCountries.Format(L"DELETE FROM Countries WHERE code_country='%s'", codec);
db.Execute(strSqlCountries);
	//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Countries WHERE code_country='"+codec+"'");
	//strSQL.Format(L"DELETE FROM Continents WHERE code_continent='%s'",codec);
	//recset.Delete();
    RefreshList();
	// TODO: Add your control notification handler code here
}


void Country::OnBnClickedSearchcy()
{
	CDaoDatabase db;
CDaoRecordset recset(&db);
db.Open(L"GestionVillages.mdb");
	CString d, code, name, cont, c;// variant
GetDlgItemText(IDC_Cy1,c);
COleVariant var;
var.ChangeType(VT_BSTR,NULL);
list_CY.DeleteAllItems(); //effacer la list
 //CString strSQL = L"SELECT Countries.id, Countries.code_country, Countries.country, Continents.continent "
                // L"FROM Countries INNER JOIN Continents ON countries.code_continent = Continents.code_continent "
                 //L"WHERE Countries.code_country='%s'";
 CString strSQL;
strSQL.Format(L"SELECT Countries.id, Countries.code_country, Countries.country, Continents.continent "
              L"FROM Countries INNER JOIN Continents ON countries.code_continent = Continents.code_continent "
              L"WHERE Countries.code_country='%s'", c);

recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
recset.GetFieldValue(L"id",var);
d.Format(L"%d",(LPCWSTR)var.pbstrVal);
list_CY.InsertItem(0,d,0);
recset.GetFieldValue(L"code_country",var);
code=(LPCWSTR)var.pbstrVal;
list_CY.SetItemText(0,1,code);
recset.GetFieldValue(L"country",var);
name=(LPCWSTR)var.pbstrVal;
list_CY.SetItemText(0,2,name);
recset.GetFieldValue(L"continent",var);
cont=(LPCWSTR)var.pbstrVal;
list_CY.SetItemText(0,3,cont);
recset.Close();
db.Close();
	// TODO: Add your control notification handler code here
}


void Country::OnBnClickedModifycy()
{
	CDaoDatabase db;
    CDaoRecordset recContinent(&db);
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);

    // TODO: Add your control notification handler code here
    CString codec, namec, conti;
    GetDlgItemText(IDC_Cy1, codec);
    GetDlgItemText(IDC_CY2, namec);
    GetDlgItemText(IDC_CY3, conti);
	db.Open(L"GestionVillages.mdb");
	// TODO: Add your control notification handler code here
	CString strSQLContinent = L"SELECT code_continent FROM Continents WHERE continent = '" + conti + "'";
        recContinent.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLContinent, NULL);
            CString c;
			recContinent.GetFieldValue(L"code_continent",var);
	        c=(LPCWSTR)var.pbstrVal;
		CString strSQL;
        strSQL.Format(L"SELECT * FROM Countries WHERE code_country='%s'", codec);
        recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);
        recset.Edit();
        recset.SetFieldValue(L"code_country", (LPCWSTR)codec);
        recset.SetFieldValue(L"country", (LPCWSTR)namec);
        recset.SetFieldValue(L"code_continent", (LPCWSTR)c);
        recset.Update();
		CString strSql;
       strSql.Format(L"UPDATE Countries SET country='%s' WHERE code_country='%s'", namec, codec);
       db.Execute(strSql);
        db.Close();
        RefreshList();
		AfxMessageBox(L""+namec+"'s country informations have been updated.",MB_ICONINFORMATION|MB_OK);
}


void Country::OnBnClickedrefresh()
{
	RefreshList();
	// TODO: Add your control notification handler code here
}
