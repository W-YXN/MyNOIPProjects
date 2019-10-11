#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 610;
int sqrs[maxn][maxn] = {0};

int main()
{
    int n,q;
    scanf("%d %d", &n,&q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &sqrs[i][j]);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int code;
        scanf("%d", &code);
        if (code == 1)
        {
            int ai, aj, num;
            scanf("%d %d %d", &ai, &aj, &num);
            sqrs[ai][aj] = num;
        }
        if (code == 2)
        {
            int ai1, ai2;
            scanf("%d %d", &ai1, &ai2);
            for (int j = 0; j < n + 1; j++)
            {
                swap(sqrs[ai1][j], sqrs[ai2][j]);
            }
        }
        if (code == 3)
        {
            int ai1, ai2;
            scanf("%d %d", &ai1, &ai2);
            for (int j = 0; j < n + 1; j++)
            {
                swap(sqrs[j][ai1], sqrs[j][ai2]);
            }
        }
        if (code == 4)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    printf("%d ", sqrs[i][j]);
                }
                puts("");
            }
            puts("");
        }
    }
    return 0;
}