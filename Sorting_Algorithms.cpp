#include <iostream>
#include <vector>

using namespace std;

// print array function
void printArray(vector<int> array, int size)
{
    cout << "The array is \n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}

// bubble sort with time complexity of O(n^2)
void bubbleSort(vector<int> array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        { // array is sorted
            break;
        }
    }
    printArray(array, size);
}

// selection sort with time complexity of O(n^2)
void selectionSort(vector<int> array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(array[i], array[smallestIdx]);
    }
    printArray(array, size);
}

// insertion sort with time complexity of O(n^2)
void insertionSort(vector<int> &array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int curr = array[i], prev = i - 1;
        while (prev >= 0 && array[prev] < curr)
        {
            array[prev + 1] = array[prev];
            prev--;
        }
        array[prev + 1] = curr;     // placing the current to its current position
    }
    printArray(array, size);
}
int main()
{
    vector<int> array = {10, 45, 71, 25, 16, 29, 35};
    bubbleSort(array, array.size());
    selectionSort(array, array.size());
    insertionSort(array, array.size());
    return 0;
}
