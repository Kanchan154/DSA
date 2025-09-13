#include <iostream>
using namespace std;

// Binary Exponential
/**
 * if n is a decimal number then we have atmost log2(n) + 1 digits in its binary form
 * if n = 8, then it have log2(8) binary digits in its binary form
 */
void myPow(double x, int n)
{
    // Corner cases for the expressions
    if (n == 0)
    {
        cout << "the result is : " << 1.0 << endl;
        return;
    }
    if (x == 0)
    {
        cout << "The result is : " << 0.0 << endl;
        return;
    }
    if (x == 1)
    {
        cout << "The result is : " << 1.0 << endl;
        return;
    }
    if(x == -1 && n%2 == 0) {
        cout << "The result is : " << 1.0 << endl;
        return;
    } 
    if(x == -1 && n%2 != 0) {
        cout << "The result is : " << -1.0 << endl;
        return;
    } 

    long binForm = n;
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }
    double ans = 1;

    while (binForm > 0)
    {
        /* code */
        if (binForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }
    
    cout << "the result is : " << ans << endl;
}
int main()
{
    myPow(5,5);

}
