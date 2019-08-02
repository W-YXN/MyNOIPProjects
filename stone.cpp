#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int sum[150];
int f1[150][150];
int f2[150][150];
int n;
int main()
{
    while (cin >> n)
    {
        sum[0] = 0;
        std::memset(f1, 0x3f, sizeof(f1));
        std::memset(f2, 0, sizeof(f2));
        for (int i = 1; i <= n; i++)
        {
            cin >> sum[i];
            sum[i] += sum[i - 1];
            f1[i][i] = 0;
        }
        for (int l = 2; l <= n; l++)
        {
            int i = 1;
            int j = l;
            while (j <= n)
            {
                for (int k = i; k <= j - 1; k++)
                {
                    f1[i][j] = std::min(f1[i][j], f1[i][k] + f1[k + 1][j] + sum[j] - sum[i - 1]);
                    f2[i][j] = std::max(f2[i][j], f2[i][k] + f2[k + 1][j] + sum[j] - sum[i - 1]);
                }
                i++;
                j++;
            }
        }
        cout << f1[1][n] << ' ' << f2[1][n]<<endl;
    }
    return 0;
}