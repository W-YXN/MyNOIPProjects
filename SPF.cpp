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

typedef struct __EDGE_
{
    int nxt;
    int to;
} edge;

edge e[100010];

int head[100010] = {0}, cnt = 0;

inline void init();

void addEdge(int nodeX, int nodeY)
{
    ++cnt;
    e[cnt].nxt = head[nodeX];
    e[cnt].to = nodeY;
    head[nodeX] = cnt;
}

int dfn[1010], low[1010], fa[1010];
bool visd[100010];

int dn, lw;

void dfs(int root, int father)
{
    dn++;
    lw++;
    visd[root] = true;
    dfn[root] = dn;
    fa[root] = father;
    low[root] = lw;
    // cout << "node " << root << " ,dfn: " << dfn[root] << " ,low: " << low[root] << endl;
    for (int kkksc03 = head[root]; kkksc03; kkksc03 = e[kkksc03].nxt)
    {
        int i = e[kkksc03].to;
        if (i != fa[root])
        {
            if (!visd[i])
            {
                dfs(i, root);
            }
            else
            {
                for (int j = root; j; j = fa[j])
                {
                    low[j] = std::min(low[i], low[j]);
                }
            }
        }
    }
}


int main()
{
    int l;
    init();
    while (cin >> l)
    {
        if (l == 0)
        {
            dfs(1, 0);
            cout << endl;
            cout << "node " << 3 << " ,dfn: " << dfn[3] << " ,low: " << low[3] << endl;
            cout << "node " << 4 << " ,dfn: " << dfn[4] << " ,low: " << low[4] << endl;
            cout << "node " << 5 << " ,dfn: " << dfn[5] << " ,low: " << low[5] << endl;
            cout << "node " << 2 << " ,dfn: " << dfn[2] << " ,low: " << low[2] << endl;
            cout << "node " << 1 << " ,dfn: " << dfn[1] << " ,low: " << low[1] << endl;
        }
        else
        {
            int r;
            cin >> r;
            addEdge(l, r);
            addEdge(r, l);
        }
    }
    return 0;
}

inline void init()
{
    std::memset(dfn, 0, sizeof(dfn));
    std::memset(low, 0, sizeof(low));
    std::memset(fa, 0, sizeof(fa));
    std::memset(head, 0, sizeof(head));
    std::memset(e, 0, sizeof(e));
    std::memset(visd, 0, sizeof(visd));
    cnt = 0;
    // dn = 0;
    // lw = 0;
}