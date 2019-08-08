#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int a[110] = {0};
int ans = 0;
int n = 0;

int checkPrime(int x)
{
    int i;
    for (i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}

void dfs(int t, int s, int l)
{
    int i;
    if (t == 3)
    {
        if (checkPrime(s))
            ans++;
    }
    else
        for (i = l; i <= n; i++)
            dfs(t + 1, s + a[i], i + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}

// int main()
// {
//     int n;
//     cin >> n;
//     int *arr = new int[n + 3];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     std::sort(arr, arr + n);
//     int ans = 0;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         for (int k = 0; k < n; k++)
//     //         {
//     //             if(i != j && i != k && j != k){

//     //             }
//     //         }
//     //     }
//     // }
//     return 0;
// }
