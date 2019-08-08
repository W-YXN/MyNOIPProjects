#include <iostream>
#include <cstdio>
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
int main()
{
    int map[15][15] = {0};
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    int p[15];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i] = (p[i] << 1) + map[i][j];
        }
    }
    int k = 1 << n;
    int check[5010] = {0};
    for (int i = 0; i < k; i++)
    {
        if (((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0))
        {
            check[i] = 1;
        }
    }
    int tmp[15][5010] = {0};
    tmp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (check[j] && ((j & p[i]) == j))
            {
                for (int u = 0; u < k; u++)
                {
                    if ((u & j) == 0)
                    {
                        tmp[i][j] = (tmp[i][j] + tmp[i - 1][u]) % 100000000;
                    }
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tmp[m][i];
        sum %= 100000000;
    }

    cout << sum << endl;

    return 0;
}
