#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define mian main
using namespace std;
int n;
int a[1000010];

bool check(int mid)
{
    int x = a[0] - mid, y;
    for (int i = 1; i < n; ++i)
    {
        y = a[i] - mid;
        if (y <= x)
        {
            y = x + 1;
            if (abs(y - a[i]) > mid)
                return false;
        }
        x = y;
    }
    return true;
}

int mian()
{
    int t;
    int copy_t;
    cin >> t;
    copy_t = t;
    int ans;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            ans = 0;
        }
        else
        {
            int left = 0;
            int right = 1000000;
            int mid;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (check(mid))
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            ans = left;
        }
        cout << "Case #" << copy_t - t << ':' << '\n'
             << ans << endl;
    }

    return 0;
}