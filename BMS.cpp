#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Bank_Account
{
    int Account_Number;
    char name[50];
    char type;
    int Money_Deposite;

    public:

    int returnAccountNumber() const
    {
        return Account_Number;
    }
    void Report_Account() const;
    void Withdraw_Money();
    void Alter_Account();
    void Create_Account();

    void Display_Account();
};

void Bank_Account :: Alter_Account()
{
    m:
    int choice;
    cout <<"\t\t\t\t\t---------------------------------"<<endl;
    cout <<"\t\t\t\t\t|Modify Your Bank Account Details|"<<endl;
    cout <<"\t\t\t\t\t---------------------------------"<<endl;
    cout <<"\t\t\t\t\tPress 1 for change your Name" << endl;
    cout <<"\t\t\t\t\tPress 2 for change your Account type" << endl;
    cout <<"\t\t\t\t\tPress 3 for Deposite Money" << endl;
    cout <<"\t\t\t\t\tPress 4 for exit" << endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout <<"\t\t\t\t\tEnter your new Name: ";
        cin.ignore();
        cin.getline(name,50);
        break;

        case 2:
        cout <<"\t\t\t\t\tEnter C for (current account), S for (saving account): ";
        cin.ignore();
        cin>>type;
        break;

        case 3:
        int newMoney;
        cout <<"\t\t\t\t\tEnter amount which you want to add in your account: ";
        cin>>newMoney;
        Money_Deposite+=newMoney;
        break;

        case 4:
        cout << "\t\t\t\t\tThanks for using Bank Management system!"<<endl;
        break;

        default:
        cout << "You have choosen wrong option Please go back and select a right option: ";
        goto m;
    }
}

void Bank_Account :: Create_Account()
{
    system("cls");
    cout << "\n\t\t\t\tEnter the account number: ";
    cin >> Account_Number;
    cout <<"\n\t\t\t\tEnter the name of the holder: ";
    cin.ignore();
    cin.getline(name,50);
    cout <<"\n\t\t\t\tEnter the type of type of the account (C/S): ";
    cin >> type;
    type = toupper(type);
    cout <<"\n\t\t\t\tEnter the initial amount  (>= 500 for Saving and >= 1000 for Current): ";
    cin >> Money_Deposite;
    cout << "\n\t\t\t\t\t\t\tAccount Created Successfully....:)";
}

void Bank_Account :: Display_Account()
{
    cout << "\n\t\t\t\t\t****************User Information*********************\n";
    cout <<"\t\t\t\t\tName of the Account Holder is: " << name << endl;
    cout <<"\t\t\t\t\tAccount number is: " << Account_Number << endl;
    cout <<"\t\t\t\t\tType of account is: " << type << endl;
    cout <<"\t\t\t\t\tBalance amount is: " << Money_Deposite << endl;
}

void Bank_Account :: Report_Account() const
{
    cout <<"\t\t\t\t" <<Account_Number << setw(18) <<name << setw(6) << type << setw(17) << Money_Deposite <<endl;
}

void write_account();
void delete_account(int);
void display_details(int);
void display_all();
void money_withdraw(int);

