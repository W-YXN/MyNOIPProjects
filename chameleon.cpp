#include <iostream>
#include <cstdlib>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

int land[2010][2010] = {0};
int ans[2010][2010] = {0};

void solve(int x, int y, int current)
{
    if (land[x][y] == -1)
        return;
    else
    {
        if (current < ans[x][y])
            ans[x][y] = current;
        land[x][y] = -1;
        if (land[x - 1][y] == land[x][y])
            solve(x - 1, y, current);
        else
            solve(x - 1, y, current + 1);
        if (land[x + 1][y] == land[x][y])
            solve(x + 1, y, current);
        else
            solve(x + 1, y, current + 1);
        if (land[x][y - 1] == land[x][y])
            solve(x, y - 1, current);
        else
            solve(x, y - 1, current + 1);
        if (land[x][y + 1] == land[x][y])
            solve(x, y + 1, current);
        else
            solve(x, y + 1, current + 1);
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n + 3; i++)
    {
        land[i][0] = -1;
        land[i][m + 1] = -1;
    }
    for (int i = 0; i < m + 3; i++)
    {
        land[0][i] = -1;
        land[n + 1][i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> land[i][j];
        }
    }
    solve(x, y, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}