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

int n, m;

int mymap[20][20], calculate[20][20], out[20][20];

int direction[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int f(int x, int y)
{
    int temp = mymap[x][y];

    for (int i = 0; i < 5; i++)
    {
        int xi = x + direction[i][0];
        int yi = y + direction[i][1];

        if (xi < 1 || xi > n || yi < 1 || yi > m)
        {
            continue;
        }

        temp += calculate[xi][yi];
    }
    return temp % 2;
}

int dfs()
{
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f(i - 1, j))
                calculate[i][j] = 1;

    for (int i = 1; i <= m; i++)
        if (f(n, i))
            return -1;

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res += calculate[i][j];
    return res;
}

int main()
{
    //int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> mymap[i][j];
            }
        }
        bool flag = 0;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 1 << m; i++)
        {
            std::memset(calculate, 0, sizeof(calculate));

            for (int j = 1; j <= m; j++)
                calculate[1][m - j + 1] = i >> (j - 1) & 1;
            int cont = dfs();

            if (cont >= 0 && cont < ans)
            {
                flag = 1;
                ans = cont;
                // for (int k = 0; k < sizeof(calculate); k++)
                // {

                // }
                std::memcpy(out, calculate, sizeof(calculate));
            }
        }
        if (!flag)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j != 1)
                        cout << " ";
                    cout << out[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}