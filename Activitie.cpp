// Activitie.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "Activitie.h"
#include "afxdialogex.h"
#include <afxdao.h>

// Activitie dialog
CString freeStatus ;
IMPLEMENT_DYNAMIC(Activitie, CDialogEx)

Activitie::Activitie(CWnd* pParent /*=NULL*/)
	: CDialogEx(Activitie::IDD, pParent)
	, m_free(0)
	, m_acode(_T(""))
	, m_aname(_T(""))
	, m_avi(_T(""))
	, m_ca(_T(""))

{

}

Activitie::~Activitie()
{
}

void Activitie::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_AC);
	//DDX_Radio(pDX, IDC_RADIO1, m_free);
	DDX_Text(pDX, IDC_AC1, m_acode);
	DDX_Text(pDX, IDC_AC2, m_aname);
	DDX_Text(pDX, IDC_AC4, m_avi);
	DDX_Text(pDX, IDC_AC5, m_ca);
	DDX_Control(pDX, IDC_LIST2, list_SETT);
}


BEGIN_MESSAGE_MAP(Activitie, CDialogEx)
	ON_BN_CLICKED(IDC_DELETEAC, &Activitie::OnBnClickedDeleteac)
	ON_BN_CLICKED(IDC_CANCELAC, &Activitie::OnBnClickedCancelac)
	ON_BN_CLICKED(IDC_SEARCHAC, &Activitie::OnBnClickedSearchac)
	ON_BN_CLICKED(IDC_ADDAC, &Activitie::OnBnClickedAddac)
	ON_BN_CLICKED(IDC_MODIFYAC, &Activitie::OnBnClickedModifyac)
	ON_BN_CLICKED(IDC_BUTTON1, &Activitie::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_listbyvill, &Activitie::OnBnClickedlistbyvill)
	ON_BN_CLICKED(IDC_RADIO1, &Activitie::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Activitie::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_aa, &Activitie::OnBnClickedaa)
	ON_BN_CLICKED(IDC_da, &Activitie::OnBnClickedda)
	ON_BN_CLICKED(IDC_ma, &Activitie::OnBnClickedma)
	ON_BN_CLICKED(IDC_sa, &Activitie::OnBnClickedsa)
	ON_BN_CLICKED(IDC_REF, &Activitie::OnBnClickedRef)
	ON_BN_CLICKED(IDC_faa, &Activitie::OnBnClickedfaa)
	ON_BN_CLICKED(IDC_paa, &Activitie::OnBnClickedpaa)
END_MESSAGE_MAP()

BOOL Activitie::OnInitDialog()
{
    CDialogEx::OnInitDialog();

CButton* vButton = (CButton*)GetDlgItem(IDC_ADDAC);
vButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
vButton->ModifyStyle(0, BS_TOP);
vButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* wButton = (CButton*)GetDlgItem(IDC_DELETEAC);
wButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
wButton->ModifyStyle(0, BS_TOP);
wButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* xButton = (CButton*)GetDlgItem(IDC_MODIFYAC);
xButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
xButton->ModifyStyle(0, BS_TOP);
xButton->SetIcon(AfxGetApp()->LoadIcon(IDI_trash));

CButton* yButton = (CButton*)GetDlgItem(IDC_SEARCHAC);
yButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
yButton->ModifyStyle(0, BS_TOP);
yButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));

CButton* zButton = (CButton*)GetDlgItem(IDC_CANCELAC);
zButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zButton->ModifyStyle(0, BS_TOP);
zButton->SetIcon(AfxGetApp()->LoadIcon(IDI_lcancel));

CButton* zuuButton = (CButton*)GetDlgItem(IDC_REF);
zuuButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zuuButton->ModifyStyle(0, BS_TOP);
zuuButton->SetIcon(AfxGetApp()->LoadIcon(IDI_refresh));


//activities settings buttons
CButton* zuuuButton = (CButton*)GetDlgItem(IDC_aa);
zuuuButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zuuuButton->ModifyStyle(0, BS_TOP);
zuuuButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* zuuuuButton = (CButton*)GetDlgItem(IDC_da);
zuuuuButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zuuuuButton->ModifyStyle(0, BS_TOP);
zuuuuButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* zuuiButton = (CButton*)GetDlgItem(IDC_ma);
zuuiButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zuuiButton->ModifyStyle(0, BS_TOP);
zuuiButton->SetIcon(AfxGetApp()->LoadIcon(IDI_MODIFY));

