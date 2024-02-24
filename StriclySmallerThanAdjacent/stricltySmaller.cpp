/*
Write a C++ program that returns the elements in a vector that are strictly smaller than their adjacent left and right neighbours.

Sample Data:
({7, 2 ,5, 3, 1, 5, 6}) -> 2, 1
({1, 2 ,5, 0, 3, 1, 7}) -> 0, 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void toFindPeaksValley_1(vector<int> &nums)
    {
        int diff = nums[0] - nums[1];
        bool mem = signbit(diff);
        for (int i = 1; i < nums.size() - 1; i++)
        {
            diff = nums[i] - nums[i + 1];
            if (mem != signbit(diff))
            {
                cout << nums[i] << " ";
                mem = signbit(diff);
            }
        }
    }
    void toFindPeaksValley_2(vector<int> &nums)
    {

        int diff1 = 0;
        int diff2 = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            diff1 = nums[i] - nums[i - 1];
            diff2 = nums[i] - nums[i + 1];
            if (signbit(diff1) == signbit(diff2))
            {
                cout << nums[i] << " ";
            }
        }
    }
    void toFindValley(vector<int> &nums)
    {
        int diff1 = 0;
        int diff2 = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            diff1 = nums[i - 1] - nums[i];
            diff2 = nums[i] - nums[i + 1];
            if (signbit(diff1) == 0 && signbit(diff2) == 1)
            {
                cout << nums[i] << " ";
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {7, 2, 5, 3, 1, 5, 6};
    vector<int> nums2 = {1, 2, 5, 0, 3, 1, 7};

    cout << "Result for nums1: " << endl;
    cout << "All the corners : ";
    solution.toFindPeaksValley_1(nums1);
    cout << endl;
    cout << "All the Valleys : ";
    solution.toFindValley(nums1);
    cout << endl;

    cout << "Result for nums2: " << endl;
    cout << "All the corners : ";
    solution.toFindPeaksValley_2(nums2);
    cout << endl;
    cout << "All the Valleys : ";
    solution.toFindValley(nums2);
    cout << endl;

    return 0;
}