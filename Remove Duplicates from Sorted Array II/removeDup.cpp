#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void removeDup(vector<int> &vec)
    {
        int slow = 0;

        for (int fast = 1; fast < vec.size(); fast++)
        {
            if (vec[fast] != vec[slow]) // Add condition if (vec[fast] != vec[slow] || fast == vec.size() - 1) to prevent heap-buffer-overflow error
            {
                vec[++slow] = vec[fast];
            }
            else
            {
                if (vec[fast + 1] != vec[slow])
                {
                    vec[++slow] = vec[fast];
                }
            }
        }

        vec.resize(slow + 1);
    }
};

int main()
{
    Solution s;
    vector<int> vec1 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> vec2 = {1, 1, 1, 2, 2, 3};
    vector<int> vec3 = {1, 1, 1};

    s.removeDup(vec1);
    s.removeDup(vec2);
    s.removeDup(vec3);

    // Output the modified vectors
    cout << "Modified vector 1: ";
    for (int num : vec1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Modified vector 2: ";
    for (int num : vec2)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Modified vector 1: ";
    for (int num : vec3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
A heap-buffer-overflow error occurs when the program is trying to read or write memory outside the bounds of a dynamically allocated heap buffer.
*/