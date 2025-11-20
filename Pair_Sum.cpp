#include <iostream>
#include <vector>
using namespace std;

// finding the 2-sum of the array using brute force technique with O(n^2)
void pairSum(vector<int> num, int size, int target)
{
    vector<int> answer;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (num[i] + num[j] == target)
            {
                answer.push_back(num[i]);
                answer.push_back(num[j]);
            }
        }
    }
    if (answer.size() == 0)
    {
        cout << "No subarray found...";
    }
    cout << endl
         << "The subarray with the target is : " << answer[0] << " , " << answer[1];
}

// pair sum by taking pointers from both directions - time complexity = O(n)
void pairSumWithOptimization(vector<int> num, int target)
{
    int n = num.size();
    int i = 0, j = n - 1;
    vector<int> ans;
    while (i < j)
    {
        /* code */
        int pairSum = num[i] + num[j];
        if (pairSum > target)
            j--;
        else if (pairSum < target)
            i++;
        else
        {
            ans.push_back(num[i]);
            ans.push_back(num[j]);
            break;
        }
    }
    
    cout << endl << " -------------------- Pair sum using optimized technique -------------" << endl ;
    if (ans.size() == 0)
    {
        cout << "No subarray found...";
    }
    cout << endl
         << "The subarray with the target is : " << ans[0] << " , " << ans[1];
}

int main()
{
    vector<int> nums = {2, 7, 11, 15, 18, 25};
    // pair sum with first function
    pairSum(nums, nums.size(), 22);

    // pair sum with optimized function
    pairSumWithOptimization(nums, 22);
}




