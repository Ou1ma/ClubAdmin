// Language.cpp : implementation file
//

#include "stdafx.h"
#include "ClubAdmin.h"
#include "Language.h"
#include "afxdialogex.h"
#include <afxdao.h>

// Language dialog

IMPLEMENT_DYNAMIC(Language, CDialogEx)

Language::Language(CWnd* pParent /*=NULL*/)
	: CDialogEx(Language::IDD, pParent)
	, m_lcode(_T(""))
	, m_lname(_T(""))
	, m_lvi(_T(""))
	, m_lac(_T(""))
{

}

Language::~Language()
{
}

void Language::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_LA);
	DDX_Text(pDX, IDC_LA1, m_lcode);
	DDX_Text(pDX, IDC_LA2, m_lname);
	DDX_Text(pDX, IDC_LA3, m_lvi);
	DDX_Text(pDX, IDC_LA4, m_lac);
	DDX_Control(pDX, IDC_LIST3, list_SET);
}


BEGIN_MESSAGE_MAP(Language, CDialogEx)
	ON_BN_CLICKED(IDC_CANCELLA, &Language::OnBnClickedCancella)
	ON_BN_CLICKED(IDC_ADDLA, &Language::OnBnClickedAddla)
	ON_BN_CLICKED(IDC_DELETELA, &Language::OnBnClickedDeletela)
	ON_BN_CLICKED(IDC_MODIFYLA, &Language::OnBnClickedModifyla)
	ON_BN_CLICKED(IDC_SEARCHLA, &Language::OnBnClickedSearchla)
	ON_BN_CLICKED(IDC_LAlist, &Language::OnBnClickedLalist)
	ON_BN_CLICKED(IDC_VIlist, &Language::OnBnClickedVilist)
	ON_BN_CLICKED(IDC_al, &Language::OnBnClickedal)
	ON_BN_CLICKED(IDC_dl, &Language::OnBnClickeddl)
	ON_BN_CLICKED(IDC_ml, &Language::OnBnClickedml)
	ON_BN_CLICKED(IDC_sl, &Language::OnBnClickedsl)
	ON_BN_CLICKED(IDC_refresh, &Language::OnBnClickedrefresh)
END_MESSAGE_MAP()

BOOL Language::OnInitDialog()
{
    CDialogEx::OnInitDialog();

CButton* qButton = (CButton*)GetDlgItem(IDC_ADDLA);
qButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
qButton->ModifyStyle(0, BS_TOP);
qButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* rButton = (CButton*)GetDlgItem(IDC_DELETELA);
rButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
rButton->ModifyStyle(0, BS_TOP);
rButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* sButton = (CButton*)GetDlgItem(IDC_MODIFYLA);
sButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
sButton->ModifyStyle(0, BS_TOP);
sButton->SetIcon(AfxGetApp()->LoadIcon(IDI_trash));

CButton* tButton = (CButton*)GetDlgItem(IDC_SEARCHLA);
tButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
tButton->ModifyStyle(0, BS_TOP);
tButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));

CButton* uButton = (CButton*)GetDlgItem(IDC_CANCELLA);
uButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
uButton->ModifyStyle(0, BS_TOP);
uButton->SetIcon(AfxGetApp()->LoadIcon(IDI_lcancel));

CButton* auButton = (CButton*)GetDlgItem(IDC_refresh);
auButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
auButton->ModifyStyle(0, BS_TOP);
auButton->SetIcon(AfxGetApp()->LoadIcon(IDI_refresh));
//for language settings 
CButton* zaButton = (CButton*)GetDlgItem(IDC_al);
zaButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zaButton->ModifyStyle(0, BS_TOP);
zaButton->SetIcon(AfxGetApp()->LoadIcon(IDI_ADD));

CButton* zoButton = (CButton*)GetDlgItem(IDC_dl);
zoButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zoButton->ModifyStyle(0, BS_TOP);
zoButton->SetIcon(AfxGetApp()->LoadIcon(IDI_DELETE));

CButton* ziButton = (CButton*)GetDlgItem(IDC_ml);
ziButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
ziButton->ModifyStyle(0, BS_TOP);
ziButton->SetIcon(AfxGetApp()->LoadIcon(IDI_MODIFY));

