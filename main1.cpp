#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct student
{
    int id;
    char name[20];
    float gpa;
    char address[50];
};

void add_student()
{

    student s;
    fstream stud;

    stud.open("sd.txt", ios::app);
    while (stud.is_open())
    {
        cout << "enter student ID: ";
        cin >> s.id;
        cin.ignore();
        cout << "enter student Name: ";
        cin.getline(s.name, 20);
        cout << "enter student GPA: ";
        cin >> s.gpa;
        cin.ignore();
        cout << "enter student Address: ";
        cin.getline(s.address, 50);
        stud.write((char *)(&s.id), sizeof(short));
        stud << s.id;
        short length = strlen(s.name);
        stud.write((char *)(&length), sizeof(short));
        stud.write(s.name, length);
        stud.write((char *)(&s.gpa), sizeof(short));
        stud << s.gpa;
        length = strlen(s.address);
        stud.write((char *)(&length), sizeof(short));
        stud.write(s.address, length);
        stud << "$";
        stud << '\n';
        stud.close();
    }
}

void search()
{

    student s;

    short length;
    int search_id;
    char item;
    cout << "Enter your id to search: ";
    cin >> search_id;
    ifstream myfile;
    myfile.open("sd.txt", ios::app);
    while (myfile.is_open())
    {
        while (myfile >> item)
        {
            if (item == search_id)
            {
                cout << "Student data:" << endl;
                myfile.seekg(-1, ios::cur);
                myfile.read((char *)(&length), sizeof(short));
                myfile >> s.id;
                myfile.read((char *)(&length), sizeof(short));
                myfile.read(s.name, length);
                s.name[length] = '\0';
                myfile.read((char *)(&length), sizeof(short));
                myfile >> s.gpa;
                myfile.read((char *)(&length), sizeof(short));
                myfile.read(s.address, length);
                s.address[length] = '\0';
                cout << "student id: " << s.id << endl;
                cout << "student name: " << s.name << endl;
                cout << "student gpa: " << s.gpa << endl;
                cout << "student address: " << s.address << endl;
                break;
            }
        }
        myfile.close();
    }
}
void display()
{

    fstream display;
    display.open("sd.txt");
    while (display.is_open())
    {
        while (!display.eof())
        {
            string p;
            display >> p;

            cout << p << endl;
        }

        display.close();
    }
}

int main()
{
    // please create a txt file called sd first
    int o;
    // cout << "choose if you want to add a student choose 1 -- if you want to search a student by ID choose 2 -- if you want to display all the student choose 3 " << endl;
    cout << "your choise is : ";
    cin >> o;
    if (o == 1)
        add_student();
    else if (o == 2)
        search();
    else if (o == 3)
        display();
    else
        cerr << "error file can't open ..." << endl;
    return 0;
}