#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDup(vector<int> &vec)
    {
        int slow = 0;

        for (int fast = 1; fast < vec.size(); fast++)
        {
            if (vec[fast] != vec[slow])
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

        // vec.resize(slow + 1);
        return slow + 1;
    }
};

int main()
{
    Solution s;
    vector<int> vec1 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> vec2 = {1, 1, 1, 2, 2, 3};
    vector<int> vec3 = {1, 1};

    int a1 = s.removeDup(vec1);
    int a2 = s.removeDup(vec2);
    int a3 = s.removeDup(vec3);

    cout << "Modified vector 1: ";
    for (int i = 0; i < a1; i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;

    cout << "Modified vector 2: ";
    for (int i = 0; i < a2; i++)
    {
        cout << vec2[i] << " ";
    }
    cout << endl;

    cout << "Modified vector 3: ";
    for (int i = 0; i < a3; i++)
    {
        cout << vec3[i] << " ";
    }
    cout << endl;

    return 0;
}
