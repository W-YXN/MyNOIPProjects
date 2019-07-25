#include <iostream>
#include <cstdlib>
#include <cmath>
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

edge e[1000010];

int head[1000010] = {0}, edgecnt = 0;

void addEdge(int nodeX, int nodeY)
{
    ++edgecnt;
    e[edgecnt].nxt = head[nodeX];
    e[edgecnt].to = nodeY;
    head[nodeX] = edgecnt;
}

int main()
{

    return 0;
}
