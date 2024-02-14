#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {-123, 4, 234, -234, -3442};
    for (int i = 0; i < 5; i++)
        cout << ~(arr[i] - 1) << endl;
}