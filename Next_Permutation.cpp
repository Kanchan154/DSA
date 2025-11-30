#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
return lexicographically next
Given an array ex: [1,2,3],
Then the possible permutation are:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
so now the next permutation for [1,2,3] is [1,3,2]
*/

/**
 * Brute force approach can give the time complexity of O(n!*n)
 * The solution will be obtained by finding all the permutation using brute force approach
 * and the find the current array and then select the enxt array
 */

// optimal approach to get the solution with Time complexity of o(n) and space o(1)

/**
 * step - 1: Find the pivot element using loop, and if the pivot element is -1, (the array is sorted backward already, then arrange the array in ascending order)
 * step - 2: Swap the values of the last element to the pivot element
 * step - 3: Reverse the elements
 **/

// print the array
void printArray(vector<int> array)
{
    for (int i : array)
    {
        cout << i << "\t";
    }
}

// function to get the next permutation
void next_Permtation_Arrangemnet(vector<int> &array)
{
    // step - 1: find the pivot
    int n = array.size(), pivot = -1;
    for (int i = n - 2; i > 0; i--)
    {
        if (array[i] < array[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        // reverse the array
        reverse(array.begin(), array.end()); // in place changes
        printArray(array);
        return;
    }

    // step - 2: next larger element
    for (int i = n - 1; i > pivot; i--)
    {
        if (array[i] > array[pivot])
        {
            swap(array[i], array[pivot]);
            break;
        }
    }

    // step - 3: Reverse (piv+1 to n-1)
    reverse(array.begin() + pivot + 1, array.end());
    // print the array
    printArray(array);
    return;
}

int main()
{
    vector<int> array = {1, 4, 5, 3, 2};
    next_Permtation_Arrangemnet(array);

    // can also use alternative function
    next_permutation(array.begin(), array.end());
    printArray(array);

    return 0;
}
