#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
// class date
// {
//     unsigned int day, month, year;

// public:
//     void setDate();
//     void displayDate() const;
//     int getDay();
//     int getMonth();
//     int getYear();
// };
// void date::setDate()
// {
//     cout << "enter the day : ";
//     cin >> day;
//     cout << "enter the month : ";
//     cin >> month;
//     cout << "enter the year : ";
//     cin >> year;
// }
// void date::displayDate() const
// {
//     cout << "day : " << day;
//     cout << "month : " << month;
//     cout << "year : " << year;
// }
// int date::getDay() { return day; }
// int date::getMonth() { return month; }
// int date::getYear() { return year; }

class Appointment // class Appointment
{
    int patient_id;
    char name[20], userName[20], Email[20], password[20];
    string disease;
    string contact_no;
    string time;
    int day, month, year;

public:
    void registration()
    {
        cout << "enter Name : ";
        cin >> name;
        cout << "enter userName : ";
        cin >> userName;
        cout << "enter Email: ";
        cin >> Email;
        cout << "passowrd : ";
        cin >> password;
        cout << "contact Number : ";
        cin >> contact_no;
        // fp.open("appointment.dat", ios::out | ios::app);
        // ap.get_data();
        // fp.write((char *)&ap, sizeof(ap));
        // fp.close();
        // cout << "\n Appointment record has been created ";
        // getchar();
    };
    char ret_userName()
    {
        return userName[20];
    }
    char ret_pass()
    {
        return password[20];
    }
    void login()
    {
        cout << "enter the user Name : ";
        cin >> userName;
        cout << "enter password : ";
        cin >> password;
    };
    void get_data()
    {
        cout << "\n Enter patient ID: ";
        cin >> patient_id;
        cout << "\n Enter patient name: ";
        cin >> name;
        cout << "\n Enter Disease: ";
        cin >> disease;
        cout << "\n Enter Contact Number: ";
        cin >> contact_no;
        cout << "\n Enter date of appointment: \n";
        cout << "enter the day : ";
        cin >> day;
        cout << "enter the month : ";
        cin >> month;
        cout << "enter the year : ";
        cin >> year;
        cout << "\n Enter time of appointment: ";
        cin >> time;
    }

    void show_data()
    {
        cout << "\n Patient ID: " << patient_id;
        cout << "\n Patient Name: " << name;
        cout << "enter userName : ";
        cin >> userName;
        cout << "enter Email: ";
        cin >> Email;
        cout << "passowrd : ";
        cin >> password;
        cout << "\n Disease: " << disease;
        cout << "\n Contact Number: " << contact_no;
        cout << "day : " << day;
        cout << "month : " << month;
        cout << "year : " << year;
        cout << "\n Time of Appointment: " << time;
    }

    int ret_patient_id()
    {
        return patient_id;
    }
    string ret_time()
    {
        return time;
    }
    int ret_date()
    {
        return day;
    }

    void edit_data()
    {
        cout << "\n Enter new patient name: ";
        cin >> name;
        cout << "\n Enter new Disease: ";
        cin >> disease;
        cout << "\n Enter new Contact Number: ";
        cin >> contact_no;
        cout << "\n Enter new date of appointment: \n";
        cout << "enter the day : ";
        cin >> day;
        cout << "enter the month : ";
        cin >> month;
        cout << "enter the year : ";
        cin >> year;
        cout << "\n Enter new time of appointment: ";
        cin >> time;
    }
};

fstream fp;
Appointment ap;

void signUp()
{
    fstream sign_up;
    sign_up.open("sing_up.dat", ios::out | ios::app);
    ap.registration();
    sign_up.write((char *)&ap, sizeof(ap));
    sign_up.close();
    cout << "\nuser has registered successfully \n";
    getchar();
}
void login()
{
    int flag = 0;
    char userName[20], password[20];
    cout << "enter the user Name : ";
    cin >> userName;
    cout << "enter password : ";
    cin >> password;

    fstream log_in;
    log_in.open("sign_up.dat", ios::in);
    while (log_in.read((char *)&ap, sizeof(ap)))

    {
        // if (ap.ret_userName() == userName && ap.ret_pass() == password)
        {
            ap.show_data();
            flag = 1;
        }
    }

    log_in.close();
    if (flag == 0)
        cout << "\n\n Appointment does not exist";
    getchar();
}

void write_appointment() // function to write record in binary file
{
    fp.open("appointment.dat", ios::out | ios::app);
    ap.get_data();
    fp.write((char *)&ap, sizeof(ap));
    fp.close();
    cout << "\n Appointment record has been created ";
    getchar();
}

