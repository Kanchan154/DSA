#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// Element that occurs more than floor(n/2) times in an array using brute-force approach - O(n^2)
void majorityElements(vector<int> arr)
{
    int element = -1;
    for (int i : arr)
    {
        int freq = 0;
        for (int d : arr)
        {
            if (d == i)
                freq++;
        }
        if (freq > arr.size() / 2)
        {
            cout << endl
                 << "Majority Element is : " << i << endl;
            element = i;
            break;
        }
    }
    if (element == -1)
    {
        cout << endl
             << "No majority element." << endl;
    }
}

int majorityElementsUsingSorting(vector<int> arr)
{
    // sort the array
    sort(arr.begin(), arr.end());

    int element = arr[0];
    int freq = 1;
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            freq++;
            element = arr[i - 1];
        }
        else
        {
            freq = 1;
            element = arr[i];
        }
        if (freq > n / 2)
        {
            cout << endl
                 << "Majority Element is : " << element << endl;
            break;
        }
    }
    if (element == arr[arr.size() - 1] && !(freq > n / 2))
    {
        cout << endl
             << "No majority element." << endl;
    }
}

void Moores_Voting_Alogorthm(vector<int> arr)
{
    int element = -1, freq = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            element = arr[i];
        }
        if (arr[i] == element)
            freq++;
        else
            freq--;
    }

    cout << endl
         << "Majority Element is : " << element << endl;
}
int main()
{
    vector<int> arr = {1, 2, 2, 1, 2, 1, 2, 2, 2, 3, 3};
    majorityElements(arr);

    majorityElementsUsingSorting(arr);
    Moores_Voting_Alogorthm(arr);

    return 0;
}