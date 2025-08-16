#include <iostream>
#include <vector>
using namespace std;

void getAllSubArrays(vector<int> vec, int n)
{
    for (int st = 0; st < n; st++)
    {
        for (int end = st; end < n; end++)
        {
            for (int i = st; i < end; i++)
            {
                if (i == end - 1)
                {
                    cout << vec[i] << " ";
                }
                else
                {
                    cout << vec[i] << ",";
                }
            }
            cout << " | ";
        }
        cout << endl;
    }
}

// Maximum sum from a subarray using brute force in O(n^2) time complexity
void Max_SubArray_Sum_Brute(vector<int> vec, int n)
{
    int max_Sum = INT8_MIN;
    for (int st = 0; st < n; st++)
    {
        int current_sum = 0;
        for (int end = st; end < n; end++)
        {
            current_sum += vec[end];
            max_Sum = max(current_sum, max_Sum);
        }
    }
    cout << endl
         << "Maximum Sum of the subArrays : " << max_Sum;
}

// Maximum sum from a subarray using Kadane's Algorithm with O(n) time complexity
void Max_Sum_SubArray_Kadans(vector<int> vec, int n)
{
    int max_Sum = INT8_MIN;
    int current_Sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_Sum += vec[i];
        max_Sum = max(max_Sum, current_Sum);
        if (current_Sum < 0)
        {
            current_Sum = 0;
        }
    }
    cout << endl
         << "The maximum sum of the subarray using Kadan's algorithm is : " << max_Sum << endl;
}

int main()
{
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    getAllSubArrays(vec, vec.size());
    Max_SubArray_Sum_Brute(vec, vec.size());
    Max_Sum_SubArray_Kadans(vec, vec.size());

    return 0;
}