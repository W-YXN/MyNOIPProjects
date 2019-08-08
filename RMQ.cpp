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

int rmq[2000010][30];

int checkRmq(int l, int r)
{
    int k = log2(r - l + 1);
    return std::min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

// typedef struct __EDGE_
// {
//     int nxt;
//     int to;
// } edge;

// edge e[100010];

// int head[100010] = {0}, cnt = 0;

// void addEdge(int nodeX, int nodeY)
// {
//     ++cnt;
//     e[cnt].nxt = head[nodeX];
//     e[cnt].to = nodeY;
//     head[nodeX] = cnt;
// }

int main()
{
    std::ios::sync_with_stdio(false);
    std::memset(rmq, 0x3f3f3f3f, sizeof(rmq));
    int n;
    cin >> n;
    int *arr = new int[n + 3];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i + 1];
        rmq[i + 1][0] = arr[i + 1];
    }
    for (int j = 1; (1 << j - 1) <= n + 3; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            rmq[i][j] = (i + (1 << j - 1)) <= n + 3 ? std::min(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]) : rmq[i][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << checkRmq(l, r) << endl;
    }
    return 0;
}
/*
5
3 4
2 8
2 4
6 8
7 10

 */