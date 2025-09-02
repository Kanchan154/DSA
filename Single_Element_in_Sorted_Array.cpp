#include <iostream>
#include <vector>

using namespace std;

void single_Element_using_Optimization(vector<int> &array)
{
    int start = 0, n = array.size(), end = array.size() - 1, mid;
    // case where there is only single element in the array.......
    if (array.size() == 1)
    {
        cout << "Single Element is " << array[0] << " at index : " << 0 << endl;
        return;
    }
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        // for first element
        if (mid == 0 && array[0] != array[1])
        {
            cout << "Single Element is " << array[0] << " at index : " << 0 << endl;
            break;
        }
        // for last element
        if (mid == n - 1 && array[n - 1] != array[n - 2])
        {
            cout << "Single Element is " << array[mid] << " at index : " << mid << endl;
            break;
        }
        else if (array[mid] != array[mid + 1] && array[mid] != array[mid - 1])
        {
            cout << "Single Element is " << array[mid] << " at index : " << mid << endl;
            break;
        }
        // check if the size of search space is even
        else if (mid % 2 == 0)
        {
            // check where should we have to search whether right or left part
            if (array[mid] == array[mid - 1])
                end = end - 1;
            else
                start = start + 1;
        }
        // check the size of search space is odd
        else
        {
            // check where should we have to search whether right or left part
            if (array[mid] == array[mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
}

int main()
{
    vector<int> array = {3, 3, 7, 7, 8, 8, 10, 13, 13};
    single_Element_using_Optimization(array);
    return 0;
}