CButton* zuuaButton = (CButton*)GetDlgItem(IDC_sa);
zuuaButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zuuaButton->ModifyStyle(0, BS_TOP);
zuuaButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));

//free activities and paid once buttons

CButton* zavButton = (CButton*)GetDlgItem(IDC_faa);
zavButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zavButton->ModifyStyle(0, BS_TOP);
zavButton->SetIcon(AfxGetApp()->LoadIcon(IDI_faa));

CButton* zavvButton = (CButton*)GetDlgItem(IDC_paa);
zavvButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zavvButton->ModifyStyle(0, BS_TOP);
zavvButton->SetIcon(AfxGetApp()->LoadIcon(IDI_money));



    // Add initialization code here

    // Set the icon for this dialog
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);

	list_AC.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_AC.InsertColumn(1, L"ACTIVITY", LVCFMT_CENTER, 100, -1);
list_AC.InsertColumn(2, L"VILLAGE", LVCFMT_CENTER, 100, -1);
list_AC.InsertColumn(3, L"PAYMENT STATUS", LVCFMT_CENTER, 100, -1);
ListView_SetExtendedListViewStyle(list_AC, LVS_EX_GRIDLINES);
list_AC.SetBkColor(RGB(200,200,200));

list_SETT.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_SETT.InsertColumn(1, L"CODE", LVCFMT_CENTER, 98, -1);
list_SETT.InsertColumn(2, L"ACTIVITY", LVCFMT_CENTER, 98, -1);
ListView_SetExtendedListViewStyle(list_SETT, LVS_EX_GRIDLINES);
list_SETT.SetBkColor(RGB(200,200,200));

//HWND parentWnd = GetParent()->GetSafeHwnd(); // Assuming parent contains radio buttons
//::SendMessage(::GetDlgItem(parentWnd, IDC_RADIO1), BM_SETCHECK, BST_UNCHECKED, 0);
RefreshAssoc();
RefreshList();
    return TRUE;
}
void Activitie::RefreshList()
{	
     CDaoDatabase db;
    CDaoRecordset recset(&db);
       COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
        CString ids, codes, names;//end variables
        list_SETT.DeleteAllItems();//clear list
       db.Open(L"GestionVillages.mdb");  
	   CString strSQL = L"SELECT * FROM Activities ";
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
   while(!recset.IsEOF())  //do until eof
      {int i=0;
       recset.GetFieldValue(L"id", var);
        ids.Format(L"%d",(LPCWSTR)var.pbstrVal);
        recset.GetFieldValue(L"code_activity",var);
	    codes=(LPCWSTR)var.pbstrVal;
       recset.GetFieldValue(L"activity",var);
	    names=(LPCWSTR)var.pbstrVal;
		//recset.GetFieldValue(L"village",var);
	   // vil=(LPCWSTR)var.pbstrVal;
        list_SETT.InsertItem(i,ids,0); //filling the list fields 
        list_SETT.SetItemText(i,1,codes);
	    list_SETT.SetItemText(i,2,names);
	    //list_LA.SetItemText(i,3,vil);
	i=i++;
	recset.MoveNext();   }
        db.Close();
}

// Activitie message handlers
void Activitie::RefreshAssoc()
{
		CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 
	 db.Open(L"GestionVillages.mdb");  
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString N, village, activity, f;//end variables
    list_AC.DeleteAllItems();//clear list
	GetDlgItem(IDC_RADIO1)->SendMessage(BM_SETCHECK, BST_UNCHECKED, 0);
GetDlgItem(IDC_RADIO2)->SendMessage(BM_SETCHECK, BST_UNCHECKED, 0);
	CString strSQL = L"SELECT Offer.no, Offer.free_status, Villages.village, Activities.activity from" 
		L"((Offer INNER JOIN Villages ON Offer.code_V = Villages.code_village) INNER JOIN Activities ON Offer.code_A = Activities.code_activity)"; 
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
   while(!recset.IsEOF())//do until eof
   {
		int i=0;
		recset.GetFieldValue(L"no", var);
		N.Format(L"%d",(LPCWSTR)var.pbstrVal);
		list_AC.InsertItem(i,N,0);
		recset.GetFieldValue(L"activity",var);
		activity=(LPCWSTR)var.pbstrVal;
		list_AC.SetItemText(i,1,activity);
		recset.GetFieldValue(L"village",var);
		village=(LPCWSTR)var.pbstrVal;
		list_AC.SetItemText(i,2,village);
		recset.GetFieldValue(L"free_status",var);
		f=(LPCWSTR)var.pbstrVal;
		list_AC.SetItemText(i,3,f);
		i=i++;
		recset.MoveNext();   
     }
	  recset.Close();
	   db.Close();
}