void display_all() // function to display all records from binary file
{
    cout << "\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("appointment.dat", ios::in);
    while (fp.read((char *)&ap, sizeof(ap)))
    {
        ap.show_data();
        cout << "\n\n====================================\n";
        getchar();
    }
    fp.close();
    getchar();
}

void display_sp(int n) // function to display specific record from binary file
{
    int flag = 0;
    fp.open("appointment.dat", ios::in);
    while (fp.read((char *)&ap, sizeof(ap)))
    {
        if (ap.ret_patient_id() == n)
        {
            ap.show_data();
            flag = 1;
        }
    }

    fp.close();
    if (flag == 0)
        cout << "\n\n Appointment does not exist";
    getchar();
}

void modify_appointment() // function to modify record of binary file
{
    int no, found = 0;
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tEnter patient id of Appointment : ";
    cin >> no;
    fp.open("appointment.dat", ios::in | ios::out);
    while (fp.read((char *)&ap, sizeof(ap)) && found == 0)
    {
        if (ap.ret_patient_id() == no)
        {
            ap.show_data();
            cout << "\nEnter new details of appointment" << endl;
            ap.edit_data();
            unsigned int pos = 1 * sizeof(ap);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&ap, sizeof(ap));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }

    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getchar();
}

void delete_Appointment() // function to delete record of binary file
{
    int no;
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nEnter the patient id of the Appointment You Want To Delete : ";
    cin >> no;
    fp.open("appointment.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&ap, sizeof(ap)))
    {
        if (ap.ret_patient_id() != no)
        {
            fp2.write((char *)&ap, sizeof(ap));
        }
    }

    fp2.close();
    fp.close();
    remove("appointment.dat");
    rename("Temp.dat", "appointment.dat");
    cout << "\n\n\tRecord Deleted ..";
    getchar();
}

void search_appointment() // function to search record of binary file
{
    int no;
    cout << "\n\n\tSearch Appointment";
    cout << "\n\n\tEnter patient id of Appointment:";
    cin >> no;
    fp.open("appointment.dat", ios::in | ios::out);
    while (fp.read((char *)&ap, sizeof(ap)))
    {
        if (ap.ret_patient_id() == no)
        {
            ap.show_data();
            cout << "\n\n====================================\n";
            getchar();
        }
    }

    fp.close();
    getchar();
}

void view_appointments() // function to view all appointments
{
    fp.open("appointment.dat", ios::in);
    while (fp.read((char *)&ap, sizeof(ap)))
    {
        ap.show_data();
        // cout<<"\n Date of Appointment: "<<ap.date;
        // cout<<"\n Time of Appointment: "<<ap.time;
        ap.show_data();
        cout << "\n\n====================================\n";
        getchar();
    }
    fp.close();
    getchar();
}

// void view_free_slots() // function to view free slots
// {
//     int flag = 0;
//     unsigned int d;
//     string t;
//     cout << "\n Enter date for free slots: ";
//     cin >> d;
//     cout << "\n Enter time for free slots: ";
//     cin >> t;

//     fp.open("appointment.dat", ios::in);
//     while (fp.read((char *)&ap, sizeof(ap)))
//     {
//         if (strcmp(ap.ret_date(), d) == 0 && strcmp(ap.ret_time(), t) == 0)
//         {
//             flag = 1;
//             break;
//         }
//     }

//     if (flag == 0)
//         cout << "\n Slot is free";
//     else
//         cout << "\n Slot is not free";

//     fp.close();
//     getchar();
// }

int main() // main function
{
    int choice;
    cout.setf(ios::fixed | ios::showpoint);
    cout << "\n\n\t\t Hospital Management System \n\n";
    do
    {
        cout << "\n\n\tMAIN MENU\n\n";
        cout << "1.signup\n";
        cout << "2.login\n";
        cout << "\n1.CREATE Appointment";
        cout << "\n2.DISPLAY All Appointments";
        cout << "\n3.SEARCH Appointment";
        cout << "\n4.MODIFY Appointment";
        cout << "\n5.DELETE Appointment";
        cout << "\n6.VIEW Appointments";
        cout << "\n7.VIEW Free Slots";
        cout << "\n8.EXIT";
        cout << "\n\nEnter Your Choice (1-8) ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            login();
            break;
        case 3:
            write_appointment();
            break;
        case 4:
            display_all();
            break;
        case 5:
            int num;
            cout << "\n\n\tPlease Enter The patient id ";
            cin >> num;
            display_sp(num);
            break;
        case 6:
            modify_appointment();
            break;
        case 7:
            delete_Appointment();
            break;
        case 8:
            view_appointments();
            break;
        case 9:
            // view_free_slots();
            break;
        case 10:
            exit(0);
        default:
            cout << "\a";
        }
    } while (choice != 10);
    return 0;
}