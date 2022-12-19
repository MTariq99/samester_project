// docotor appointment(file handling,search record,edit record,veiw record,delete record) using cpp
#include <fstream>
#include <iostream>
using namespace std;

class Appointment
{
    int day;
    int month;
    int year;
    string patientName;

public:
    Appointment()
    {
    }
    Appointment(int day, int month, int year, string patientName)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->patientName = patientName;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    string getPatientName()
    {
        return patientName;
    }
};

void writeToFile(Appointment appointment)
{
    ofstream file;
    file.open("Appointments.txt", ios::app);

    file << appointment.getDay() << " " << appointment.getMonth() << " " << appointment.getYear() << " " << appointment.getPatientName() << endl;

    file.close();
}

void searchAppointments(int day, int month, int year)
{
    ifstream file;
    file.open("Appointments.txt");

    string line;
    while (getline(file, line))
    {
        string dayStr = line.substr(0, 2);
        string monthStr = line.substr(3, 2);
        string yearStr = line.substr(6, 4);
        if (dayStr == to_string(day) && monthStr == to_string(month) && yearStr == to_string(year))
        {
            cout << line << endl;
        }
    }

    file.close();
}

void editAppointment(int day, int month, int year, string patientName)
{
    ifstream file;
    file.open("Appointments.txt");

    ofstream temp;
    // temp.
}

int main()
{
    char ch;
    int day, month, year;
    Appointment ap;
    do
    {
        cout << "1.book an appointment\n";
        cout << "2.search a patient\n";
        cout << "enter an option : ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            writeToFile(ap);
            break;
        case '2':
            cout << "day : ";
            cin >> day;
            cout << "month : ";
            cin >> month;
            cout << "year : ";
            cin >> year;
            searchAppointments(day, month, year);
            break;
        default:
            cout << "invalid\n";
            break;
        }
    } while (ch != '9');
    return 0;
}