void Activitie::OnBnClickedDeleteac()
{
	  CDaoDatabase db;
    CDaoRecordset recVillage(&db);
    CString villageCode;

    // Open the database
    db.Open(L"GestionVillages.mdb");

    CString vil;
    GetDlgItemText(IDC_AC4, vil);

    // Retrieve village code
    CString strSQLVillage = L"SELECT code_village FROM Villages WHERE village = '" + vil + "'";
    recVillage.Open(dbOpenDynaset, strSQLVillage, NULL);
    if (!recVillage.IsEOF()) {
        villageCode = recVillage.GetFieldValue(L"code_village");
    } else {
        // Handle village not found
        MessageBox(L"Village not found.");
        return;
    }

    // Delete associated records efficiently (preferred approach)
    CString strSQLSpeak = L"DELETE FROM Offer WHERE code_V = '" + villageCode + L"'";
    db.Execute(strSQLSpeak);

    // Alternative approach using a recordset:
    // CDaoRecordset recset(&db);
    // recset.Open(dbOpenDynaset, L"Speak", NULL);
    // recset.Filter = L"code_V = '" + villageCode + L"'";
    // recset.Delete();

    // Refresh associated data (ensure RrefreshAsso handles errors)
    try {
        RefreshAssoc();
    } catch (CDaoException* e) {
        // Handle database errors
        MessageBox(L"Error refreshing data: " + e->m_pErrorInfo->m_strDescription);
    }
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedCancelac()
{
	OnOK();
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedSearchac()
{
	 CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString c, v;
    GetDlgItemText(IDC_AC5, c);
    GetDlgItemText(IDC_AC4, v);
    list_AC.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Offer.no, Offer.free_status, Villages.village, Activities.Activity "
                  L"FROM ((Offer INNER JOIN Villages ON Offer.code_V = Villages.code_village) "
                  L"INNER JOIN Activities ON Offer.code_A = Activities.code_activity) "
				  L"WHERE Villages.village = '%s' AND Activities.code_activity = '%s'", v, c);
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
            no.Format(L"%d", (LPCWSTR)var.pbstrVal);

            recset.GetFieldValue(L"activity", var);
            CString activite = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

			recset.GetFieldValue(L"free_status", var);
            CString stato = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_AC.InsertItem(i, no); // Insert only once per loop
            list_AC.SetItemText(i, 1, activite);
            list_AC.SetItemText(i, 2, village);
			list_AC.SetItemText(i, 3, stato);

        i++;
        recset.MoveNext();
    }

	db.Close();}
 // Your existing code here
