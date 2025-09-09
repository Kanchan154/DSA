#include <iostream>
#include <vector>

using namespace std;

void binary_Search(vector<int> array, int target)
{
    int start = 0, end = array.size() - 1;
    bool found = false;
    while (start <= end)
    {
        // prevent the overflow of the integer value by optimizing the calculation
        int mid = start + (end - start) / 2;
        // if targer is less than middle element, then search the element in the first half
        if (array[mid] > target)
        {
            end = mid - 1;
        }
        // if the target element is greater than middle element, then search the element in the second half
        else if (array[mid] < target)
        {
            start = start + 1;
        }
        // if element was found
        else
        {
            cout << "Element found at index : " << mid;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << endl
             << "Element not found" << endl;
    }
}

// binary search using recursion
int binarySearch_usingRecursion(vector<int> array, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (array[mid] > target)
    {
        return binarySearch_usingRecursion(array, target, start, mid - 1);
    }
    else if (array[mid] < target)
    {
        return binarySearch_usingRecursion(array, target, mid + 1, end);
    }
    else
    {
        return mid;
    }
    return -1;
}

int main()
{
    vector<int> array = {-1, 0, 3, 4, 5, 9, 12};
    int target;
    cout << endl
         << "Enter the target value : ";
    cin >> target;
    binary_Search(array, target);

    cout << endl << "***********--------- Binary Search using recursion ---------------**********";
    int index = binarySearch_usingRecursion(array, target, 0, array.size() - 1);
    cout << endl
         << "Element found in index : " << index;
    return 0;

}
