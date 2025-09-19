#include <iostream>
#include <vector>

using namespace std;

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
void bubbleSort(vector<int> &array, int size)
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

void insertionSort(vector<int> &array)
{
}
int main()
{

    vector<int> array = {10, 45, 71, 125, 160, 229, 355};
    bubbleSort(array, array.size());
    return 0;
}