catch (CDaoException* e)
{
    e->ReportError();
    e->Delete();
}
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedAddac()
{
   CDaoDatabase db;
    CDaoRecordset recVillage(&db);
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    // TODO: Add your control notification handler code here
    CString codel, vil;
    GetDlgItemText(IDC_AC5, codel);
    //GetDlgItemText(IDC_LA2, namel);
    GetDlgItemText(IDC_AC4, vil);
    db.Open(L"GestionVillages.mdb");
	CString strSQLVillage = L"SELECT code_village FROM Villages WHERE village = '" + vil + "'";
       recVillage.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLVillage, NULL);
       CString c;
       recVillage.GetFieldValue(L"code_village",var);
       c=(LPCWSTR)var.pbstrVal;
       recset.Open(AFX_DAO_USE_DEFAULT_TYPE, L"SELECT * FROM Offer", NULL);
        recset.AddNew();
        recset.SetFieldValue(L"code_A", (LPCWSTR)codel);
        //recset.SetFieldValue(L"language", (LPCWSTR)namel);
        recset.SetFieldValue(L"code_V", (LPCWSTR)c);
		recset.SetFieldValue(L"free_status", (LPCWSTR)freeStatus);
        recset.Update();
        db.Close();
        RefreshAssoc();
        //m_lname = L"";
        m_ca = L"";
        m_avi = L"";
        UpdateData(false);
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedModifyac()
{
	CDaoDatabase db;
    CString codel, vil, villageCode;

    // Retrieve code language and village
    GetDlgItemText(IDC_AC5, codel);
    GetDlgItemText(IDC_AC4, vil);

    // Open the database
    db.Open(L"GestionVillages.mdb");

    // Retrieve village code efficiently
    CString strSQLVillage = L"SELECT code_village FROM Villages WHERE village = '" + vil + "'";
    CDaoRecordset recVillage(&db);
    recVillage.Open(dbOpenDynaset, strSQLVillage, NULL);
    if (!recVillage.IsEOF()) {
        villageCode = recVillage.GetFieldValue(L"code_village");
    } else {
        // Handle village not found
        MessageBox(L"Village not found.");
        return;
    }

    // Delete single record efficiently
    CString strSQLSpeak = L"DELETE FROM Offer WHERE code_A = '" + codel + "' AND code_V = '" + villageCode + "'";
    db.Execute(strSQLSpeak);

    // Refresh associated data (ensure RrefreshAsso handles errors)
    try {
        RefreshAssoc();
    } catch (CDaoException* e) {
        // Handle database errors
        MessageBox(L"Error refreshing data: " + e->m_pErrorInfo->m_strDescription);
    }

    // Clear UI fields and update
    m_ca = L"";  // Clear code language field
    m_avi = L"";    // Clear village field (assuming this is the intent)
    UpdateData(false);
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedButton1()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString c;
    GetDlgItemText(IDC_AC5, c);
    list_AC.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Offer.no, Offer.free_status, Villages.village, Activities.activity "
                  L"FROM ((Offer INNER JOIN Villages ON Offer.code_V = Villages.code_village) "
                  L"INNER JOIN Activities ON Offer.code_A = Activities.code_activity) "
				  L"WHERE Activities.code_activity = '%s'", c);
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
          no.Format(L"%d", (LPCWSTR)var.pbstrVal);

            recset.GetFieldValue(L"activity", var);
            CString activite = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

			recset.GetFieldValue(L"free_status", var);
            CString stato = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_AC.InsertItem(i, no); // Insert only once per loop
            list_AC.SetItemText(i, 1, activite);
            list_AC.SetItemText(i, 2, village);
			list_AC.SetItemText(i, 3, stato);

        i++;
        recset.MoveNext();
    }

	db.Close();}
 // Your existing code here
catch (CDaoException* e)
{
    e->ReportError();
    e->Delete();
}
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedlistbyvill()
{
    CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString vil;
    GetDlgItemText(IDC_AC4, vil);
    list_AC.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Offer.no, Offer.free_status, Villages.village, Activities.activity "
                  L"FROM ((Offer INNER JOIN Villages ON Offer.code_V = Villages.code_village) "
                  L"INNER JOIN Activities ON Offer.code_A = Activities.code_activity) "
				  L"WHERE Villages.village = '%s'", vil);
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
            no.Format(L"%d", (LPCWSTR)var.pbstrVal);
            recset.GetFieldValue(L"activity", var);
            CString activite = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

			recset.GetFieldValue(L"free_status", var);
            CString stato = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_AC.InsertItem(i, no); // Insert only once per loop
            list_AC.SetItemText(i, 1, activite);
            list_AC.SetItemText(i, 2, village);
			list_AC.SetItemText(i, 3, stato);

        i++;
        recset.MoveNext();
    }

	db.Close();}
 // Your existing code here
catch (CDaoException* e)
{
    e->ReportError();
    e->Delete();
}
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedRadio1()
{
	freeStatus="free";
	// TODO: Add your control notification handler code here
}



void Activitie::OnBnClickedRadio2()
{
	freeStatus="paid";
	// TODO: Add your control notification handler code here
}
//code for activities settings

void Activitie::OnBnClickedaa()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
// TODO: Add your control notification handler code here
    CString id, code, name;
    GetDlgItemText(IDC_AC1,code);
    GetDlgItemText(IDC_AC2,name);
    db.Open(L"C://Users/DELL/Documents/Visual Studio 2010/Projects/ClubAdmin/ClubAdmin/GestionVillages.mdb");
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Activities",NULL);
    recset.AddNew();
    recset.SetFieldValue(L"code_activity",(LPCWSTR)code);
    recset.SetFieldValue(L"activity",(LPCWSTR)name);
    recset.Update();
    db.Close();
    RefreshList();
    m_aname=L"";
    m_acode=L"";
    UpdateData(false);
	// TODO: Add your control notification handler code here
}

