// Village.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "Village.h"
#include "afxdialogex.h"


// Village dialog

IMPLEMENT_DYNAMIC(Village, CDialogEx)

Village::Village(CWnd* pParent /*=NULL*/)
	: CDialogEx(Village::IDD, pParent)
	, m_vcode(_T(""))
	, m_vname(_T(""))
	, m_vco(_T(""))
{

}

Village::~Village()
{
}

void Village::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_VI);
	DDX_Text(pDX, IDC_VI1, m_vcode);
	DDX_Text(pDX, IDC_VI2, m_vname);
	DDX_Text(pDX, IDC_VI3, m_vco);
}


BEGIN_MESSAGE_MAP(Village, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Village::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_ADDVI, &Village::OnBnClickedAddvi)
	ON_BN_CLICKED(IDC_DELETEVI, &Village::OnBnClickedDeletevi)
	ON_BN_CLICKED(IDC_MODIFYVI, &Village::OnBnClickedModifyvi)
	ON_BN_CLICKED(IDC_SEARCHVI, &Village::OnBnClickedSearchvi)
	ON_BN_CLICKED(IDC_CANCELVI, &Village::OnBnClickedCancelvi)
	ON_BN_CLICKED(IDC_refresh, &Village::OnBnClickedrefresh)
END_MESSAGE_MAP()

// Village message handlers
BOOL Village::OnInitDialog()
{
    CDialogEx::OnInitDialog();

CButton* lButton = (CButton*)GetDlgItem(IDC_ADDVI);
lButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
lButton->ModifyStyle(0, BS_TOP);
lButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* mButton = (CButton*)GetDlgItem(IDC_DELETEVI);
mButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
mButton->ModifyStyle(0, BS_TOP);
mButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* nButton = (CButton*)GetDlgItem(IDC_MODIFYVI);
nButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
nButton->ModifyStyle(0, BS_TOP);
nButton->SetIcon(AfxGetApp()->LoadIcon(IDI_MODIFY));

CButton* oButton = (CButton*)GetDlgItem(IDC_SEARCHVI);
oButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
oButton->ModifyStyle(0, BS_TOP);
oButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));

CButton* pButton = (CButton*)GetDlgItem(IDC_CANCELVI);
pButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
pButton->ModifyStyle(0, BS_TOP);
pButton->SetIcon(AfxGetApp()->LoadIcon(IDI_lcancel));

CButton* apButton = (CButton*)GetDlgItem(IDC_refresh);
apButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
apButton->ModifyStyle(0, BS_TOP);
apButton->SetIcon(AfxGetApp()->LoadIcon(IDI_refresh));


    // Add initialization code here

    // Set the icon for this dialog
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);

	list_VI.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_VI.InsertColumn(1, L"CODE", LVCFMT_CENTER, 109, -1);
list_VI.InsertColumn(2, L"VILLAGE", LVCFMT_CENTER, 109, -1);
list_VI.InsertColumn(3, L"COUNTRY", LVCFMT_CENTER, 109, -1);
ListView_SetExtendedListViewStyle(list_VI, LVS_EX_GRIDLINES);
list_VI.SetBkColor(RGB(200,200,200));
RefreshList();
    return TRUE;
}
void Village::RefreshList()
{	
    CDaoRecordset recset(&db);
    COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
        CString idv, codev, namev, cou;//end variables
        list_VI.DeleteAllItems();//clear list
       db.Open(L"GestionVillages.mdb");  
	   CString strSQL = L"SELECT Villages.id, Villages.code_village, Villages.village, Countries.country "
                  L"FROM Villages INNER JOIN Countries ON Villages.code_country = countries.code_country";
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
   while(!recset.IsEOF())  //do until eof
  {int i=0;
       recset.GetFieldValue(L"id", var);
        idv.Format(L"%d",(LPCWSTR)var.pbstrVal);
        recset.GetFieldValue(L"code_village",var);
	    codev=(LPCWSTR)var.pbstrVal;
       recset.GetFieldValue(L"village",var);
	    namev=(LPCWSTR)var.pbstrVal;
		recset.GetFieldValue(L"country",var);
	    cou=(LPCWSTR)var.pbstrVal;
        list_VI.InsertItem(i,idv,0); //filling the list fields 
       list_VI.SetItemText(i,1,codev);
	   list_VI.SetItemText(i,2,namev);
	   list_VI.SetItemText(i,3,cou);
	   i=i++;
	   recset.MoveNext();   }
       recset.Close();
       db.Close();
}



void Village::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}


