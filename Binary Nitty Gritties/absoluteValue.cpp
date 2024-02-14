#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int absFunc(int n)
    {
        uint32_t temp = n >> 31;
        n ^= temp;
        n += temp & 1;
        return n;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution solution;
    int ans = solution.absFunc(n);
    cout << ans;
}