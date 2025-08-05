#include <iostream>
using namespace std;

// 1 - print basic pattern
void basic_number_pattern(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << j << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// 2 - basic alphabet print
void print_basic_alphabet(int n)
{
    for (char i = 0; i < n; i++)
    {
        for (char j = 0; j < n; j++)
        {
            cout << char(j + 65) << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

// 3 - Basic number series
void basic_number_series(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << num << '\t';
            num++;
        }
        cout << endl;
    }
    cout << endl;
}

// 4 - Triangle Pattern
void triangle_pattern(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

// 5 - Triangle Problem with numbers
void Triangle_Numbers(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1 << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // reverse number
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i - j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // Floids Triangle
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;
}

// Inverted Triangle Pattern
void inverted_triangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = i; j < n; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    cout << endl;
}
int main()
{
    basic_number_pattern(5);
    print_basic_alphabet(4);
    basic_number_series(5);
    triangle_pattern(5);
    Triangle_Numbers(5);
    inverted_triangle(5);
    return 0;
}