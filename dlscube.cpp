#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

long long nums[2][1010] = {0};
long long cons[1010] = {0};
long long cols[1010] = {0};
long long lslash = 0, rslash = 0;

int main()
{
    int n;
    cin >> n;
    bool flag = false;
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    int zx, zy;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> nums[j][i];
            if (nums[j][i] == 0)
            {
                zx = j;
                zy = i;
            }
            cons[j] += nums[j][i];
            cols[i] += nums[j][i];
            if (j == i)
                rslash += nums[j][i];
            if (i + j + 1 == n)
                lslash += nums[j][i];
        }
    }
    long long ans;
    for (int i = 1; i < n; i++)
    {
        if (cons[i - 1] != cons[i] && i - 1 != zx && i != zx)
        {
            cout << -1 << endl;
            return 0;
        }
        if (cols[i - 1] != cols[i] && i - 1 != zy && i != zy)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (zx == 0)
    {
        ans = cons[1] - cons[zx];
        cons[zx] += ans;
        cols[zy] += ans;
    }
    else
    {
        ans = cons[0] - cons[zx];
        cons[zx] += ans;
        cols[zy] += ans;
    }
    if (zx == zy)
        rslash += ans;
    if (zx + zy + 1 == n)
        lslash += ans;
    if (!((rslash == lslash) && (lslash == cons[0])))
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}