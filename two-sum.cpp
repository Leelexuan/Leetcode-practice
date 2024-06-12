#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //left pointer
        int l = 0;
        //right pointer
        int r = static_cast<int>(nums.size()) - 1;

        int sum = 0;

        vector<int> indices;

        vector<int> nums_copy = nums;
        
        //sort the vector in ascending order
        sort(nums.begin(), nums.end());

        while (l != r && sum != target) {
            sum = nums[l] + nums[r];

            if (sum < target) {
                l += 1;
            } else if (sum > target) {
                r -= 1;
            } else if (sum == target) {
                auto value_l = find(nums_copy.begin(), nums_copy.end(), nums[l]);
                int index_l = distance(nums_copy.begin(), value_l);
                auto value_r = find(nums_copy.begin() + index_l + 1, nums_copy.end(), nums[r]);
                int index_r = distance(nums_copy.begin(), value_r);
                indices.push_back(index_l);
                indices.push_back(index_r);
            }
        } 
        return indices;
    }
};

void testTwoSum(vector<int> nums, int target) {
    
    // Create an instance of the Solution class
    Solution solution;

    // Call the twoSum function
    vector<int> result = solution.twoSum(nums, target);

    // Print the result vector
    cout << "Indices of the two numbers that add up to target: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {

    vector<int> nums1 = {2, 11, 7, 15};   
    vector<int> nums2 = {3,3};   
    vector<int> nums3 = {3,2,4};   

    int target1 = 9;
    int target2 = 6;
    int target3 = 5;

    // Run the test case
    testTwoSum(nums1, target1);
    testTwoSum(nums2, target2);
    testTwoSum(nums3, target3);

    return 0;

}