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

edge e[2 * M];

int head[N] = {0}, cnt = 0, weight[N] = {0}, father[N] = {0};

int f[10010][3] = {0};

void addedge(int nodeX, int nodeY)
{
    ++cnt;
    e[cnt].nxt = head[nodeX];
    e[cnt].to = nodeY;
    head[nodeX] = cnt;
    //father[nodeY] = nodeX;
}
void dfs(int x, int fa)
{
    f[x][0] = 1, f[x][1] = 0, f[x][2] = 0;

    int flag = 0, inc = 10001;

    for (int i = head[x]; i; i = e[i].nxt)
    {
        int y = e[i].to;
        if (y != fa)
        {
            dfs(y, x);
            f[x][0] += std::min(std::min(f[y][0], f[y][1]), f[y][2]);
            f[x][2] += f[y][1];
            if (f[y][0] <= f[y][1])
            {
                f[x][1] += f[y][0], flag = 1;
            }
            else
            {
                f[x][1] += f[y][1], inc = std::min(inc, f[y][0] - f[y][1]);
            }
        }
    }
    if (!flag)
        f[x][1] += inc;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        addedge(a, b);
        addedge(b, a);
    }
    // int fth;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (head[i] == 0)
    //     {
    //         f[i][0] = 0;
    //     }
    //     if (father[i] == 0)
    //         fth = i;
    // }
    dfs(1, 0);
    cout << std::min(f[1][0], f[1][1]) << endl;
    return 0;
}