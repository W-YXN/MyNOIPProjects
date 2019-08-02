#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return (gcd(y, x % y));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long holes, jumps;
        cin >> holes >> jumps;
        // vector<long long> v;
        // v.push_back(0);
        // long long cur = jumps % holes;
        // // cerr<<"cur="<<cur<<endl;
        // // cerr<<"cnt="<<count(v.begin(), v.end(), cur)<<endl;
        // while (!count(v.begin(), v.end(), cur))
        // {
        //     v.push_back(cur);
        //     cur += jumps;
        //     cur %= holes;
        //     // cerr<<"cur="<<cur<<endl;
        //     // cerr<<"cnt="<<count(v.begin(), v.end(), cur)<<endl;
        // }
        // // cerr<<"SIZE="<<v.size()<<endl;
        // if (v.size() < holes)
        // {
        //     cout << "YES" << endl;
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }
        if (gcd(holes, jumps) == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}