CButton* zyButton = (CButton*)GetDlgItem(IDC_sl);
zyButton->ModifyStyle(BS_ICON | BS_BITMAP, 0);
zyButton->ModifyStyle(0, BS_TOP);
zyButton->SetIcon(AfxGetApp()->LoadIcon(IDI_SEARCH));


    // Add initialization code here

    // Set the icon for this dialog
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);
    SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);

		list_LA.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_LA.InsertColumn(1, L"LANGUAGE", LVCFMT_CENTER, 98, -1);
list_LA.InsertColumn(2, L"VILLAGE", LVCFMT_CENTER, 98, -1);
ListView_SetExtendedListViewStyle(list_LA, LVS_EX_GRIDLINES);
list_LA.SetBkColor(RGB(200,200,200));
//language settings
	list_SET.InsertColumn(0, L"N°", LVCFMT_CENTER, 30, -1);
list_SET.InsertColumn(1, L"CODE", LVCFMT_CENTER, 98, -1);
list_SET.InsertColumn(2, L"LANGUAGE", LVCFMT_CENTER, 98, -1);
ListView_SetExtendedListViewStyle(list_SET, LVS_EX_GRIDLINES);
list_SET.SetBkColor(RGB(200,200,200));

RefreshList();
RrefreshAsso();
    return TRUE;
}

// Language message handlers

void Language::RefreshList()
{	
	CDaoDatabase db;
    CDaoRecordset recset(&db);
       COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
        CString ids, codes, names;//end variables
        list_SET.DeleteAllItems();//clear list
       db.Open(L"GestionVillages.mdb");  
	   CString strSQL = L"SELECT * FROM Languages ";
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
   while(!recset.IsEOF())  //do until eof
      {int i=0;
       recset.GetFieldValue(L"id", var);
        ids.Format(L"%d",(LPCWSTR)var.pbstrVal);
        recset.GetFieldValue(L"code_langue",var);
	    codes=(LPCWSTR)var.pbstrVal;
       recset.GetFieldValue(L"language",var);
	    names=(LPCWSTR)var.pbstrVal;
		//recset.GetFieldValue(L"village",var);
	   // vil=(LPCWSTR)var.pbstrVal;
        list_SET.InsertItem(i,ids,0); //filling the list fields 
        list_SET.SetItemText(i,1,codes);
	    list_SET.SetItemText(i,2,names);
	    //list_LA.SetItemText(i,3,vil);
	i=i++;
	recset.MoveNext();   }
        db.Close();
}

void Language::OnBnClickedCancella()
{
	OnOK();
	// TODO: Add your control notification handler code here
}
void Language::RrefreshAsso(){
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 
	 db.Open(L"GestionVillages.mdb");  
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString N, village, langue;//end variables
    list_LA.DeleteAllItems();//clear list
	CString strSQL = L"SELECT Speak.no, Villages.village, Languages.language from" 
		L"((Speak INNER JOIN Villages ON Speak.code_V = Villages.code_village) INNER JOIN Languages ON speak.code_L = Languages.code_langue)"; 
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
   while(!recset.IsEOF())//do until eof
   {
		int i=0;
		recset.GetFieldValue(L"no", var);
		N.Format(L"%d",(LPCWSTR)var.pbstrVal);
		list_LA.InsertItem(i,N,0);
		recset.GetFieldValue(L"language",var);
		langue=(LPCWSTR)var.pbstrVal;
		list_LA.SetItemText(i,1,langue);
		recset.GetFieldValue(L"village",var);
		village=(LPCWSTR)var.pbstrVal;
		list_LA.SetItemText(i,2,village);
		i=i++;
		recset.MoveNext();   
     }
	  recset.Close();
	   db.Close();
}


void Language::OnBnClickedAddla()
{
	 CDaoDatabase db;
    CDaoRecordset recVillage(&db);
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    // TODO: Add your control notification handler code here
    CString codel, vil;
    GetDlgItemText(IDC_LA1, codel);
    //GetDlgItemText(IDC_LA2, namel);
    GetDlgItemText(IDC_LA3, vil);
    db.Open(L"GestionVillages.mdb");
	CString strSQLVillage = L"SELECT code_village FROM Villages WHERE village = '" + vil + "'";
       recVillage.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLVillage, NULL);
       CString c;
       recVillage.GetFieldValue(L"code_village",var);
       c=(LPCWSTR)var.pbstrVal;
       recset.Open(AFX_DAO_USE_DEFAULT_TYPE, L"SELECT * FROM Speak", NULL);
        recset.AddNew();
        recset.SetFieldValue(L"code_L", (LPCWSTR)codel);
        //recset.SetFieldValue(L"language", (LPCWSTR)namel);
        recset.SetFieldValue(L"code_V", (LPCWSTR)c);
        recset.Update();
        db.Close();
        RrefreshAsso();
        //m_lname = L"";
        m_lcode = L"";
        m_lvi = L"";
        UpdateData(false);
	// TODO: Add your control notification handler code here
}



