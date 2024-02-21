#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(const vector<int> &nums, int target)
    {
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
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
