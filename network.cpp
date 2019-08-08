#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
//#include <queue>
using namespace std;

int dis[55][55];
int points;
int dir[55];
bool visd[55];
// int lowc[55],addn[55];
// int adjc[55];

// bool visd[55];

// typedef struct ___TO_{
//     int len;
//     int to;
// } to;
// struct cmp{
//     bool operator()(const to& lhs,const to& rhs){
//         return lhs.len>rhs.len;
//     }
// };

int kruskal(int x)
{
    memset(dir, 0x3f3f3f3f, sizeof(dir));
    memset(visd, 0, sizeof(visd));
    dir[x] = 0;
    int ans = 0;
    for (int i = 1; i <= points; i++)
    {
        int u = -1, MIN = 0x3f3f3f3f;
        for (int j = 1; j <= points; j++)
        {
            if (visd[j] == 0 && dir[j] < MIN)
                MIN = dir[j], u = j;
        }
        ans += MIN;
        visd[u] = 1;
        for (int z = 1; z <= points; z++)
        {
            if (visd[z] == 0 && dis[u][z] < dir[z])
                dir[z] = dis[u][z];
        }
    }
    return ans;
}

// int prim(int start){
//     int DSSQ = 0;
//     for (int i = 1; i < points +1; i++)
//     {
//         lowc[i] = dis[start][i];
//     }

//     addn[start] = 0;
//     adjc[start] = start;

//     for (int i = 1; i < points; i++)
//     {
//         int mini = 0x7ffffff0;
//         int visd = -1;
//         for (int j = 1; j < points+1; j++)
//         {
//             if(addn[j]!=-1&&lowc[j]<min){
//                 mini = lowc[j];
//                 visd = j;
//             }
//         }
//         if(visd!=-1){
//             addn[visd] = 0;

//             DSSQ += lowc[visd];
//             for (int j = 1; j <points+1; j++)
//             {
//                 if(addn[j]==-1&&dis[visd][j]<lowc[j]){
//                     lowc[j] = dis[visd][j];
//                     adjc[j] = visd;
//                 }
//             }

//         }
//     }
//     return DSSQ;
// }

int main()
{
    int paths;
    while (cin >> points && points != 0)
    {
        // priority_queue<to,vector<to>,cmp> pq;
        cin >> paths;
        memset(dis, 0x3f3f, sizeof(dis));
        //memset(visd,0,sizeof(visd));
        if (points == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < paths; i++)
        {
            int a, b, tdis;
            cin >> a >> b >> tdis;
            dis[a][b] = min(dis[a][b], tdis);
            dis[b][a] = dis[a][b];
        }
        // memset(lowc,0,sizeof(lowc));
        // memset(addn,-1,sizeof(addn));
        // memset(adjc,0,sizeof(adjc));
        int ans = kruskal(1);
        // to ttttt;
        // ttttt.len = 0;
        // ttttt.to = 1;
        // pq.push(ttttt);
        // long long ans = 0;
        // while(!pq.empty()){
        //     to tmp = pq.top();
        //     pq.pop();

        // }
        cout << ans << endl;
    }
    return 0;
}