/*void Language::OnBnClickedDeletela()
{
    CDaoDatabase db;
    CDaoRecordset recVillage(&db);
    CDaoRecordset recset(&db);
    COleVariant var; // Variables
    var.ChangeType(VT_BSTR, NULL);
	CString villageCode;
    // Open the database
    db.Open(L"GestionVillages.mdb");

    CString codel, vil;
    GetDlgItemText(IDC_LA1, codel);
    GetDlgItemText(IDC_LA3, vil);

    CString strSQLVillage = L"SELECT code_village FROM Villages WHERE village = '" + vil + "'";
    recVillage.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLVillage, NULL);

    // Check if there is at least one record
        recVillage.GetFieldValue(L"code_village", var);
        villageCode = (LPCWSTR)var.pbstrVal;
		recset.Open(dbOpenDynaset, L"SELECT * FROM Speak", NULL);
        // Build the SQL statement for deletion
        //CString strSQLSpeak;
        //strSQLSpeak.Format(L"SELECT * FROM Speak WHERE code_V='%s'", villageCode);
		CString strSQLSpeak = L"code_V = '" + villageCode + L"'";
         //recset.FindFirst(strSQLSpeak);
        // Execute the delete query
        //recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQLSpeak, NULL);

        // Inform the user about the deletion

if (recset.FindFirst(strSQLSpeak))
{
    do
    {
        // Delete the current record
        recset.Delete();
    } while (recset.MoveNext());  // Directly use the boolean return value

    // Refresh associated data
    RrefreshAsso();
}
       // while (!recset.IsEOF())
       // {
		//	recset.Delete();
			//RrefreshAsso();
       // }
        // Refresh associated data
		   // AfxMessageBox(L"Records have been deleted.", MB_ICONINFORMATION | MB_OK);
        //RrefreshAsso();
// Close the recordset for Speak
        recset.Close();
  
    // Close the recordset for Villages
    recVillage.Close();
    // Close the database
    db.Close();
}*/
void Language::OnBnClickedDeletela()
{
    CDaoDatabase db;
    CDaoRecordset recVillage(&db);
    CString villageCode;

    // Open the database
    db.Open(L"GestionVillages.mdb");

    CString vil;
    GetDlgItemText(IDC_LA3, vil);

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
    CString strSQLSpeak = L"DELETE FROM Speak WHERE code_V = '" + villageCode + L"'";
    db.Execute(strSQLSpeak);

    // Alternative approach using a recordset:
    // CDaoRecordset recset(&db);
    // recset.Open(dbOpenDynaset, L"Speak", NULL);
    // recset.Filter = L"code_V = '" + villageCode + L"'";
    // recset.Delete();

    // Refresh associated data (ensure RrefreshAsso handles errors)
    try {
        RrefreshAsso();
    } catch (CDaoException* e) {
        // Handle database errors
        MessageBox(L"Error refreshing data: " + e->m_pErrorInfo->m_strDescription);
    }
}

void Language::OnBnClickedModifyla()
{
CDaoDatabase db;
    CString codel, vil, villageCode;

    // Retrieve code language and village
    GetDlgItemText(IDC_LA1, codel);
    GetDlgItemText(IDC_LA3, vil);

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
    CString strSQLSpeak = L"DELETE FROM Speak WHERE code_L = '" + codel + "' AND code_V = '" + villageCode + "'";
    db.Execute(strSQLSpeak);

    // Refresh associated data (ensure RrefreshAsso handles errors)
    try {
        RrefreshAsso();
    } catch (CDaoException* e) {
        // Handle database errors
        MessageBox(L"Error refreshing data: " + e->m_pErrorInfo->m_strDescription);
    }

    // Clear UI fields and update
    m_lcode = L"";  // Clear code language field
    m_lvi = L"";    // Clear village field (assuming this is the intent)
    UpdateData(false);
}



