#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decToBin(int dec)
    {
        string binary = "";
        while (dec > 0)
        {
            binary = (dec % 2 == 0 ? "0" : "1") + binary;
            dec /= 2;
        }
        return binary;
    }
    string decToBin2(int dec)
    {
        if (dec == 0)
        {
            return "0";
        }
        else if (dec == 1)
        {
            return "1";
        }
        return decToBin2(dec / 2) + (dec % 2 == 0 ? "0" : "1");
    }
};

int main()
{
    Solution solution;
    int arr[7] = {12, 23, 34, 45, 56, 67, 89};
    string ans = solution.decToBin(arr[5]);
    cout << ans << endl;
    ans = solution.decToBin2(arr[5]);
    cout << ans << endl;
}