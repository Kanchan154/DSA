#include <iostream>
#include <vector>
using namespace std;

void setVector()
{
    vector<int> vec;                 // initializing vector with size 0
    vector<int> vec1 = {1, 2, 3, 4}; // vector with passing the values
    vector<int> vec2(5, 4);          // vector with giving the parameters ---- size and value at each index
    // for each loop to print vector
    for (int val : vec2)
    {
        cout << val << "\t";
    }
}

void vector_functions(vector<int> vec)
{
    // size of the vector
    cout << endl
         << "Size of the vector : " << vec.size() << endl;
    // capacity of the vector
    cout << endl
         << "Capacity of the vector : " << vec.capacity() << endl;

    // pushing the element in the vector
    vec.push_back(45);

    // print size after push back
    cout << endl
         << "Size of the vector after push-back : " << vec.size() << endl;
    // printing the capacity of the vector after the push-back function
    cout << endl
         << "Capacity of the vector after push back : " << vec.capacity() << endl;
    // print elements of the vector using for-each loop
    for (int val : vec)
    {
        cout << val << "\t";
    }
    cout << endl;

    // pop element in the vector
    vec.pop_back();

    // print size after pop back
    cout << endl
         << "Size of the vector after pop-back : " << vec.size() << endl;

    // print elements of the vector using for-each loop
    for (int val : vec)
    {
        cout << val << "\t";
    }
    cout << endl;

    // print the starting value of the vector
    cout << "Front element of the vector : " << vec.front() << endl;

    // print the last element of the vector
    cout << "Back element of the vector : " << vec.back() << endl;

    // print the element at a given index
    int index;
    cout << "Enter the index between 0 and " + vec.size() - 1;
    cin >> index;
    if (index > vec.size() - 1 || index < 0)
    {
        cout << "Enter a valid index";
        return;
    }
    cout << "Element at index " << index << " is : " << vec.at(index) << endl;
}

int getSingleNumberValue(vector<int>& vec){
    int num = 0;
    for(int val: vec){
        num = num ^ val;
    }
    return num;
}
int main()
{
    setVector();

    vector<int> vec = {1, 47, 47, 85, 78, 47, 78, 85};
    vector_functions(vec);
    int num = getSingleNumberValue(vec);
    cout << endl << "The Signle Values number is : " << num << endl;

    return 0;
} 