/*void Language::OnBnClickedSearchla()
{
   
    CDaoDatabase db;
    CDaoRecordset recset(&db);

    // Open the database
    db.Open(L"GestionVillages.mdb");

    CString languageCode, villageName;
    GetDlgItemText(IDC_LA1, languageCode);
    GetDlgItemText(IDC_LA3, villageName);

    list_LA.DeleteAllItems();  // Clear the list control

    CString strSQL;
    strSQL.Format(
        L"SELECT Speak.no, Villages.village, Languages.language "
        L"FROM ((Speak INNER JOIN Villages ON Speak.code_V = Villages.code_village) "
        L"INNER JOIN Languages ON Speak.code_L = Languages.code_langue) "
        L"WHERE Languages.code_langue = '%s' AND Villages.village LIKE '%%%s%%'",
        languageCode, villageName);

    // Execute the SQL query (consider dbOpenSnapshot for read-only)
    recset.Open(dbOpenSnapshot, strSQL, NULL);

    if (!recset.IsEOF()) {
        int nIndex = 0;
        while (!recset.IsEOF()) {
            // Retrieve field values
            CString no = recset.GetFieldValue(L"no");
            CString village = recset.GetFieldValue(L"village");
            CString language = recset.GetFieldValue(L"language");

            // Insert data into the list control
            list_LA.InsertItem(nIndex, no, 0);
            list_LA.SetItemText(nIndex, 1, language);
            list_LA.SetItemText(nIndex, 2, village);

            recset.MoveNext();
            nIndex++;
        }
    } else {
        AfxMessageBox(L"No records found.");
    }

    recset.Close();
    db.Close();
}*/
void Language::OnBnClickedSearchla()
{
      CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString c, v;
    GetDlgItemText(IDC_LA1, c);
    GetDlgItemText(IDC_LA3, v);
    list_LA.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Speak.no, Villages.village, Languages.language "
                  L"FROM ((Speak INNER JOIN Villages ON Speak.code_V = Villages.code_village) "
                  L"INNER JOIN Languages ON Speak.code_L = Languages.code_langue) "
				  L"WHERE Villages.village = '%s' AND Languages.code_langue = '%s'", v, c);
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
            no.Format(L"%d", (LPCWSTR)var.pbstrVal);

            recset.GetFieldValue(L"language", var);
            CString language = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_LA.InsertItem(i, no); // Insert only once per loop
            list_LA.SetItemText(i, 1, language);
            list_LA.SetItemText(i, 2, village);

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
}



/*void Language::OnBnClickedLalist()
{
CDaoDatabase db;
    CDaoRecordset recset(&db);
    db.Open(L"GestionVillages.mdb");
	CString d, lan, vil, l;// variant
    GetDlgItemText(IDC_LA1,l);
    COleVariant var;
    var.ChangeType(VT_BSTR,NULL);
    list_LA.DeleteAllItems(); //effacer la list
    
	CString strSQL;
    strSQL.Format(L"SELECT Speak.no, Villages.village, Languages.language "
                  L"FROM ((Speak INNER JOIN Villages ON Speak.code_V = Villages.code_village) "
                  L"INNER JOIN Languages ON Speak.code_L = Languages.code_langue) "
                  L"WHERE Languages.code_langue = '%s'" ,l);

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

//recset.Open(AFX_DAO_USE_DEFAULT_TYPE,strSQL,NULL);
     while(!recset.IsEOF())  //do until eof
      {int i=0;
       recset.GetFieldValue(L"no", var);
        d.Format(L"%d",(LPCWSTR)var.pbstrVal);
        recset.GetFieldValue(L"language",var);
	    lan=(LPCWSTR)var.pbstrVal;
        recset.GetFieldValue(L"village",var);
	    vil=(LPCWSTR)var.pbstrVal;
        list_LA.InsertItem(i,d,0); //filling the list fields 
        list_LA.SetItemText(i,1,lan);
	    list_LA.SetItemText(i,2,vil);
	i=i++;
	recset.MoveNext();   }
        db.Close();
	// TODO: Add your control notification handler code here
}*/
void Language::OnBnClickedLalist()
{
    CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString c;
    GetDlgItemText(IDC_LA1, c);
    list_LA.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Speak.no, Villages.village, Languages.language "
                  L"FROM ((Speak INNER JOIN Villages ON Speak.code_V = Villages.code_village) "
                  L"INNER JOIN Languages ON Speak.code_L = Languages.code_langue) "
				  L"WHERE Languages.code_langue = '%s'", c);
                 // L"WHERE Villages.village = '" + vil + "'");

    recset.Open(AFX_DAO_USE_DEFAULT_TYPE, strSQL, NULL);

    int i = 0;
    while (!recset.IsEOF())
    {
       // CString no, language, village;
		recset.GetFieldValue(L"no", var);
            CString no;
            no.Format(L"%d", (LPCWSTR)var.pbstrVal);

            recset.GetFieldValue(L"language", var);
            CString language = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_LA.InsertItem(i, no); // Insert only once per loop
            list_LA.SetItemText(i, 1, language);
            list_LA.SetItemText(i, 2, village);

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
}



