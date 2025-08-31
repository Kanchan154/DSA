#include <iostream>
#include <vector>

using namespace std;

void Peak_Element_Index(vector<int> &array)
{
    int start = 1, end = array.size() - 2, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (array[mid] > array[mid - 1] && array[mid] > array[mid + 1])
        {
            cout << "Peak element is : " << array[mid] << " at index : " << mid << endl;
            break;
        }
        else if (array[mid] > array[mid - 1])
        {
            start = mid + 1;
        }
        else if (array[mid] < array[mid - 1])
        {
            end = mid - 1;
        }
    }
}
int main()
{
    vector<int> array = {-5, -1, 1, 2, 4, 6, 7, 10, 8, 6, 5, 0, -2};
    Peak_Element_Index(array);
    return 0;
}