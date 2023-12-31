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

    int returnAccountNumber() const     // member function for returning account number
    {
        return Account_Number;
    }

    void Report_Account() const;        // it return all data member values

    void DEP(int x){                    // to maintain Money when user deposite money
        Money_Deposite+=x;
    }

    void WTHDRW(int x)                  // to maintain Money when user withdraw money from the account
    {
        Money_Deposite-=x;
    }

    int Return_Deposite() const{        // to return user's balance in user's account
        return Money_Deposite;
    }

    void Modify();

    void Create_Account();              // it is for Creating a New Account

    void Display_Account();             // It is for Dispalying the all information of a defined account no. of a Bank holder
};

void Bank_Account :: Create_Account()
{
    system("cls");
    system("color 17");
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
    system("color 37");
    cout << "\n\t\t\t\t\t****************User Information*********************\n"<<endl;
    cout <<"\t\t\t\t\tName of the Account Holder is: " << name << endl;
    cout <<"\t\t\t\t\tAccount number is: " << Account_Number << endl;
    cout <<"\t\t\t\t\tType of account is: " << type << endl;
    cout <<"\t\t\t\t\tBalance amount is: " << Money_Deposite << endl;
    cout << "\n\t\t\t\t\t*****************************************************\n"<<endl;
    cout <<endl<<endl;
}

void Bank_Account :: Report_Account() const
{
    system("color 40");
    cout <<"\t\t\t\t" <<Account_Number << setw(18) <<name << setw(6) << type << setw(17) << Money_Deposite <<endl;
}

void Bank_Account :: Modify()
{
    system("cls");
    system("color 17");
    cout << "\t\t\t\t\t Bank account number is: " << Account_Number <<endl;
    cout <<"\t\t\t\t\t Modify bank account holder name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout <<"\t\t\t\t\t Modify the type of account: ";
    cin>>type;
    type = toupper(type);
    cout <<"\t\t\t\t\t Modify bank account Amount: ";
    cin>>Money_Deposite;
}

void write_account();
void delete_account(int);
void display_details(int);
void display_all();
void money_deposite_withdraw(int,int);
void update_bank_account(int);

int main()
{
    system("color 60");
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
    cout <<"\t\t\t\t\t 2. Deposite Money"<<endl;            // created
    cout <<"\t\t\t\t\t 3. Withdraw Money"<<endl;            // created
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
           update_bank_account(num);              // Modify an Account Function
        break;

        case '8':
        cout <<"\t\t\t\t\tThanks for using Bank Management System"<<endl;
        break;

        default:
        cout <<endl;
        cout <<"\t\t\t\t\t Wrong choice, Go back and Chose your right option!"<<endl;
        goto m;
    }
    cin.ignore();
    cin.get();
    }while(choice != '8');
    return 0;
cout <<"\n\t\t\t\t\t\t\t\t\t\tDONE!\n\n";
return 0;
}

void write_account()            // function to write record in binary form
{
    system("color 30");
    Bank_Account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.Create_Account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
    outFile.close();
    ac.Display_Account();
}

void delete_account(int n)
{
    system("color 40");
    Bank_Account ac;
    ifstream readFile;      // input file stream
    ofstream writeFile;     // output file stream
    readFile.open("account.dat", ios::binary);
    if(!readFile)
    {
        cout <<"\t\t\t\t\tFile could not be open | Press any key...";
        return;
    }
    writeFile.open("temp.dat", ios::binary);
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
    system("color 90");
    Bank_Account ac;
    ifstream readFile;
    bool flage = false;
    readFile.open("account.dat", ios::binary);
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
    system("color 50");
    Bank_Account ac;
    ifstream readFile;
    readFile.open("account.dat", ios::binary);
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

void money_deposite_withdraw(int n, int option)
{
    system("color 70");
    int amount;
    bool found = false;
    fstream File;
    Bank_Account ac;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    while(!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
        if(ac.returnAccountNumber() == n)
        {
            ac.Display_Account();
            if(option == 1)
            {
                cout <<"\t\t\t\t\t Enter amount to be deposite into your Bank account: ";
                cin>>amount;
                ac.DEP(amount);
            }
            if(option == 2){
                cout << "\t\t\t\t\t Enter amount to be withdrawing from your Bank account: ";
                cin>>amount;
                int balance = ac.Return_Deposite() - amount;
                if(balance < 0)
                {
                    cout <<"\t\t\t\t\t Your account have unsufficient money"<<endl;

                }else{
                    ac.WTHDRW(amount);
                }
            }
            int pos = (-1)* static_cast<int>(sizeof(Bank_Account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
            cout <<"\t\t\t\t\t Record Updated!"<<endl;
            found = true;
        }
    }
    File.close();
    if(found == false)
    {
        cout <<"\t\t\t\t\t Record not found! "<<endl;
    }
}

void update_bank_account(int n)
{
    system("color 20");
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);     // Open the file in binary mode
    if(!File)
    {
        cout << "\t\t\t\t\t\t Account could not be exist: "<<endl;
        return;
    }
    while(!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));            // read the record from the file
        if(ac.returnAccountNumber() == n)
        {
            ac.Display_Account();
            cout << "\t\t\t\t\t Enter the new details of your account:"<<endl;
            ac.Modify();
            int pos = (-1)* static_cast<int>(sizeof(Bank_Account));      
            File.seekp(pos, ios::cur);                                             // move the pointer to the position of the file
            File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
            cout <<"\t\t\t\t\t Record Updated!"<<endl;
            found = true;
        }
    }
    File.close();
    if(found == false)
    {
        cout << "\t\t\t\t\t Record not found!"<<endl;
    }
}