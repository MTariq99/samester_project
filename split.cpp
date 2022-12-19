//

// #include <bits/stdc++.h>
// using namespace std;
// void removeDupWord(string str)
// {
//     istringstream ss(str);
//     string word;
//     while (ss >> word)
//     {
//         cout << word << "\n";
//     }
// }
// int main()
// {
//     string str = "Geeks for Geeks";
//     removeDupWord(str);
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     string str = "Geeks forGeeks is a computer science portal";

//     // ignore the whitespaces in the string
//     string word = "";
//     for (auto x : str)
//     {
//         if (x != ' ')
//             word = word + x;
//         else
//         {
//             // print the searched word
//             if (word == "computer")
//                 cout << word << endl;
//             word = "";
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    int i = 0, j = 0;

    // iterate through the string
    while (sentence[i] != '\0')
    {

        // ignore all whitespaces
        if (sentence[i] != ' ')
            j = i;
        i++;
    }

    // print the next word
    while (sentence[j] != ' ' && sentence[j] != '\0')
    {
        cout << sentence[j];
        j++;
    }

    return 0;
}
