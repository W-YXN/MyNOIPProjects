#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#ifdef min
#undef min
#endif
#define min(a,b) (((a)<(b))?(a):(b))
#ifdef max
#undef max
#endif
#define max(a,b) (((a)>(b))?(a):(b))

const int N = 5010, M = 5010;

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
    for (int i = head[root]; i; i = e[i].nxt)
    {
        int y = e[i].to;
        if (y != daddy)
        {
            dfs(y, root);
            //do something
        }
    }
}

int dfnTimes,dfn[N],vis[N],low[N];


int fackStack[N],top=0;
bool instack[N];

typedef std::pair<int,int> cutedge;
std::vector<cutedge> ce;

void tarjan(int u)
{
	dfnTimes++;
	dfn[u]=dfnTimes;
	low[u]=dfnTimes;
	vis[u]=true;
	instack[u]=true; 
	fackStack[top]=u;
	top++;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(!vis[y])
		{
			tarjan(y); 
			low[u]=min(low[u],low[y]);
		}
		else 
			if(instack[y]==true)
			{
				low[u]=min(low[u],dfn[y]);
			}
	}
	
	if(low[u]==dfn[u])
	{
		while(top>0&&fackStack[top]!=u)
		{
			top--;
			instack[fackStack[top]]=false;
		}
        ce.push_back(std::make_pair(min(u,father[u]),max(u,father[u])));
	}
}

int main()
{
    // std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        addedge(a,b);
        addedge(b,a);
    }
    tarjan(1);
    std::sort(ce.begin(),ce.end());
    for (auto it = ce.begin();it != ce.end();it++)
    {
        cout<<it->first<<' '<<it->second<<endl;
    }
    return 0;
}


