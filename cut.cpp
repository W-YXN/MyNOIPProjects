#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

long long ans = 0;

int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    while (!q.empty())
    {
        int a = q.top();
        q.pop();
        if (!q.empty())
        {
            int b = q.top();
            q.pop();
            int cnt = a + b;
            ans += (a + b);
            q.push(cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
