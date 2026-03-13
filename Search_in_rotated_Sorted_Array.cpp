#include <iostream>
#include <vector>

using namespace std;

// function to sort array in a rotated array
void rotated_Sorted_Array(vector<int> array)
{
    int start = 0, end = array.size() - 1;
    int mid, found = false, target;
    cout << "Enter the target value: ";
    cin >> target;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (array[mid] == target)
        {
            cout << endl
                 << "Element found at index: " << mid;
            found = true;
            break;
        }
        else if (array[start] <= array[mid])
        { // left sorting
            if (array[start] < target && array[mid] > target)
            { // search in left side
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (array[start] >= array[mid])
        { // search in right
            if (array[mid] < target && array[end] > target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    if (!found)
    {
        cout << "Element not found...." << endl;
    }
}

int main()
{
    vector<int> array = {3, 4, 5, 6, 7, 0, 1, 2};
    rotated_Sorted_Array(array);
    return 0;
}