void Village::OnBnClickedAddvi()
{
	CDaoRecordset recset(&db);
	CDaoRecordset recCountry(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    // TODO: Add your control notification handler code here
    CString codeV, nameV, coV;
    GetDlgItemText(IDC_VI1, codeV);
    GetDlgItemText(IDC_VI2, nameV);
    GetDlgItemText(IDC_VI3, coV);
    db.Open(L"GestionVillages.mdb");
	CString strSQLCountry = L"SELECT code_country FROM Countries WHERE country = '" + coV + "'";
        recCountry.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLCountry, NULL);
            CString c;
			recCountry.GetFieldValue(L"code_country",var);
	        c=(LPCWSTR)var.pbstrVal;
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE, L"SELECT * FROM Villages", NULL);
        recset.AddNew();
        recset.SetFieldValue(L"code_village", (LPCWSTR)codeV);
        recset.SetFieldValue(L"village", (LPCWSTR)nameV);
        recset.SetFieldValue(L"code_country", (LPCWSTR)c);
        recset.Update();
        db.Close();
        RefreshList();
        m_vname = L"";
        m_vcode = L"";
        m_vco = L"";
        UpdateData(false);

	// TODO: Add your control notification handler code here
}


void Village::OnBnClickedDeletevi()
{
	CDaoRecordset recset(&db);
	db.Open(L"GestionVillages.mdb");
	CString codev;
	GetDlgItemText(IDC_VI1,codev);
	recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Villages WHERE code_village='"+codev+"'");
	recset.Delete();
    RefreshList();
	//AfxMessageBox(L""+namev+"'s country informations has been updated.",MB_ICONINFORMATION|MB_OK);
	// TODO: Add your control notification handler code here
}



void Village::OnBnClickedModifyvi()
{
	CDaoRecordset recCountries(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);

    // TODO: Add your control notification handler code here
    CString codev, namev, coun;
    GetDlgItemText(IDC_Cy1, codev);
    GetDlgItemText(IDC_CY2, namev);
    GetDlgItemText(IDC_CY3, coun);
	db.Open(L"GestionVillages.mdb");
	// TODO: Add your control notification handler code here
	CString strSQLCountry = L"SELECT code_country FROM Countries WHERE country = '" + coun + "'";
        recCountries.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLCountry, NULL);
            CString c;
			recCountries.GetFieldValue(L"code_country",var);
	        c=(LPCWSTR)var.pbstrVal;
		CString strSQL;
        strSQL.Format(L"SELECT * FROM Villages WHERE code_village='%s'", codev);
        recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);
        recset.Edit();
        recset.SetFieldValue(L"code_village", (LPCWSTR)codev);
        recset.SetFieldValue(L"village", (LPCWSTR)namev);
        recset.SetFieldValue(L"code_country", (LPCWSTR)c);
        recset.Update();
        db.Close();
        RefreshList();
		AfxMessageBox(L""+namev+"'s village informations have been updated.",MB_ICONINFORMATION|MB_OK);
	// TODO: Add your control notification handler code here
}


void Village::OnBnClickedSearchvi()
{
	CDaoRecordset recset(&db);
	db.Open(L"GestionVillages.mdb");
	CString d, code, name, co, c;// variant
    GetDlgItemText(IDC_VI1,c);
    COleVariant var;
    var.ChangeType(VT_BSTR,NULL);
    list_VI.DeleteAllItems(); //effacer la list
    CString strSQL;
    strSQL.Format(L"SELECT Villages.id, Villages.code_village, Villages.village, Countries.country "
              L"FROM Villages INNER JOIN Countries ON Villages.code_country = Countries.code_country "
              L"WHERE Villages.code_village='%s'", c);

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
    recset.GetFieldValue(L"id",var);
    d.Format(L"%d",(LPCWSTR)var.pbstrVal);
    list_VI.InsertItem(0,d,0);
    recset.GetFieldValue(L"code_village",var);
    code=(LPCWSTR)var.pbstrVal;
    list_VI.SetItemText(0,1,code);
    recset.GetFieldValue(L"village",var);
    name=(LPCWSTR)var.pbstrVal;
    list_VI.SetItemText(0,2,name);
    recset.GetFieldValue(L"country",var);
    co=(LPCWSTR)var.pbstrVal;
    list_VI.SetItemText(0,3,co);
    recset.Close();
    db.Close();
	// TODO: Add your control notification handler code here
}


void Village::OnBnClickedCancelvi()
{
	OnOK();
	// TODO: Add your control notification handler code here
}


void Village::OnBnClickedrefresh()
{
	RefreshList();
	// TODO: Add your control notification handler code here
}
