#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// #ifdef min
// #undef min
// #endif
// #define min(a,b) (((a)<(b))?(a):(b))
// #ifdef max
// #undef max
// #endif
// #define max(a,b) (((a)>(b))?(a):(b))

const int N = 5010, M = 5010;

// typedef struct __EDGE_
// {
//     int nxt;
//     int to;
// } edge;

// edge e[M];

// int len[M] = {0};
// int head[N] = {0}, cnt = 0, weight[N] = {0}, father[N] = {0};

// void addedge(int nodeX, int nodeY)
// {
//     ++cnt;
//     e[cnt].nxt = head[nodeX];
//     e[cnt].to = nodeY;
//     head[nodeX] = cnt;
//     father[nodeY] = nodeX;
//     len[nodeX]++;
// }

int maps[151][151];

typedef struct _____Edge__
{
    int x, y;
} edge;

edge ans[5010];

int dfn[200], low[200], father[200];
int dfnTimes;
int cnt = 0;

void addedge(int x, int y)
{
    ans[++cnt].x = x;
    ans[cnt].y = y;
}

// void dfs(int root, int daddy)
// {
//     for (int i = head[root]; i; i = e[i].nxt)
//     {
//         int y = e[i].to;
//         if (y != daddy)
//         {
//             dfs(y, root);
//             //do something
//         }
//     }
// }

bool cmp(edge a, edge b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

// int dfnTimes, dfn[N], vis[N], low[N];
// edge ans[M];

// void tarjan(int cur, int fa)
// {
//     dfn[cur] = dfnTimes;
//     dfnTimes++;
//     low[cur] = dfn[cur];
//     for (int i = 0; i < len[cur]; i++)
//     {
//         int kkk;
//         for (int k = head[cur], j = 0; k && j < i; k = e[k].nxt)
//         {
//             kkk = k;
//         }
//         if (dfn[kkk] && kkk != fa)
//             low[cur] = std::min(low[cur], dfn[kkk]);
//         if (!dfn[kkk])
//         {
//             tarjan(kkk, cur);
//             if (dfn[cur] < low[kkk])
//             {
//                 ans[std::min(kkk, cur)].to = std::max(kkk, cur);
//             }
//             low[cur] = std::min(low[cur], low[kkk]);
//         }
//     }
// }

int global_n;

void tarjan(int x)
{
    int y;
    ++dfnTimes;
    dfn[x] = low[x] = dfnTimes;
    for (int i = 1; i <= global_n; i++)
    {
        if (maps[x][i])
        {
            y = i;
            if (dfn[y] != 0 && y != father[x])
            {
                low[x] = std::min(low[x], dfn[y]);
            }
            if (!dfn[y])
            {
                father[y] = x;
                tarjan(y);
                low[x] = std::min(low[x], low[y]);
                if (low[y] > dfn[x])
                {
                    addedge(x, y);
                }
            }
        }
    }
}

// int dfnTimes,dfn[N],vis[N],low[N];

// int fackStack[N],top=0;
// bool instack[N];

// typedef std::pair<int,int> cutedge;
// std::vector<cutedge> ce;

// void tarjan(int u)
// {
// 	dfnTimes++;
// 	dfn[u]=dfnTimes;
// 	low[u]=dfnTimes;
// 	vis[u]=true;
// 	instack[u]=true;
// 	fackStack[top]=u;
// 	top++;
// 	for(int i=head[u];i;i=e[i].nxt)
// 	{
// 		int y=e[i].to;
// 		if(!vis[y])
// 		{
// 			tarjan(y);
// 			low[u]=min(low[u],low[y]);
// 		}
// 		else
// 			if(instack[y]==true)
// 			{
// 				low[u]=min(low[u],dfn[y]);
// 			}
// 	}

// 	if(low[u]==dfn[u])
// 	{
// 		while(top>0&&fackStack[top]!=u)
// 		{
// 			top--;
// 			instack[fackStack[top]]=false;
// 		}
//         ce.push_back(std::make_pair(min(u,father[u]),max(u,father[u])));
// 	}
// }

int main()
{
    // std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    global_n = n;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        // addedge(a, b);
        // addedge(b, a);

        maps[a][b] = 1;
        maps[b][a] = 1;
    }

    // tarjan(1);
    // std::sort(ce.begin(),ce.end());
    // for (auto it = ce.begin();it != ce.end();it++)
    // {
    //     cout<<it->first<<' '<<it->second<<endl;
    // }

    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
            tarjan(i);
    }

    // for (int i = 1; i <= n; i++)
    //     if (dfn[i] == 0)
    //     {
    //         tarjan(i, i);
    //     }
    // for (int i = 0; i < m; i++)
    // {
    //     if (ans[i].to)
    //     {
    //         cout << i << ' ' << ans[i].to << endl;
    //     }
    // }
    std::sort(ans+1,ans+cnt+1,cmp);
    for(int i=1; i<=cnt; i++) {
        cout<<std::min(ans[i].x,ans[i].y)<<' '<<std::max(ans[i].x,ans[i].y)<<endl;
    }
    return 0;
}
