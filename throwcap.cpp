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

int n, m;
int arr[100010];

bool check(int num)
{
    int result = 1, last = arr[1];
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] - last > num)
            last = arr[i], result++;
    }
    return result >= m;
}


int main()
{
    cin >> n >> m;
    int l = 0, r = 2147483000;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    std::sort(arr + 1, arr + n + 1);
    r = arr[n] - arr[1];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    int ans = l;
    cout << ans << endl;
    return 0;
}