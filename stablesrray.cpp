#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))

long long n,t,a [300010];

bool judge(long long num,int n)
{
    long long t = 0, k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= num)
            t -= (num - a[i]);
        else
            t += (a[i] - num) / 2;
    }
    if (t >= 0)
        return true;
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        ios::sync_with_stdio(false);
        cin >> n;
        long long l = 0, r = 0;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            r = max(r, a[i]);
        }
        long long ans = 0;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            if (judge(mid,n))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid;
        }
        cout << ans << endl;
    }
    return 0;
}


