#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

long long int f[110][110][110];

int main()
{
    int n, k;
    cin >> n >> k;
    if (k == n)
    {
        cout << 0 << endl;
        return 0;
    }
    int *a = new int[n + 3];
    std::memset(a, 0, sizeof(a));
    std::memset(f, 0x3f3f, sizeof(f));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int mn = 1e9 + 3;
    // int mx = 0 - mn;
    // for (int i = 0; i < n; i++)
    // {
    //     mn = std::min(mn, a[i]);
    //     mx = std::max(mx, a[i]);
    //     f[i][i][k] = 0;
    //     f[0][i][k] = mx - mn;
    // }
    // // for (int i = 0; i < n; i++)
    // // {
    // //     for (int j = 0; j < n; j++)
    // //     {
    // //         cout << f[i][j] << ' ';
    // //     }
    // //     cout << endl;
    // // }
    // mn = 1e9 + 3;
    // mx = 0 - mn;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     mn = std::min(mn, a[i]);
    //     mx = std::max(mx, a[i]);
    //     f[i][n - 1][k] = mx - mn;
    // }
    // // for (int i = 0; i < n; i++)
    // // {
    // //     for (int j = 0; j < n; j++)
    // //     {
    // //         cout << f[i][j] << ' ';
    // //     }
    // //     cout << endl;
    // // }

    // for (int i = 0; i < n; i++)
    // {
    //     int ck = k;
    //     for (int len = 1; len < n; len++)
    //     {
    //         int j = i + len;
    //         if (j >= n)
    //             continue;
    //         for (int kkk = i; kkk <= j - 1&&ck>=0 ; kkk++)
    //         {
    //             if(ck != 0){
    //                 f[i][j][ck] = std::min(std::min(f[i][j][ck + 1], f[i][j][ck]), f[i][kkk][ck + 1] + f[kkk + 1][j][ck + 1]);
    //             }
    //             else{
    //                 f[i][j][ck] = std::min(f[i][j][ck + 1], f[i][j][ck]);
    //             }
    //         }
    //         // while (j < n)
    //         // {
    //         //     for (int kkk = i; kkk <= j - 1; kkk++)
    //         //     {
    //         //         f[i][j] = std::min(f[i][j], f[i][kkk] + f[kkk + 1][j]);
    //         //     }
    //         //     i++;
    //         //     j++;
    //         // }
    //         ck--;
    //     }
    //     // for (int i = 0; i < n; i++)
    //     // {
    //     //     for (int j = 0; j < n; j++)
    //     //     {
    //     //         cout << f[i][j] << ' ';
    //     //     }
    //     //     cout << endl;
    //     // }
    //     // cout << endl;
    // }

    // // for (int i = 0; i < n; i++)
    // // {
    // //     for (int j = 0; j < n; j++)
    // //     {
    // //         cout << f[i][j] << ' ';
    // //     }
    // //     cout << endl;
    // // } 
    // long long mnnnnn = 0x7ffffffffffffffa;
    // for (int i = 0; i < k; i++)
    // {
    //     mnnnnn = std::min(mnnnnn, f[0][n - 1][i]);
    // }
    // cout << mnnnnn << endl;
    return 0;
}




