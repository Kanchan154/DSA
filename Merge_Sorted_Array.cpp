#include <iostream>
#include <vector>
using namespace std;

/*
    * Given 2 arrays are sorted.
    * merge the arrays so that the merged arrays are also sorted.
*/    

// function to print the array
void printArray(vector<int> &array)
{
    for (int i : array)
    {
        cout << i << "\t";
    }
}

// function that is used to merge the arrays with O(1) space and O(n+m) time complexity
void merge(vector<int> &nums1, int m, vector<int> nums2, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[idx--] = nums1[i--];
        }
        else
        {
            nums1[idx--] = nums2[j--];
        }
    }
    while (j >= 0)
    {
        nums1[idx--] = nums2[j--];
    }
    printArray(nums1);
}

int main()
{
    vector<int> nums1 = {10, 14, 21};
    vector<int> nums2 = {5, 8, 13, 19};

    merge(nums1, nums1.size(), nums2, nums2.size());

    return 0;
}

