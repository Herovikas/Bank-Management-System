#include <iostream>
#include<windows.h>
#include<mysql.h>
#include <sstream>
#include<stdio.h>

using namespace std;

//***************************************************************
//    	Class declaration
//****************************************************************
class account
{
private:
    int acno;
    char name[20];
    int amount;

public:
    void Org_login();
    void Emp_login();
};



//***************************************************************
//    	function declaration
//****************************************************************
void Org_login();
void Emp_login();
void intro();


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
{
   char ch;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tWELCOME TO MAIN MENU";
		cout<<"\n\n\t01. ORGANISATIONAL LOGIN";
		cout<<"\n\n\t02. EMPLOYEE LOGIN";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tSelect Your Option (1-3) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
        case '1':
			Org_login();
			break;
        case '2':
			Emp_login();
			break;
        case '3':
			cout<<"\n\n\tThanks for using Bank Management System\n\n\t\t  Have a Cheerful Day";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='3');
	return 0;
}





 //***************************************************************
//    	ORGANISATION LOGIN FUNCTION
//****************************************************************



void Org_login()
{
    MYSQL* conn;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
        char uid[20],pass[20];
        int qstate = 0;
        cout<<"\n\n  Please Login to the Organisation"<<endl;
        cout<<"\n\n\tLogin_id: ";
        cin>>uid;
        cout<<"\n\n\tPassword: ";
        cin>>pass;
        stringstream ss;
        ss<< "SELECT * FROM org WHERE username = '" << uid << "' and userpass = '" << pass << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
     if(!qstate){
            res = mysql_store_result(conn);
            int count1 = mysql_num_rows(res);
            if (count1 == 1){
                cout<<"\n\n\tLogin Successful\n\n"<<endl;
                system("pause");

{char ch;
intro();
while (ch!='4') {
    system("cls");
    cout<<"\n\n\n\tWELCOME TO ORGANISATIONAL INFO";
    cout<<"\n\n\t01. CREATE EMPLOYEE ACCOUNT";
    cout<<"\n\n\t02. ALL EMPLOYEE LIST";
    cout<<"\n\n\t03. DELETE AN ACCOUNT";
    cout<<"\n\n\t04. LOG-OUT";
    cout<<"\n\n\tSelect Your Option (1-4) ";
    cin>>ch;
    system("cls");
    switch(ch)
    {
    case '1':
{
    int acno;
	char name[30];
	int deposit;
    char pass[20];
    string dummy;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
    int qstate = 0;
    cout<<"\n\n  CREATE NEW ACCOUNT FOR EMPLOYEE"<<endl;
    cout<<"\nEnter The account No. : ";
    cin>>acno;
	cout<<"\n\nEnter User Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,30);
    cout<<"\nCreate a new Password: ";
	cin>>pass;
    cout<<"\nEnter The Initial amount: ";
	cin>>deposit;
	stringstream ss;
	ss << "INSERT INTO bank(accno, uname, pass, amounts) VALUES(" << acno << ",'" << name << "','" << pass << "'," << deposit <<")";
	string query = ss.str();
         const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "\n\n\tAccount created...\n\n" << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "\n\n\n\n Press B to go back";
            cin >> dummy;
        }
    }else{
        cout << "Connection Error" << endl;
        cout << "\n\n\n\n Press B to go back";
        cin >> dummy;
    }
    system("pause");
    system("cls");
}
        break;
    case '2':
{   MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
            cout<<"\n\n\tLISTING ALL THE DETAILS :"<<endl;
    int qstate = mysql_query(conn, "SELECT accno, uname, pass, amounts FROM BANK");
if(!qstate){
            res = mysql_store_result(conn);
            cout <<"Acc NO."<<"\t | \t" << "Uname"<<"\t | \t" <<"Pass"<<"\t | \t" <<"Balance"<< endl << endl;
            while ( row = mysql_fetch_row(res) )
            {
                cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
            }
        }
    }
    system("pause");

}   break;

    case '3':
{
    MYSQL* conn;
    MYSQL_RES* res1;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
        int acno;
        int qstate = 0;
        int qstate1 = 0;
        cout<<"\n\n\tENTER ACCOUNT NO. TO DELETE : ";
        cin>>acno;
        stringstream ss;
        ss << "SELECT * FROM bank WHERE accno = " << acno << "";
        stringstream ss1;
        ss1 << "DELETE FROM bank WHERE accno = " << acno << "";
        string query1 = ss1.str();
        const char* r = query1.c_str();
        qstate1 = mysql_query(conn, r);
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
                res1 = mysql_store_result(conn);
                int countt = mysql_num_rows(res1);
                if (countt == 1){
                    cout<<"\n\n\tACCOUNT DELETED\n\tSorry to see you GO\n\n"<<endl;
                }
                else{
                    cout<<"\n\n\tACCOUNT NO. NOT FOUND\n\n"<<endl;
                }

}
else{
    cout<<"Unable to get record"<<endl;
}
    }
system("pause");
}

        break;
    case '4':
        cout<<"\n\n\tThank you and have a cheerful day ";
        break;
    }
                }
}



     }
            else{
                cout<<"\n  Login_id or Password wrong\n\tTry Again";
            }}
