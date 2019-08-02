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

const int N = 100010, M = 100010;

typedef struct __EDGE_
{
    int nxt;
    int to;
} edge;

edge e[M];

int head[N] = {0}, cnt =0 , weight[N] = {0},father[N] = {0};

int dp[10010][2];


void addedge(int nodeX, int nodeY)
{
    ++cnt;
    e[cnt].nxt = head[nodeX];
    e[cnt].to = nodeY;
    head[nodeX] = cnt;
    father[nodeY] = nodeX;
}

void dfs(int root,int 啊daddy){
    dp[root][1]+= weight[root];
    //cout<<root<<endl;
    //cout<<head[root]<<endl;
    for (int i = head[root]; i; i = e[i].nxt){
        //cout<<root<<" : ";
		int y = e[i].to;
        //cout<<y<<' '<<endl;
		if (y != 啊daddy){
			dfs(y, root);
            //cout<<y<<" - "<<dp[y][0]<<' '<<dp[y][1]<<endl;
			dp[root][0] += std::max(dp[y][0], dp[y][1]);
			dp[root][1] += dp[y][0];
		}
	}
}

int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>weight[i];
    }
    for (int i = 1; i < n; i++)
    {
        int l,k;
        cin>>l>>k;
        addedge(k,l);
    }
    int fth;
    for (int i = 1; i <= n; i++)
    {
        if(head[i]==0) {
            dp[i][0] = 0;
        }
        if(father[i]==0) fth = i;
    }
    dfs(fth,0);
    cout<<std::max(dp[fth][0],dp[fth][1]);
    // cout<<dp[fth][0]<<dp[fth][1];
    return 0;
}