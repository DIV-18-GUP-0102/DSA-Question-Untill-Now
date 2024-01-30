/*
268. Missing Number
Solved
Easy

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int s1 = (n * (n + 1)) / 2;
        for (int i : nums) {
            s1 = s1 - i;
        }
        return s1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1}; 

    int missingNum = solution.missingNumber(nums);

    std::cout << "The missing number is: " << missingNum << std::endl;

    return 0;
}
