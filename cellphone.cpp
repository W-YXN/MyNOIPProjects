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

int f[N][2], a[N], hd[N], vis[N], cnt;

void add(int x, int y)
{
    e[++cnt] = (Edge){hd[x], y}, hd[x] = cnt;
}

void dfs(int x, int fa)
{
    f[x][0] = 1, f[x][1] = 0, f[x][2] = 0;

    int flag = 0, inc = 10001;

    for (int i = hd[x]; i; i = e[i].nxt)
    {
        int y = e[i].to;
        if (y != fa)
        {
            dfs(y, x);
            f[x][0] += min(min(f[y][0], f[y][1]), f[y][2]);
            f[x][2] += f[y][1];
            if (f[y][0] <= f[y][1])
            {
                f[x][1] += f[y][0], flag = 1;
            }
            else
            {
                f[x][1] += f[y][1], inc = min(inc, f[y][0] - f[y][1]);
            }
        }
    }
    if (flag == 0)
        f[x][1] += inc;
    cout << x << ' ' << flag << ' ' << f[x][0] << ' ' << f[x][1] << ' ' << f[x][2] << endl;
}
int main()
{
    int n, root;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(y, x), add(x, y);
    }

    dfs(1, 0);
    cout << min(f[1][0], f[1][1]) << endl;
}
