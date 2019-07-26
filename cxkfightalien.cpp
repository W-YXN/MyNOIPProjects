#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

long long *arr = NULL;
long long ans = 0;
int indx = 1;

void solve(long long a[], int n)
{
    if (indx == n)
        return;
    while (a[indx] > 0 && a[indx + 1] > 0)
    {
        long long t = min(a[indx], a[indx + 1]);
        a[indx] -= t;
        a[indx + 1] -= t;
        ans+=t;
    }
    indx++;
    solve(a, n);
}

int main()
{
    int n;
    cin >> n;
    arr = new long long[n + 2];
    arr[n + 1] = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
    cout << ans;
}