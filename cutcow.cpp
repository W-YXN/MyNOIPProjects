#include <iostream>
#include <cstdlib>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

int *cows;
int n;

bool judge(int len, int num)
{
    int k = 1;
    int tp = cows[0] + len;
    for (int i = 1; i < n; i++)
    {
        if (cows[i] < tp)
        {
            continue;
        }
        else
        {
            k++;
            tp = cows[i] + len;
        }
    }
    return (k >= num);
}

int main()
{
    int c;
    cin >> n >> c;
    cows = new int[n + 3];
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    sort(cows, cows + n);
    int l = 0, r = cows[n - 1] - cows[0];
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (judge(mid, c))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid;
    }
    cout << ans << endl;
    return 0;
}
