#include <iostream>

using namespace std;

// check if the character is alpha numeric
bool isAlphaNumeric(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}

// function that checks for the valid palindrome
bool valid_Palindrome()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    int st = 0, end = str.length() - 1;
    while (st < end)
    {
        // check for alphanumber character at the start
        if (!isAlphaNumeric(str[st]))
        {
            st++;
            continue;
        }
        // check for alphanumber character at the end
        if (!isAlphaNumeric(str[end]))
        {
            end--;
            continue;
        }

        if (tolower(str[st]) != tolower(str[end]))
        { 
            return false;
        }
        st++;
        end--;
    }
    return true;
}

// main function
int main()
{
    bool result = valid_Palindrome();
    result ? cout << "String is palindrome..." : cout << "String is not palindrome...";
    return 0;
}
