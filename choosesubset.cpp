#include <iostream>
#include <cstdlib>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

long long num[105] = {0};
long long CC[105][105] = {0};

inline void getCC()
{
    for (int i = 0; i < 105; i++)
    {
        CC[i][0] = 1;
    }
    CC[1][0] = 0;
    CC[1][1] = 0;
    for (int i = 1; i < 105; i++)
    {
        for (int j = 0; j < i; j++)
        {
            CC[i][j] = (CC[i - 1][j - 1] % 1000000009 + CC[i - 1][j] % 1000000009) % 1000000009;
        }
        CC[i][i] = 1;
    }
}

int main()
{
    getCC();
    int n, m, k;
    cin >> n >> m >> k;
    long long *a = new long long int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num[a[i] % k]++;
    }
    long long ans = 0;
    for (int i = 0; i <= k; i++)
    {
        if (num[i] != 0)
        {
            ans += CC[num[i]][m];
            ans %= 1000000009;
        }
    }
    cout << ans << endl;
    return 0000;
}