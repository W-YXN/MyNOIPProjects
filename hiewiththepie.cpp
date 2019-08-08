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

int dp[1 << 13][13];
int dis[13][13];

int main()
{

    int n;
    while (cin >> n && n != EOF && n != 0)
    {
        std::memset(dp, -1, sizeof(dp));
        std::memset(dis, 0x3f3f, sizeof(dis));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cin >> dis[i][j];
            }
        }
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                for (int k = 0; k < n + 1; k++)
                {
                    if (dis[i][k] + dis[k][j] < dis[i][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
        dp[1][0] = 0;
        for (int st = 0; st < (1 << (n + 1)); st++)
        {
            st = st | 1;
            for (int i = 0; i <= n; i++)
            {
                if (dp[st][i] != -1)
                {
                    for (int j = 0; j <= n; j++)
                    {
                        if (j == i)
                            continue;
                        if (dp[st | (1 << j)][j] == -1)
                            dp[st | (1 << j)][j] = dp[st][i] + dis[i][j];
                        else
                            dp[st | (1 << j)][j] = std::min(dp[st | (1 << j)][j], dp[st][i] + dis[i][j]);
                    }
                }
            }
        }
        cout << dp[(1 << (n + 1)) - 1][0] << endl;
    }
    return 0;
}