void Language::OnBnClickedVilist()
{
    CDaoDatabase db;
    CDaoRecordset recset(&db);
	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    db.Open(L"GestionVillages.mdb");
    CString vil;
    GetDlgItemText(IDC_LA3, vil);
    list_LA.DeleteAllItems(); // Clear the list
	try {
    CString strSQL;
    strSQL.Format(L"SELECT Speak.no, Villages.village, Languages.language "
                  L"FROM ((Speak INNER JOIN Villages ON Speak.code_V = Villages.code_village) "
                  L"INNER JOIN Languages ON Speak.code_L = Languages.code_langue) "
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

            recset.GetFieldValue(L"language", var);
            CString language = (LPCWSTR)var.pbstrVal;

            recset.GetFieldValue(L"village", var);
            CString village = (LPCWSTR)var.pbstrVal;

            // Insert item into list control
            list_LA.InsertItem(i, no); // Insert only once per loop
            list_LA.SetItemText(i, 1, language);
            list_LA.SetItemText(i, 2, village);

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
}

//code
//code
// refreshList is for language settings
// the coming code is for the lower section of the dialog
void Language::OnBnClickedal()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
// TODO: Add your control notification handler code here
    CString idl, codel, namel;
    GetDlgItemText(IDC_LA4,codel);
    GetDlgItemText(IDC_LA2,namel);
    db.Open(L"C://Users/DELL/Documents/Visual Studio 2010/Projects/ClubAdmin/ClubAdmin/GestionVillages.mdb");
    recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Languages",NULL);
    recset.AddNew();
    recset.SetFieldValue(L"code_langue",(LPCWSTR)codel);
    recset.SetFieldValue(L"language",(LPCWSTR)namel);
    recset.Update();
    db.Close();
    RefreshList();
    m_lname=L"";
    m_lac=L"";
    UpdateData(false);
	// TODO: Add your control notification handler code here
}



void Language::OnBnClickeddl()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
	db.Open(L"GestionVillages.mdb");
	CString codec;
	GetDlgItemText(IDC_LA4,codec);
	recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Languages WHERE code_langue='"+codec+"'");
	recset.Delete();
     RefreshList();
	// TODO: Add your control notification handler code here
}




void Language::OnBnClickedml()
{
	CDaoDatabase db;
    CDaoRecordset recset(&db);
    db.Open(L"GestionVillages.mdb");
    CString c,n;
    GetDlgItemText(IDC_LA4,c);
    GetDlgItemText(IDC_LA2,n);
    CString strSql;
    strSql.Format(L"UPDATE Languages SET language='%s' WHERE code_langue='%s'", n, c);
    db.Execute(strSql);
    RefreshList();
    AfxMessageBox(L"THE LANGUAGE "+n+" INFOS HAVE BEEN MODIFIED!",MB_ICONINFORMATION|MB_OK);
	// TODO: Add your control notification handler code here
}




void Language::OnBnClickedsl()
{
	  CDaoDatabase db;
      CDaoRecordset recset(&db);
      db.Open(L"GestionVillages.mdb");
	  CString d,c,cc;// variant
      GetDlgItemText(IDC_LA4,c);
      COleVariant var;
      var.ChangeType(VT_BSTR,NULL);
      list_SET.DeleteAllItems(); //effacer la list
      recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT * FROM Languages WHERE code_langue='"+c+"' ",NULL);
      recset.GetFieldValue(L"id",var);
      d.Format(L"%d",(LPCWSTR)var.pbstrVal);
      list_SET.InsertItem(0,d,0);
      recset.GetFieldValue(L"code_langue",var);
      c=(LPCWSTR)var.pbstrVal;
      list_SET.SetItemText(0,1,c);
      recset.GetFieldValue(L"language",var);
      cc=(LPCWSTR)var.pbstrVal;
      list_SET.SetItemText(0,2,cc);
      recset.Close();
      db.Close();
	// TODO: Add your control notification handler code here
}


void Language::OnBnClickedrefresh()
{
	RrefreshAsso();
	RefreshList();
	// TODO: Add your control notification handler code here
}
