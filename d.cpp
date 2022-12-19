#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string user_Name, password;
    cout << "enter the user name : ";
    cin >> user_Name;
    cout << "enter the password : ";
    cin >> password;

    ofstream doctor;
    doctor.open("user.txt", ios::app);
    doctor << user_Name << " ";
    doctor << password << " ";
    doctor << endl;
    doctor.close();

    string username;
    cout << "Enter username : ";
    cin >> username;

    // ifstream file("users.txt");
    // string line;
    // bool found = false;
    // while (getline(file, line))
    // {
    //     if (line == username)
    //     {
    //         cout << "User " << username << " found in file." << endl;
    //         found = true;
    //         break;
    //     }
    // }

    // if (!found)
    // {
    //     cout << "User " << username << " not found in file." << endl;
    // }

    string name;
    cout << "Please enter your username: ";
    cin >> name;
    cout << "Please enter your password: ";
    cin >> password;

    ifstream fin;
    fin.open("user.txt");
    string line;
    bool found = true;
    while (getline(fin, line))
    {
        int breakpoint = line.find(" ");
        string newname = line.substr(0, breakpoint);
        string newpassword = line.substr(breakpoint + 1);
        if (name == newname && password == newpassword)
        {
            cout << "Loggedin successfully" << endl;
            found;
        }
    }

    fin.close();
    if (!found)
    {
        cout << "not found\n";
    }
    return 0;
}