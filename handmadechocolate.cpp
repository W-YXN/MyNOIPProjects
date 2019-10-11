#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

long long v[510][510] = {0}, h[510][510] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    long long l;
    cin >> n >> m >> l;
    long long maxh = -10000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> h[i][j];
            maxh = std::max(maxh, h[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            l -= v[i][j];
            l -= (maxh - h[i][j]);
            if (l < 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    long long kkk = m * n;
    l /= kkk;
    maxh += l;
    cout << maxh << endl;
    return 0;
}
