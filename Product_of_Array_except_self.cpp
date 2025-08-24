#include <iostream>
#include <vector>
using namespace std;

// using brute force approach
void product_of_array(vector<int> array)
{
    vector<int> productArray(array.size(), 1);
    for (int i = 0; i < array.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < array.size(); j++)
        {
            if (i != j)
            {
                productArray[i] *= array[j];
            }
        }
    }
    for (int i : productArray)
    {
        cout << i << "\t";
    }
}

// using optimized solution
void product_of_array_using_Optimizaation(vector<int> array)
{
    vector<int> prefix(array.size(), 1);
    vector<int> suffix(array.size(), 1);
    vector<int> ans(array.size(), 1);
    for (int i = 1; i < array.size(); i++)
    {
        prefix[i] = prefix[i - 1] * array[i - 1];
    }
    
    for (int i = array.size() - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * array[i + 1];
    }
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = suffix[i] * prefix[i];
    }
    
    cout << endl;
    // print result
    for (int i : ans)
    {
        cout << i << "\t";
    }
}

// using optimized way with both space and time complexity
void product_of_array_using_space_and_time_Optimizaation(vector<int> array)
{
    vector<int> ans(array.size(), 1);
    int suffix = 1;
    for (int i = 1; i < array.size(); i++)
    {
        ans[i] = ans[i-1] * array[i-1];
    }
    
    for (int i = array.size() - 2; i >= 0; i--)
    {
        suffix *= array[i+1];
        ans[i] *= suffix;
    }
    
    cout << endl;
    // print result
    for (int i : ans)
    {
        cout << i << "\t";
    }
}


int main()
{
    vector<int> array = {1, 2, 3, 4};
    product_of_array(array);
    product_of_array_using_Optimizaation(array);
    product_of_array_using_space_and_time_Optimizaation(array);
    return 0;
}