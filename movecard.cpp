#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    long long *tmp = new long long;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        *tmp += a[i];
    }
    int num = *tmp / n;
    tmp = nullptr;
    delete tmp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > num)
        {
            a[i + 1] += a[i] - num;
            ans++;
        }
        else if (a[i] < num)
        {
            a[i + 1] -= num - a[i];
            ans++;
        }
        else
            continue;
    }
    cout << ans;
    return 0;
}