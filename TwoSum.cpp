#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: Key = number value, Value = its index
        unordered_map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (num_map.find(complement) != num_map.end()) {
                // If found, return the index of the complement and the current index
                return {num_map[complement], i};
            }
            
            // Otherwise, store the current number and its index in the map
            num_map[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found
        return {};
    }
};

// main function
int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15, 12, 6, 3, 10};
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        cout << "No solution found.\n";
    }   
    return 0;
}
