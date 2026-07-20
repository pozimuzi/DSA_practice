// Problem: Two Sum (return values, not indices)
// Pattern: Two Pointer
// Time: O(n log n) - due to sorting | Space: O(1) - no extra map needed
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // sort first, safe since we only need values

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return {nums[left], nums[right]};  // found the pair
            }
            else if (sum < target) {
                left++;   // sum too small, need bigger value → move left pointer up
            }
            else {
                right--;  // sum too big, need smaller value → move right pointer down
            }
        }

        return {};  // no pair found
    }
}; 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}