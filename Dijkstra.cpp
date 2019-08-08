#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include<queue>
using namespace std;

int Dijkstra(int graph, int LEN,int start)
{
    int *vis = new int[LEN];
    int *dist = new int[LEN];
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return dist[a] > dist[b];
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    fill(dist, dist + LEN, 0x3f3f3f3f);
    dist[s] = 0;
    while (1)
    {
        int u = -1, d = 0x3f3f3f3f;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i] && dist[i] < d)
            {
                d = dist[i];
                u = i;
            }
        }
        if (u < 0)
            break;
        vis[u] = 1;
        for (int i = 0; i < N; i++)
            if (!vis[i])
            {
                if (dist[u] + g[u][i] < dist[i])
                {
                    dist[i] = dist[u] + g[u][i];
                }
            }
    }
}