int main()
{
    m:
    char choice;
    int num;
    do
    {
    cout <<"\n\n";
    cout <<"\t\t\t\t-----------------------------------------"<<endl;
    cout <<"\t\t\t\t| Welcome to the Bank Management System |"<<endl;
    cout <<"\t\t\t\t-----------------------------------------"<<endl;
    cout <<endl;

    cout <<"\t\t\t\t\t --- Main Menu ---"<<endl;
    cout <<"\t\t\t\t\t 1. Create Account"<<endl;            // created
    cout <<"\t\t\t\t\t 2. Deposite Money"<<endl;
    cout <<"\t\t\t\t\t 3. Withdraw Money"<<endl;            
    cout <<"\t\t\t\t\t 4. Balance Enquiry"<<endl;           // created
    cout <<"\t\t\t\t\t 5. All Account holders list"<<endl;  // created
    cout <<"\t\t\t\t\t 6. Close an Account"<<endl;          // created
    cout <<"\t\t\t\t\t 7. Modify an Account"<<endl;
    cout <<"\t\t\t\t\t 8. Exit"<<endl;
    cout <<endl;

    cout <<"\t\t\t\t\t Enter Your Choice (1-8): ";
    cin>>choice;
    
    switch(choice)
    {
        case '1':
        system("cls");
        write_account();                        //creating an account
        break;

        case '2':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            money_deposite_withdraw(num,1);     //Deposite money Function
        break;

        case '3':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            money_deposite_withdraw(num, 2);    //Withdraw Money Function
        break;

        case '4':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
          display_details(num);                 //Balance Enquiry Function
        break;

        case '5':
        system("cls");
        display_all();                          //All Account Holders List Function
        break;

        case '6':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
           delete_account(num);                 //Close an Account Function
        break;

        case '7':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
        //    modify_account(num);              // Modify an Account Function
        break;

        case '8':
        cout <<"\t\t\t\t\tThanks for using Bank Management System"<<endl;
        break;

        default:
        cout <<"\t\t\t\t\t You Have Entered Wrong Choise, Go back and Chose your right option!"<<endl;
        goto m;
    }
    cin.ignore();
    cin.get();
    }while(choice != '8');
    return 0;

// Bank_Account B;
// B.Create_Account();
// cout << endl;
// B.Display_Account();
cout <<"\n\t\t\t\t\t\t\t\t\t\tDONE!\n\n";
return 0;
}

void write_account()            // function to write record in binary form
{
    Bank_Account ac;
    ofstream outFile;
    outFile.open("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/account.dat", ios::binary | ios::app);
    ac.Create_Account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
    outFile.close();
    ac.Display_Account();
}

void delete_account(int n)
{
    Bank_Account ac;
    ifstream readFile;      // input file stream
    ofstream writeFile;     // output file stream
    readFile.open("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/account.dat", ios::binary);
    if(!readFile)
    {
        cout <<"\t\t\t\t\tFile could not be open | Press any key...";
        return;
    }
    writeFile.open("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/temp.dat", ios::binary);
    readFile.seekg(0, ios::beg);
    while(readFile.read(reinterpret_cast<char* > (&ac), sizeof(Bank_Account)))
    {
        if(ac.returnAccountNumber() != n)
        {
            writeFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
        }

    }
    readFile.close();
    writeFile.close();
    // remove("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/account.dat");
    // rename("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/temp.dat", "C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/temp.dat");
    remove("account.dat");
    rename("temp.dat", "account.dat");
    cout << "\t\t\t\t\tRecord will be deleted..."<<endl;
}

void display_details(int num)
{
    Bank_Account ac;
    ifstream readFile;
    bool flage = false;
    readFile.open("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/account.dat", ios::binary);
    if(!readFile)
    {
        cout << "\t\t\t\t\tCould not find any account | Press any key...";
        return;
    }
    readFile.seekg(0, ios_base::beg);
    while(readFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
    {
        if(ac.returnAccountNumber() == num)
        {
           ac.Display_Account();
           flage = true;
        }
    }
    readFile.close();
   if(flage == false)
   {
    cout << "\t\t\t\t\tAccount doesn't exist!"<<endl;
   }
}

void display_all()
{
    system("cls");
    Bank_Account ac;
    ifstream readFile;
    readFile.open("C:/Users/Babloo/Desktop/Practice/C++/BankManagementSystem/account.dat", ios::binary);
    if(!readFile)
    {
        cout << "\t\t\t\t\t File couldn't be open | Press any key..."<<endl;
        return;
    }
    // readFile.seekg(0, ios_base::beg);
    cout <<"\t\t\t\t\t\tBank Account Holder lists"<<endl;
    cout <<"\t\t\t\t===================================================="<<endl;
    cout <<"\t\t\t\tAccount no.     Name        type       Account Balance"<<endl;
    while(readFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
    {
        ac.Report_Account();
    }
    readFile.close();
    cout <<"\t\t\t\t===================================================="<<endl;
}

