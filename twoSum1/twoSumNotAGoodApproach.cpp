/*
Challenging test cases:

if I have a vector wich have two 0s and the target = 0 (accomplished)
or,
if the target = a and the vector contains {....,a,0,....} (not accomplished)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(const vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, upperbound = n - 1, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                upperbound = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return upperbound;
    }

    int lowerBound(const vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, lowerbound = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
            {
                lowerbound = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return lowerbound;
    }

    int bsearch(const vector<int> &nums, int comp, int start, int end)
    {
        int low = start, high = end;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == comp)
            {
                return mid;
            }
            else if (nums[mid] > comp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    vector<int> twoSum(const vector<int> &nums, int target)
    {
        vector<int> vec;
        int lowerbound, upperbound, start, end;
        lowerBound(nums, target);
        if (target < 0)
        {
            upperbound = upperBound(nums, target);
            start = upperbound;
            end = nums.size() - 1;
            cout << "The upper bound of " << target << " lies at " << upperbound << " which is " << nums[upperbound] << endl;
        }
        else
        {
            lowerbound = lowerBound(nums, target);
            if (target != 0)
            {
                start = 0;
                end = lowerbound;
            }
            else
            {
                start = lowerbound + 1;
                end = nums.size() - 1;
            }
            cout << "The lower bound of " << target << " lies at " << lowerbound << " which is " << nums[lowerbound] << endl;
        }
        for (int i = start; i <= end; i++)
        {
            int complimentary = target - nums[i];
            int ans = bsearch(nums, complimentary, i + 1, end);
            if (ans != -1)
            {
                if (ans < i)
                {
                    vec.push_back(ans + 1);
                    vec.push_back(i + 1);
                    cout << "The 2 indices are " << ans + 1 << " and " << i + 1 << endl;
                }
                else
                {
                    vec.push_back(i + 1);
                    vec.push_back(ans + 1);
                    cout << "The 2 indices are " << i + 1 << " and " << ans + 1 << endl;
                }

                break;
            }
        }
        cout << endl;
        return vec;
    }
};

int main()
{
    Solution solution;
    cout << "----------------------------------------" << endl;

    // Define a vector of pairs containing the numbers vector and target value
    vector<pair<vector<int>, int>> testCases = {
        {{4, 4, 8, 11, 15}, 8},
        {{-15, -11, -9, -9, -7, -2}, -9},
        {{0, 1, 1, 3, 4}, 4},
        {{-1, 0, 0, 3, 4}, 0},
        {{1, 2, 3, 4, 4}, 8},
        {{-1, 0}, -1}};

    // Loop through each test case
    for (const auto &testCase : testCases)
    {
        const vector<int> &numbers = testCase.first;
        int target = testCase.second;

        // Call the twoSum function with the current test case
        vector<int> result = solution.twoSum(numbers, target);

        // Output the result
        cout << "Input: numbers = [";
        for (int i = 0; i < numbers.size(); ++i)
        {
            cout << numbers[i];
            if (i != numbers.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "], target = " << target << endl;

        cout << "Output: [";
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
            if (i != result.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
