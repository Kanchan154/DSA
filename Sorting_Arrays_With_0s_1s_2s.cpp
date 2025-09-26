#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function to print the array
void printArray(vector<int> array)
{
    cout << endl;
    for (int i : array)
    {
        cout << i << "\t";
    }
}

// brute force technique that solve problem with O(nlogn) time complexity and O(1) space complexity
void sort_By_Brute_Force(vector<int> array)
{
    sort(array.begin(), array.end());
    printArray(array);
}

// optimized approach with time complexity O(n) but more space complexity
void sort_By_optimal_tech(vector<int> array)
{
    int count0 = 0, count1 = 0, count2 = 0;
    // O(n)
    for (int i : array)
    {
        if (i == 0)
            count0 += 1;
        else if (i == 1)
            count1 += 1;
        else
            count2 += 1;
    }
    // O(n)
    int index = 0;
    for (int i = 0; i < count0; i++)
    {
        array[index++] = 0;
    }
    for (int i = 0; i < count1; i++)
    {
        array[index++] = 1;
    }
    for (int i = 0; i < count2; i++)
    {
        array[index++] = 2;
    }

    // print the array
    printArray(array);
}

// best optimal solution  ------ Dutch National Flag Algorithm with time complexity O(n) and space complexity O(1)
void sort_by_Dutch_national_flag_algorithm(vector<int> array, int size)
{
    int mid = 0, high = size - 1, low = 0;
    while (mid <= high)
    {
        if (array[mid] == 0)
        {
            swap(array[low], array[mid]);
            low++;
            mid++;
        }
        else if (array[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(array[mid], array[high]);
            high--;
        }
    }

    // print the array
    printArray(array);
}

int main()
{
    vector<int> array = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    sort_By_Brute_Force(array);
    sort_By_optimal_tech(array);
    sort_by_Dutch_national_flag_algorithm(array, array.size());

    return 0;

}
