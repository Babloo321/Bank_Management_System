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
    void Create_Account();
    void Display_Account();
};
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
int main()
{
    m:
    char choice;
    int num;
    cout <<"\n\n";
    cout <<"\t\t\t\t---------------------------------------------"<<endl;
    cout <<"\t\t\t\t | Welcome to the Bank Management System |"<<endl;
    cout <<"\t\t\t\t---------------------------------------------"<<endl;
    cout <<endl;

    cout <<"\t\t\t\t\t --- Main Menu ---"<<endl;
    cout <<"\t\t\t\t\t 1. Create Account"<<endl;
    cout <<"\t\t\t\t\t 2. Deposite Money"<<endl;
    cout <<"\t\t\t\t\t 3. Withdraw Money"<<endl;
    cout <<"\t\t\t\t\t 4. Balance Enquiry"<<endl;
    cout <<"\t\t\t\t\t 5. All Account holders list"<<endl;
    cout <<"\t\t\t\t\t 6. Close an Account"<<endl;
    cout <<"\t\t\t\t\t 7. Modify an Account"<<endl;
    cout <<"\t\t\t\t\t 8. Exit"<<endl;
    cout <<endl;

    cout <<"\t\t\t\t\t Enter Your Choice (1-8): ";
    cin>>choice;

    switch(choice)
    {
        case '1':
        system("cls");
            //creating an account
        break;

        case '2':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            //Deposite money Function
        break;

        case '3':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            //Withdraw Money Function
        break;

        case '4':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            //Balance Enquiry Function
        break;

        case '5':
        system("cls");
        // display_all();
            //All Account Holders List Function
        break;

        case '6':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            //Close an Account Function
        break;

        case '7':
        system("cls");
        cout <<"\t\t\t\t\t Enter Your Account Number: ";
        cin>>num;
            // Modify an Account Function
        break;

        case '8':
        cout <<"\t\t\t\t\tThanks for using Bank Management System"<<endl;
        break;

        default:
        cout <<"\t\t\t\t\t You Have Entered Wrong Choise, Go back and Chose your right option!"<<endl;
        goto m;
    }

Bank_Account B;
B.Create_Account();
cout << endl;
B.Display_Account();
cout <<"\nt\t\t\t\t\t\t\t\t\tDONE!";
cout <<"\n\n";
return 0;
}