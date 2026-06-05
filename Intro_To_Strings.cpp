#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void stringBasics()
{
    char str[100];
    cout << "Enter char array: ";
    cin.getline(str, 100, '$');

    cout << "Output: " << str << endl;
}

void StringAdvance() {
    string str = "Apna College";
    string str1 = "apna College";

    // concatination of string
    cout << "Concatination of string: " << (str + str1) << endl;

    // comparision of strings
    cout << "Comparision of strings: " << (str == str1) << endl;
    cout  << "Comparision of strings: " << (str < str1) << endl;

    // string length
    cout << "Length of string: " << str.length() << endl;

    // substring
    cout << "Substring: " << str.substr(2, 5) << endl;

    // reverse of string
    cout << "Reverse of string: " << endl; 
    reverse(str.begin(), str.end()) ;
    cout << str << endl;
}
// main function
int main()
{
    // stringBasics();
    StringAdvance();
    return 0;
}
