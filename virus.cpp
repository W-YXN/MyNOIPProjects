#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

typedef struct __EDGE_
{
    int nxt;
    int to;
} 
edge;

edge e[1000010];

int head[1000010] = {0}, cnt = 0, indegree[1000010] = {0}, viruses[1000010] = {0};

void addEdge(int nodeX, int nodeY)
{
    ++cnt;
    e[cnt].nxt = head[nodeX];
    e[cnt].to = nodeY;
    head[nodeX] = cnt;
}

long long ans = 0;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int ai;
        cin >> ai;
        viruses[ai]++;
        viruses[ai] %= 142857;
    }
    for (int i = 1; i <= m; i++)
    {
        int out, in;
        cin >> out >> in;
        addEdge(out, in);
        indegree[in]++;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (indegree[i] == 0)
    //     {
    //         indegree[i] = 999999999;
    //         for (int j = head[i]; j != 0; j = e[j].nxt)
    //         {
    //             int y = e[j].to;
    //             viruses[y] += viruses[i];
    //             viruses[y] %= 142857;
    //             indegree[y]--;
    //         }
    //         i = 1;
    //         head[i] = 0;
    //     }
    // }
    queue<int> zeros;
    while(!zeros.empty()) zeros.pop();//init

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            zeros.push(i);
        }
    }
    while (!zeros.empty())
    {
        int i = zeros.front();
        zeros.pop();

        ans%=142857;
        ans += (viruses[i]%142857);
        ans %= 142857;

        indegree[i] = -999999999;

        for (int j = head[i]; j != 0; j = e[j].nxt)
        {
            int y = e[j].to;

            viruses[y] += (viruses[i]%142857);
            viruses[y] %= 142857;

            indegree[y]--;
            if (indegree[y] == 0)
            {
                zeros.push(y);
            }
        }
        head[i]=0;
    }
    cout << ans;
    return 0;
}