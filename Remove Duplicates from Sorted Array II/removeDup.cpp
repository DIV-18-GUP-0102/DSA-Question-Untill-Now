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

        vec.resize(slow + 1);
    }
};

int main()
{
    Solution s;
    vector<int> vec1 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> vec2 = {1, 1, 1, 2, 2, 3};

    s.removeDup(vec1);
    s.removeDup(vec2);

    // Output the modified vectors
    cout << "Modified vector 1: ";
    for (int num : vec1)
    {
        cout << num << " ";
        class Solution
        {
        public:
            int removeDuplicates(vector<int> &vec)
            {
                int mem = 0;
                int ind = 0;
                int arr[2] = {-1, -1};

                for (int i = 0; i < vec.size(); i++)
                {
                    // cout << arr[0] << " " << arr[1] << endl;
                    if (arr[1] == vec[i])
                    {
                        mem = i;
                        while (vec[i] == arr[1])
                        {
                            i++;
                        }
                        i--;
                    }
                    else
                    {
                        if (ind == 2)
                        {
                            ind = 0;
                        }
                        arr[ind] = vec[i];
                        cout << "mem = " << mem << " i = " << i << endl;
                        cout << "arr[mem] = " << vec[mem] << " arr[i] = " << vec[i] << endl;
                        vec[mem] = vec[i];
                        cout << "arr[mem] = " << vec[mem] << endl;
                        ind++;
                        mem++;
                    }
                }
                return mem;
            }
        };
    }
    cout << endl;

    cout << "Modified vector 2: ";
    for (int num : vec2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
