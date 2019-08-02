#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

stringstream ss;

int conv(long long n, long long r)
{
    // bool flag = true;
    // if (n < 0)
    // {
    //     flag = false;
    //     n = 0 - n;
    // }
    // int ret = 0;
    // while (n != 0)
    // {
    //     if ((n % 10) >= r)
    //         return 1000100;
    //     ret *= r;
    //     ret += (n % 10);
    //     n /= 10;
    // }
    // if (!flag)
    //     ret = 0 - ret;
    // return ret;
    int temp=1,num=0;
    while(n!=0)
    {
        if((n%10)>=r)
            return 99999;
        num+=((n%10)*temp);
        temp*=r;
        n/=10;
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    long long p, q, r;
    cin >> p >> q >> r;
    for (int i = 2; i <= 17; i++)
        if (conv(p, i) * conv(q, i) == conv(r, i))
        {
            cout << i << endl;
            return 0;
        }
    cout << 0 << endl;
    return 0;
}
