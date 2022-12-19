#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char line[500];
    char search[20];
    int i;

    cout << endl
         << "Student Details" << endl
         << endl;

    ifstream infile;

    infile.open("search.txt");
    cout << "Search: ";
    cin >> search;

    if (infile.is_open())
    {
        while (!infile.eof())
        {
            infile.getline(line, 500, ','); // read first line to first ','
            for (i = 0; line[i] == search[i]; i++)
            {
                if (search[i] == '\0') // if true search and line is same
                {
                    // print all info
                    cout << "Match found!" << endl;
                    cout << line << endl;
                    infile.getline(line, 500, ',');
                    cout << line << endl;
                    infile.getline(line, 500, ',');
                    cout << line << endl;
                    infile.getline(line, 500, ',');
                    cout << line << endl;
                    infile.getline(line, 500, '\n'); // end of line
                    cout << line << endl;
                    return 1;
                }
            }
            // no match
            for (int j = 0; j < 3; j++)
                infile.getline(line, 500, ','); // skip the line
            infile.getline(line, 500, '\n');    // we reach end of line
        }
        cout << "Match not found!" << endl;
    }
    else
    {
        cout << "Unable to open: students.txt" << endl;
    }
    infile.close();
    return 0;
}