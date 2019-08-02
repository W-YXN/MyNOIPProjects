#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int N = 10010, M = 10010;

typedef struct __EDGE_
{
    int nxt;
    int to;
} edge;

edge e[M];

int head[N] = {0}, cnt = 0, weight[N] = {0}, father[N] = {0};

int dp[10010][2] = {0};

void addedge(int nodeX, int nodeY)
{
    ++cnt;
    e[cnt].nxt = head[nodeX];
    e[cnt].to = nodeY;
    head[nodeX] = cnt;
    father[nodeY] = nodeX;
}

void dfs(int root, int daddy)
{
    dp[root][1] += 1;
    //cout<<root<<endl;
    //cout<<head[root]<<endl;
    for (int i = head[root]; i; i = e[i].nxt)
    {
        //cout<<root<<" : ";
        int y = e[i].to;
        //cout<<y<<' '<<endl;
        if (y != daddy)
        {
            dfs(y, root);
            //cout<<y<<" - "<<dp[y][0]<<' '<<dp[y][1]<<endl;
            dp[root][0] += std::max(dp[y][0], dp[y][1]);
            dp[root][1] += dp[y][0];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(true);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n;
    while (cin >> n && n != EOF)
    {
        cnt = 0;
        std::memset(dp, 0, sizeof(dp));
        std::memset(head, 0, sizeof(head));
        std::memset(father, 0, sizeof(father));
        std::memset(e, 0, sizeof(e));
        for (int i = 1; i <= n; i++)
        {
            int node, num;

            std::scanf("%d:(%d)", &node, &num);
            
            for (int j = 0; j < num; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                addedge(node + 1, tmp + 1);
            }
        }
        int fth;
        for (int i = 1; i <= n; i++)
        {
            if (head[i] == 0)
            {
                dp[i][0] = 0;
            }
            if (father[i] == 0)
                fth = i;
        }
        dfs(fth, 0);
        int kkksc03 = std::max(dp[fth][0], dp[fth][1]);
        int chen_zhe = n - kkksc03;
        cout << chen_zhe << endl;
    }
    return 0;
}
