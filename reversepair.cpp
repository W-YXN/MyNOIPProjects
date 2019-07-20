#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#ifndef MAXN
#define MAXN 100010
#endif

int v[MAXN];
int merge_countInversion(int arr[], int l, int r)
{
    if (l == r)
        return 0;
    int mid = (l + r) >> 1;
    int ans = merge_countInversion(arr, l, mid) + merge_countInversion(arr, mid + 1, r);
    int p = l, j = l, k = mid + 1;
    while (j <= mid && k <= r)
    {
        if (arr[j] > arr[k])
        {
            ans += mid - j + 1;
            v[p++] = arr[k++];
        }
        else
            v[p++] = arr[j++];
    }
    while (j <= mid)
        v[p++] = arr[j++];
    while (k <= r)
        v[p++] = arr[k++];
    for (int i = l; i <= r; i++)
        arr[i] = v[i];
    return ans;
}

#ifdef MAXN
#undef MAXN
#endif

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<' ';
    // }cout<<endl;
    int ans = merge_countInversion(a, 0, n - 1)-1;
    cout << ans;
    return 0;
}