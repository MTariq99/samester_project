#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// ofstream for creating a file
//

class registration
{
protected:
    string name, userName, Email, password;

public:
    registration() {}
    registration(string cName, string cUserName, string cEmail, string cPassword)
    {
        name = cName;
        userName = cUserName;
        Email = cEmail;
        password = cPassword;
    }
    void singUp();
    void Login();
};
void registration::singUp()
{
    cout << "enter Name : ";
    cin >> name;
    cout << "user Name : ";
    cin >> userName;
    cout << "Email : ";
    cin >> Email;
    cout << "Password : ";
    cin >> password;
}
void registration::Login()
{
    cout << "ENTER USER NAME : ";
    cin >> userName;
    cout << "ENTER PASSWORD : ";
    cin >> password;
}

class customer : public registration
{
    string ID;
    string address, phoneNumber;

public:
    customer() {}
    customer(string cName, string cUserName, string cEmail, string cPassword, string cID, string cAddress, string cPhoneNumber) : ID(cID), address(cAddress), phoneNumber(cPhoneNumber), registration(cName, cUserName, cEmail, cPassword) {}
    void singUp();
    void login();
    void veiwCategory();
    void viewProduct();
    void orderProduct();
    void copydata();
};
void customer::singUp()
{

    cout << "ID : ";
    cin >> ID;
    cout << "enter Name : ";
    cin >> name;
    cout << "user Name : ";
    cin >> userName;
    cout << "Email : ";
    cin >> Email;
    cout << "Password : ";
    cin >> password;
    cout << "ADDRESS : ";
    cin >> address;
    cout << "PHONE NUMBER : ";
    cin >> phoneNumber;
    // writing data in a file
    ofstream reg;
    reg.open("registrationfile.txt", ios::app);
    reg << ID << " ";
    reg << name << " ";
    reg << userName << " ";
    reg << Email << " ";
    reg << password << " ";
    reg << address << " ";
    reg << phoneNumber << " ";
    reg << endl;
    reg.close();
}

// void customer::copydata()
// {
//     ifstream copyd("registrationfile.txt");
//     customer arr[2];
//     while (!copyd.eof())
//     {
//         for (int i = 0; i < 2; i++)
//         {
//             copyd >> arr[i];
//         }
//     }
//     cout << "enter user Name : ";
//     cin >> userName;
//     cout << "enter password : ";
//     cin >> password;

//     for (int i = 0; i < 2; i++)
//     {
//         if (userName == arr[i].userName && password == arr[i].userName)
//         {
//             cout << "login successfully\n";
//         }
//         else
//         {
//             cout << "error\n";
//         }
//     }
// }

void customer::login()
{

    string un, pw, line = " ", uName, passw;
    customer cust;
    FILE *fptr;
    int flag = 0;
    ifstream isLogin("registrationfile.txt");
    cout << "enter userName : ";
    cin >> uName;
    cout << "enter password : ";
    cin >> passw;

    if (fptr == NULL)
    {
        cout << "file was not opened\n";
    }

    while (fread(&cust, sizeof(cust), 1, fptr) > 0)
    {
        if (cust.userName == uName && cust.password == passw)
        {
            cout << "logged in\n";
        }
        else
        {
            cout << "Error\n";
        }
    }
}

int main()
{
    customer cus;
    char ch;
    do
    {
        cout << "1.signup\n";
        cout << "2.login\n";
        cout << "3.copy data\n";
        cout << "enter option : ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            cus.singUp();
            break;
        case '2':
            cus.login();
            break;
        case '3':
            // cus.copydata();
            break;
        default:
            cout << "invalid\n";
            break;
        }
    } while (ch != '9');
    return 0;
}