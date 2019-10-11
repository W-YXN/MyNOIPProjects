#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int n, k;
int ropes[10010] = {0};

bool check(int len)
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += (ropes[i] / len);
    }
    return (tot >= k);
}

int find(int l, int r, int n)
{
    //nothing to do
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        double tmp;
        cin >> tmp;
        //cout << tmp;
        ropes[i] = (tmp * 100);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ropes[i + 1];
    // }
    int l = 0;
    int r = 1e8 + 10;
    int res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (mid == 0)
            break; //Very Important!!!!!!!!!!!
        // if (check(mid))
        //     r = mid - 1;
        // else
        // {
        //     l = mid + 1;
        //     res = mid;
        // }
        if (!check(mid))
            r = mid - 1;
        else
        {
            l = mid + 1;
            res = mid;
        }
    }
    double ans = (res * 1.0) / 100.0;
    cout << std::fixed << std::setprecision(2) << ans << endl;
    return 0;
}