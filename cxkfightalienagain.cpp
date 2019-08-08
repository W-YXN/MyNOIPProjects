#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

// typedef pair<int, int> __P_;
// int mind[1000010] = {0};

// int main()
// {
//     priority_queue<__P_, vector<__P_>, greater<__P_> > pq;
//     int n;
//     cin >> n;
//     int *arr = new int[n + 5];
//     fill(arr, arr + n + 5, 0);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         __P_ tmp = make_pair(arr[i], i);
//         pq.push(tmp);
//     }
//     while (!pq.empty())
//     {
//         __P_ ppp = pq.top();
//         int val = ppp.first();
//         int indx = ppp.second();
//         if(indx == 0){

//         }
//     }
//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 5];
    fill(arr, arr + n + 5, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}