#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// #ifndef MAXN
// #define MAXN 500010
// #endif

// int v[MAXN];
// int merge_countInversion(int arr[], int l, int r)
// {
//     if (l == r)
//         return 0;
//     int mid = (l + r) >> 1;
//     int ans = merge_countInversion(arr, l, mid) + merge_countInversion(arr, mid + 1, r);
//     int p = l, j = l, k = mid + 1;
//     while (j <= mid && k <= r)
//     {
//         if (arr[j] > arr[k])
//         {
//             ans += mid - j + 1;
//             v[p++] = arr[k++];
//         }
//         else
//             v[p++] = arr[j++];
//     }
//     while (j <= mid)
//         v[p++] = arr[j++];
//     while (k <= r)
//         v[p++] = arr[k++];
//     for (int i = l; i <= r; i++)
//         arr[i] = v[i];
//     return ans;
// }

// #ifdef MAXN
// #undef MAXN
// #endif

// int main()
// {
//     int n;
//     while (cin >> n && n)
//     {
//         int *arr = new int[n + 3];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int num = merge_countInversion(arr, 0, n-1);
//         cout<<num<<endl;
//     }
//     return 0;
// }

const int maxn = 500010;
int a[maxn];
int t[maxn];

void merge_sort(int x, int y, long long int &ans)
{
    if (y - x > 1)
    {
        int m = x + (y - x) / 2;
        int p = x, q = m, i = x;
        merge_sort(x, m, ans);
        merge_sort(m, y, ans);
        while (p < m || q < y)
        {
            if (q >= y || p < m && a[p] <= a[q])
            {
                t[i++] = a[p++];
            }
            else
            {
                t[i++] = a[q++];
                ans += m - p;
            }
        }
        for (int j = x; j < y; j++)
        {
            a[j] = t[j];
        }
    }
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int ans = 0;
        merge_sort(0, n, ans);
        cout << ans << endl;
    }
    return 0;
}