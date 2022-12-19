#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "string"
using namespace std;

class appointment
{
    string name, username, password, email;

public:
    appointment() {}
    void signup();
    void login();
    bool searchUser(string str, string, string);
};
void appointment::signup()
{
    cout << "enter the name : ";
    cin >> name;
    cout << "enter user name : ";
    cin >> username;
    cout << "enter the password : ";
    cin >> password;
    ofstream sign_up("sign_up.txt", ios::app);
    sign_up << name << " ";
    sign_up << username << " ";
    sign_up << password << endl;
}
bool appointment::searchUser(string str, string userName, string pwd)
{
    istringstream ss(str);
    string word;
    bool found = false;
    int i = 0;
    bool isUser = false;
    bool isPwd = false;
    while (ss >> word)
    {
        if (i == 1)
        {
            // check user name
            if (word == userName)
            {
                isUser = true;
            }
        }
        else if (i == 2)
        {
            // check passward.
            if (word == pwd)
            {
                isPwd = true;
            }
        }

        i++;
    }
    if (isUser && isPwd)
    {
        return true;
    }
    return false;
}
void appointment::login()
{
    string line;
    string pass, usern;
    cout << "enter the user name : ";
    cin >> username;
    cout << "enter the password : ";
    cin >> password;
    ifstream log_in("sign_up.txt");
    bool isExist = false;
    while (getline(log_in, line))
    {
        isExist = searchUser(line, username, password);
        if (isExist)
        {
            break;
        }
    }
    if (isExist)
    {
        cout << "LoggedIn";
    }
    else
    {
        cout << "Not Loggin";
    }
}

