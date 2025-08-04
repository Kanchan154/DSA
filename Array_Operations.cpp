#include <iostream>
#include <math.h>
using namespace std;

void array_smallest_largest()
{
    int arr[5];
    int size = sizeof(arr) / sizeof(int);

    // Array printing
    cout << endl
         << "Array : " << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
        cout << arr[i] << "\t";
    }

    // check for the largest and smallest number in the array
    int small = arr[0];
    int large = arr[0];

    // smallest
    for (int i = 0; i < size; i++)
    {
        if (small < arr[i])
        {
            small = arr[i];
        }
    }

    // large
    for (int i = 0; i < size; i++)
    {
        if (large > arr[i])
        {
            large = arr[i];
        }
    }

    cout << endl
         << endl
         << "Largest number in the array is " << large << endl;
    cout
        << "Smallest number in the array is " << small << endl;

    // to find index of smallest number
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == small)
        {
            cout << "The index of the smallest number is : " << i << endl;
            break;
        }
    }

    // to find index of largest number
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == large)
        {
            cout << "The index of the largest number is : " << i << endl;
            break;
        }
    }
}

void changeArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 2 * arr[i];
    }
}

// Linear Search
int linear_Search(int arr[], int size)
{
    int key = 0;
    cout << endl
         << "Enter the value you want to search : ";
    cin >> key;
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

// Binary Search

// reversing the array
void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}

// sum and product of array
void sum_product(int arr[], int size)
{
    int sum = 0;
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        product *= arr[i];
    }

    cout << endl
         << "The sum of all the values of the array is : " << sum << endl;
    cout << endl
         << "The product of all the values of the array is : " << product << endl;
}

// swap max and min element of the array
void swap_min_max(int arr[], int size)
{
    int small = arr[0];
    int large = arr[0];

    // smallest
    for (int i = 0; i < size; i++)
    {
        if (small < arr[i])
        {
            small = arr[i];
        }
    }

    // large
    for (int i = 0; i < size; i++)
    {
        if (large > arr[i])
        {
            large = arr[i];
        }
    }
    // swapping the elements

    // now print the array
    cout << endl
         << "New array is : " << endl;
    // printing the new array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}

// print all unique values of the array
void uniqueValues(int arr[], int size)
{
    // first sort the array
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // array with unique values
    cout << endl
         << "Array with unique values : " << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            cout << arr[i] << "\t";
        }
    }
}

// intersection of 2 arrays
void intersection_of_arrays(int arr1[], int arr2[], int size)
{
    cout << endl << "Intersection of both the arrays" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << "\t";
                break;
            }
        }
    }
}

int main()
{
    // getting the smallest and largest element in the array
    array_smallest_largest();

    int arr1[] = {90, 88, 158, 136, 52, 52};
    int arr2[] = {45, 44, 78, 69, 26, 44};
    int size = sizeof(arr2) / sizeof(int);

    // Changing the value of the elements of the array
    // printing the old array
    cout << endl
         << "Old array is : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << "\t";
    }

    changeArray(arr2, size);

    // printing array here
    cout << endl
         << "New array is : " << endl;
    // printing the new array
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << "\t";
    }

    // linear search
    int index = linear_Search(arr2, size);
    if (index == -1)
    {
        cout << "Element not found.." << endl;
    }
    else
    {
        cout << "Element found in index : " << index << endl;
    }

    // reverse of the array
    reverseArray(arr2, size);
    // printing reversed array here
    cout << endl
         << "New Reversed array is : " << endl;
    // printing the new array
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << "\t";
    }

    sum_product(arr1, size);
    swap_min_max(arr1, size);
    uniqueValues(arr1, size);
    intersection_of_arrays(arr1,arr2,size);

    return 0;
}