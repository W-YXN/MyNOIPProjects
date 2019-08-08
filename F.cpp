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

typedef long long ll;

ll qpow(int a, int b, int p)
{
    ll res = 1 % p;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
    }
    return res;
}
ll mul(ll a, ll b, ll p)
{
    ll res = 0;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = (res + a) % p;
        a = (a << 1) % p;
    }
    return res;
}

int main()
{
    int n, k, a;
    int ttt = 0;
    while (cin >> n >> k >> a && k && n && a)
    {
        ttt ++;
        cout<<"Case "<<ttt<<":"<<endl;
        int c;
        cin >> c;
        for (int i = 0; i < c; i++)
        {
            int p;
            cin >> p;
            ll pw = qpow(k, n, p);
            ll ans = mul(pw, a, p);
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}