int main()
{
    int choice, userchoice;
    appointment ap;
    do
    {

        cout << endl
             << "               Doctor appointment application                 " << endl;
        cout << "--------------------------------------------------------------------" << endl
             << endl;
        cout << "  1 : signUp " << endl;
        cout << "  2 : Login " << endl;
        cout << "\nEnter a number accordingly : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ap.signup();
            break;
        case 2:
            ap.login();
            break;
        case 3:
            break;
        case 4:
            break;
            cout << "wellcome to the SignUp page" << endl
                 << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}

// void LogIn()
// {
// }

// void signUp()
// {
//     signUpSystem signup;
//     patients p;
//     string userWant, un;
//     cout << "welcome to the signup page " << endl;
//     cout << " please press 'd' for doctor 'p' for patient:  ";
//     cin >> signup.user_type;
//     if (signup.user_type == 'd')
//     {
//         cout << "Enter a user name  : ";
//         cin >> signup.user_Name;
//         cout << "Enter a password : ";
//         cin >> signup.password;
//     }
//     else if (signup.user_type == 'p')
//     {
//         cout << "Enter a user name  : ";
//         cin >> signup.user_Name;
//         cout << "Enter a password : ";
//         cin >> signup.password;
//         cout << "Enter your gender : ";
//         cin >> p.sex;
//         cout << "enter your age: ";
//         cin >> p.age;
//         cout << "what is your problem : ";
//         cin >> p.disease;
//         cout << "enter your phone number: ";
//         cin >> p.phoneNumber;
//     }
//     else if (signup.user_type == 'P')
//     {
//         cout << "enter your user Name: ";
//         cin >> signup.user_Name;
//         cout << "enter a password : ";
//         cin >> signup.password;
//     }
//     if (signup.user_type == 'd')
//     {
//         ofstream doctor;
//         doctor.open("doctorData.txt", ios::app);
//         doctor << signup.user_Name << endl;
//         doctor << signup.password << endl;
//         doctor.close();
//     }
//     else if (signup.user_type == 'P')
//     {
//         ofstream PA;
//         PA.open("PaData.txt", ios::app);
//         PA << signup.user_Name << endl;
//         PA << signup.password << endl;
//         PA.close();
//     }
//     else if (signup.user_type == 'p')
//     {
//         ofstream file;
//         file.open("patientData.txt", ios::app);
//         file << signup.user_Name << endl;
//         file << signup.password << endl;
//         file.close();
//     }

//     cout << endl
//          << endl
//          << "congratulations account created successfully " << endl;
//     cout << "want to login" << endl;
//     cout << "if you want then please Enter yes : ";
//     cin >> userWant;
//     if (userWant == "yes")
//     {
//         LogIn();
//     }
// }

// int bookAnAppointment()
// {

//     system("cls");

//     cout << "\n ----- Book your appointment for particular time slot ---- \n";
//     cout << "\n ----- Available slots are---- \n";

//     ifstream read;
//     read.open("appointment.dat");

//     int hoursbook = 10;

//     int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     int recordFound = 0;

//     if (read)
//     {
//         string line;
//         char key = 'A';
//         int i = 9;

//         while (getline(read, line))
//         {
//             char temp = line[0];
//             int index = (temp);
//             arr[index] = 0;
//             recordFound = 1;
//         }
//         if (recordFound == 1)
//         {
//             cout << "\n Appointment List by Hours:";
//             char key = 'A';
//             int hours = 9;
//             for (int i = 0; i <= 9; i++)
//             {
//                 if (i == 0)
//                 {
//                     if (arr[i] == 0)
//                         cout << "\n " << key << "-> 0" << hours << " - Available";
//                     else
//                         cout << "\n " << key << "-> 0" << hours << " - available`";
//                 }

//                 else
//                 {
//                     if (arr[i] == 0)
//                         cout << "\n " << key << "->" << hours << " - Available";
//                     else
//                         cout << "\n " << key << "->" << hours << " - available";
//                 }
//                 hours++;
//                 key++;
//             }
//         }

//         read.close();
//     }
//     if (recordFound == 0)
//     {
//         cout << "\n Appointment Available for following hours :";
//         char key = 'A';
//         for (int i = 9; i <= 18; i++)
//         {
//             if (i == 9)
//                 cout << "\n " << key << " -> 0" << i << " - Available";
//             else
//                 cout << "\n " << key << " -> " << i << " - available";
//             key++;
//         }
//     }

//     char choice;
//     cout << "\n\n Choose your slot: ";
//     cin >> choice;

//     if (!(choice >= 'A' && choice <= 'Z'))
//     {
//         cout << "\n Error : Invalid Selection";
//         cout << "\n Please selction correct value from menu A- Z";
//         cout << "\n Press any key to continue";
//         getchar();
//         getchar();
//         system("cls");
//         bookAnAppointment();
//     }

//     int index = (choice - 65);
//     int isBooked = 1;
//     if (arr[index] == 0)
//         isBooked = 0;

//     if (isBooked == 1)
//     {
//         cout << "\n Error : This Appointment  slot is already booked";
//         cout << "\n Please select different slot time !!";
//         cout << "\n Press any key to continue!!";
//         getchar();
//         getchar();
//         system("cls");
//         bookAnAppointment();
//     }

//     string name;
//     cout << "\n Enter your Name:";
//     cin >> name;

//     ofstream out;
//     out.open("appointment.dat", ios::app);

//     if (out)
//     {
//         int doctorFee, fee;
//         out << choice << ":" << name.c_str() << "\n";
//         out.close();
//         doctorFee = payFee();
//         if (doctorFee)
//             cout << "\n Appointment is Successfully Booked for Hours : " << (choice - 65) + 9 << " !!";
//         else
//         {
//             cout << "please pay the full fee " << endl;
//             payFee();
//         }
//     }
//     else
//     {
//         cout << "\n Error while saving booking";
//     }

//     cout << "\n Please any key to continue..";
//     getchar();
//     getchar();

//     return 0;
// }

// int existingAppointment()
// {
//     system("cls");

//     cout << "\n ----- List of Available Appointments ---- \n";
//     ifstream read;
//     read.open("appointment.dat");

//     int hoursbook = 10;

//     int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     int recordFound = 0;

//     if (read)
//     {
//         string line;
//         char key = 'A';
//         int i = 9;

//         while (getline(read, line))
//         {
//             char temp = line[0];
//             int index = (temp - 65);
//             arr[index] = 1;
//             recordFound = 1;
//         }
//         if (recordFound == 1)
//         {
//             cout << "\n Appointment List by hours:";
//             char key = 'A';
//             int hours = 9;
//             for (int i = 0; i <= 9; i++)
//             {
//                 if (i == 0)
//                 {
//                     if (arr[i] == 0)
//                         cout << "\n " << key << "-> 0" << hours << " - Available";
//                     else
//                         cout << "\n " << key << "-> 0" << hours << " - Booked";
//                 }

//                 else
//                 {
//                     if (arr[i] == 0)
//                         cout << "\n " << key << "->" << hours << " - Available";
//                     else
//                         cout << "\n " << key << "->" << hours << " - Booked";
//                 }
//                 hours++;
//                 key++;
//             }
//         }

//         read.close();

//         if (recordFound == 0)
//         {
//             cout << "\n Appointment Available for following hours :";
//             char key = 'A';
//             for (int i = 9; i <= 18; i++)
//             {
//                 if (i == 9)
//                     cout << "\n " << key << " -> 0" << i << " - Available";
//                 else
//                     cout << "\n " << key << " -> " << i << " - booked";
//                 key++;
//             }
//         }
//     }
//     ofstream out;
//     out.open("appointment.dat", ios::app);

//     cout << "\n Please any key to continue..";
//     getchar();
//     getchar();
//     return 0;
// }

// void viewPatients()
// {
//     string drChoice, viewPatient;
//     cout << "do you want to see patients appointments please enter viewpatient : ";
//     cin >> drChoice;
//     ifstream openfile("appointment.dat");
//     if (openfile.is_open())
//     {
//         while (!openfile.eof())
//         {
//             getline(openfile, viewPatient);
//             cout << viewPatient << endl;
//         }
//     }
// }
// bool payFee()
// {
//     int fee;
//     cout << "please Enter 1000RS doctor fee: ";
//     cin >> fee;
//     if (fee == 1000)
//         return true;
//     return false;
// }
