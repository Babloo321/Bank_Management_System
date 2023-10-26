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
Bank_Account B;
B.Create_Account();
cout << endl;
B.Display_Account();
cout <<"\nt\t\t\t\t\t\t\t\t\tDONE!";
cout <<"\n\n";
return 0;
}