else{cout << "Insert Error" << mysql_error(conn) << endl;}}

else{cout<<"\n\tDatabase not Connected";}
}





 //***************************************************************
//    	EMPLOYEE LOGIN FUNCTION
//****************************************************************


void Emp_login()
{
    string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
        char uid[20],pass[20];
        int qstate = 0;
        cout<<"\n\n  Hi, Please Login Here"<<endl;
        cout<<"\n\n\tLogin_id: ";
        cin>>uid;
        cout<<"\n\n\tPassword: ";
        cin>>pass;
        stringstream ss;
        ss<< "SELECT * FROM bank WHERE uname = '" << uid << "' and pass = '" << pass << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
     if(!qstate){
            res = mysql_store_result(conn);
            int countt = mysql_num_rows(res);
            if (countt == 1){
                cout<<"\n\n\tLogin Successful\n\n"<<endl;
                system("pause");
{char ch;
intro();
while (ch!='6') {
    system("cls");
    cout<<"\n\n\n\tWELCOME TO OUR BANK INFO";
    cout<<"\n\n\t01. MODIFY ACCOUNT";
    cout<<"\n\n\t02. BALANCE ENQUIRY";
    cout<<"\n\n\t03. DEPOSITE MONEY";
    cout<<"\n\n\t04. WITHDRAW MONEY";
    cout<<"\n\n\t05. TRANSACTION";
    cout<<"\n\n\t06. LOG-OUT";
    cout<<"\n\n\tSelect Your Option (1-6) ";
    cin>>ch;
    system("cls");
    switch(ch)
    {
    case '1':
{   char nuid[20],npass[20];
    MYSQL* conn;
    MYSQL_RES* res0;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
    int qstate = 0;
    int qstate1 = 0;
    cout<<"\n\n\t MODIFY YOUR ACCOUNT  "<<endl;

    stringstream ss0;
    ss0 << "SELECT accno FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
    string query0 = ss0.str();
    const char* a = query0.c_str();
    int qstate0 = mysql_query(conn, a);
    if(qstate0 == 0){
    res0 = mysql_store_result(conn);
    while(row = mysql_fetch_row(res0)){
    cout << "\n\n\tACCOUNT NO. :  "<< row[0] << endl << endl;}
    }

    cout<<"\n\n\tEnter New User-ID:  ";
    cin>>nuid;
    cout<<"\n\n\tEnter New Password:  ";
    cin>>npass;
    stringstream ss;
    ss << "UPDATE bank SET uname = '" << nuid << "',pass ='"<< npass <<"'  WHERE uname = '" << uid << "' and pass = '" << pass << "'";
    string query = ss.str();
         const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
             if(!qstate){
            res = mysql_store_result(conn);
             cout<<"\n\n\tACCOUNT MODIFIED..."<<endl;
             cout<<"\tPLEASE LOGIN AGAIN\n\n"<<endl;
             ch='6';
            }else{
        cout << "Connection Error" << endl;
        cout << "\n\n\n\n Press B to go back";
        cin >> dummy;
             }
        }}

        }
        break;

    case '2':
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
    int qstate = 0;
    cout<<"\n\n   Your Account Balance INFO "<<endl;
	stringstream ss;
	ss << "SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
	string query = ss.str();
         const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
             if(!qstate){
            res = mysql_store_result(conn);
             while(row = mysql_fetch_row(res)){
                cout << "\n\n\tBALANCE :  "<< row[0] << endl << endl;
             }

        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "\n\n\n\n Press B to go back";
            cin >> dummy;
        }
    }else{
        cout << "Connection Error" << endl;
        cout << "\n\n\n\n Press B to go back";
        cin >> dummy;
    }
    cout<<"\n\n";
    system("pause");
}
}
        break;
    case '3':
{   int money;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_RES* res1;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
    stringstream ss;
	ss << "SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
	string query = ss.str();
         const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            res = mysql_store_result(conn);
             while(row = mysql_fetch_row(res)){
                cout << "\n\n\tCURRENT BALANCE :  "<< row[0] << endl << endl;
            cout<<"\n\n\tEnter Amount to deposit :";
            cin>>money;}
             }
    stringstream ss2;
    ss2<< "update bank set amounts = amounts + "<<money<<" WHERE uname ='" << uid << "' and pass ='" << pass << "'";
    string query2 = ss2.str();
    const char* s = query2.c_str();
    int qstate2 = mysql_query(conn, s);
    stringstream ss1;
    ss1<< "SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
        string query1 = ss1.str();
        const char* r = query1.c_str();
        int qstate1 = mysql_query(conn, r);
        if(qstate1 == 0){
            res1 = mysql_store_result(conn);

            while(row = mysql_fetch_row(res1)){
                cout<<"\n\n\tBALANCE AFTER DEPOSIT : "<< row[0] <<endl;
             }
        }

}
cout<<"\n\n";
 }   system("pause");
    break;

    case '4':
{   int money;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_RES* res1;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
    if (conn){
    stringstream ss;
	ss << "SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
	string query = ss.str();
         const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            res = mysql_store_result(conn);
             while(row = mysql_fetch_row(res)){
                cout << "\n\n\tCURRENT BALANCE :  "<< row[0] << endl << endl;
            cout<<"\n\n\tEnter Amount to draw :";
            cin>>money;}
            }
        stringstream ss2;
    ss2<< "update bank set amounts = amounts - "<<money<<" WHERE uname ='" << uid << "' and pass ='" << pass << "'";
    string query2 = ss2.str();
    const char* s = query2.c_str();
    int qstate2 = mysql_query(conn, s);
    stringstream ss1;
    ss1<< "SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
        string query1 = ss1.str();
        const char* r = query1.c_str();
        int qstate1 = mysql_query(conn, r);
        if(qstate1 == 0){
            res1 = mysql_store_result(conn);
            while(row = mysql_fetch_row(res1)){
                cout<<"\n\n\tBALANCE AFTER WITHDRAW : "<< row[0] <<endl;
             }
        }
        cout<<"\n\n";
    system("pause");
}  }break;

    case '5':
    {
        cout<<"\n\n\tTRANSACTION\n\tAMOUNT TRANSFER TO OTHER ACCOUNT";
        int t;
        int acno;
        MYSQL* conn;
        MYSQL_RES* res0;
        MYSQL_RES* res;
        MYSQL_RES* res3;

        MYSQL_ROW row;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "192.168.1.100", "admin","admin","bank", 0 , NULL, 0);
        if (conn){

        stringstream ss0;
        ss0 << "SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
        string query0 = ss0.str();
        const char* a = query0.c_str();
        int qstate0 = mysql_query(conn, a);
        if(qstate0 == 0){
        res0 = mysql_store_result(conn);
        while(row = mysql_fetch_row(res0)){
        cout << "\n\n\tCURRENT BALANCE :  "<< row[0] << endl << endl;}
        }
        cout<<"\n\tEnter Amount to Transfer : ";
        cin>>t;
        cout<<"\n\n\tEnter Account Number of Reciever : ";
        cin>>acno;

        stringstream ss;
        ss<< "SELECT * FROM bank WHERE accno = "<< acno <<"";
        string query = ss.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        if(qstate==0){
            res = mysql_store_result(conn);
            int countt = mysql_num_rows(res);
            if (countt == 1)
            {
        stringstream ss1;
        stringstream ss2;
        stringstream ss3;
        ss1<< "update bank set amounts = amounts - "<<t<<" WHERE uname ='" << uid << "' and pass ='" << pass << "'";
        string query1 = ss1.str();
        const char* s = query1.c_str();
        int qstate1 = mysql_query(conn, s);
        ss2<< "update bank set amounts = amounts + "<<t<<" WHERE accno = '"<<acno<<"'";
        string query2 = ss2.str();
        const char* t = query2.c_str();
        int qstate2 = mysql_query(conn, t);
        ss3<<"SELECT amounts FROM bank WHERE uname ='" << uid << "' and pass ='" << pass << "'";
        string query3 = ss3.str();
        const char* u = query3.c_str();
        int qstate3 = mysql_query(conn, u);
        if(qstate3 == 0){
            res3 = mysql_store_result(conn);
            cout<<"\n\t\tTRANSACTION SUCCESSFUL"<<endl;
             while(row = mysql_fetch_row(res3)){
                cout << "\n\n\tREMAINING BALANCE :  "<< row[0] << endl << endl;}}

                }
        else{cout<<"\n\n\tEntered Account No. Does Not Exist\n\n"<<endl;
        }}
                }
                else{cout<<"\n\tDatabase not Connected";}
            }    system("pause");
                break;

    case '6':
        cout<<"\n\n\tThank you and have a cheerful day ";
        break;

}
            }
            }}
else{cout<<"\n  Login_id or Password wrong\n\tTry Again";}
                }
else{cout << "Insert Error" << mysql_error(conn) << endl;}
            }
            else{cout<<"\n\tDatabase not Connected";}
}


 //***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
	cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\tBUISNESS PURPOSES";
	cout<<"\n\n\n\n   MADE BY : Vikas & Sujeet";
	cout<<"\n\n   SCHOOL : School of Engineering";
	cin.get();
}