void Activitie::OnBnClickedda()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	db.Open(L"GestionVillages.mdb");
	CString codec;
	GetDlgItemText(IDC_AC1,codec);
	recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Activities WHERE code_Activity='"+codec+"'");
	recset.Delete();
     RefreshList();
	// TODO: Add your control notification handler code here
}

void Activitie::OnBnClickedma()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
    db.Open(L"GestionVillages.mdb");
    CString c,n;
    GetDlgItemText(IDC_AC1,c);
    GetDlgItemText(IDC_AC2,n);
    CString strSql;
    strSql.Format(L"UPDATE Activities SET activity='%s' WHERE code_activity='%s'", n, c);
    db.Execute(strSql);
    RefreshList();
    AfxMessageBox(L"THE ACTIVITY "+n+" INFOS HAVE BEEN MODIFIED!",MB_ICONINFORMATION|MB_OK);
	// TODO: Add your control notification handler code here
}



void Activitie::OnBnClickedsa()
{
	 CDaoDatabase db;
      CDaoRecordset recset(&db);
      db.Open(L"GestionVillages.mdb");
	  CString d,c,cc;// variant
      GetDlgItemText(IDC_AC1,c);
      COleVariant var;
      var.ChangeType(VT_BSTR,NULL);
      list_SETT.DeleteAllItems(); //effacer la list
      recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Activities WHERE code_activity='"+c+"' ",NULL);
      recset.GetFieldValue(L"id",var);
      d.Format(L"%d",(LPCWSTR)var.pbstrVal);
      list_SETT.InsertItem(0,d,0);
      recset.GetFieldValue(L"code_activity",var);
      c=(LPCWSTR)var.pbstrVal;
      list_SETT.SetItemText(0,1,c);
      recset.GetFieldValue(L"activity",var);
      cc=(LPCWSTR)var.pbstrVal;
      list_SETT.SetItemText(0,2,cc);
      recset.Close();
      db.Close();
	// TODO: Add your control notification handler code here
}



void Activitie::OnBnClickedRef()
{
	RefreshAssoc();
	RefreshList();
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedfaa()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString vil;
    //GetDlgItemText(IDC_AC4, vil);
    list_AC.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Offer.no, Offer.free_status, Villages.village, Activities.activity "
                  L"FROM ((Offer INNER JOIN Villages ON Offer.code_V = Villages.code_village) "
                  L"INNER JOIN Activities ON Offer.code_A = Activities.code_activity) "
				  L"WHERE Offer.free_status = 'free'");
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
            no.Format(L"%d", (LPCWSTR)var.pbstrVal);
            recset.GetFieldValue(L"activity", var);
            CString activite = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

			recset.GetFieldValue(L"free_status", var);
            CString stato = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_AC.InsertItem(i, no); // Insert only once per loop
            list_AC.SetItemText(i, 1, activite);
            list_AC.SetItemText(i, 2, village);
			list_AC.SetItemText(i, 3, stato);

        i++;
        recset.MoveNext();
    }

	db.Close();}
 // Your existing code here
catch (CDaoException* e)
{
    e->ReportError();
    e->Delete();
}
	// TODO: Add your control notification handler code here
}


void Activitie::OnBnClickedpaa()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString vil;
    //GetDlgItemText(IDC_AC4, vil);
    list_AC.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Offer.no, Offer.free_status, Villages.village, Activities.activity "
                  L"FROM ((Offer INNER JOIN Villages ON Offer.code_V = Villages.code_village) "
                  L"INNER JOIN Activities ON Offer.code_A = Activities.code_activity) "
				  L"WHERE Offer.free_status = 'paid'");
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
            no.Format(L"%d", (LPCWSTR)var.pbstrVal);
            recset.GetFieldValue(L"activity", var);
            CString activite = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

			recset.GetFieldValue(L"free_status", var);
            CString stato = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_AC.InsertItem(i, no); // Insert only once per loop
            list_AC.SetItemText(i, 1, activite);
            list_AC.SetItemText(i, 2, village);
			list_AC.SetItemText(i, 3, stato);

        i++;
        recset.MoveNext();
    }

	db.Close();}
 // Your existing code here
catch (CDaoException* e)
{
    e->ReportError();
    e->Delete();
}

	// TODO: Add your control notification handler code here
}
