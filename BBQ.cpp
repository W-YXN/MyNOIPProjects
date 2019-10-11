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

long long __gcd(long long a, long long b)
{
    long long t;
    while (b)
    {
        t = b;
        b = (a % b);
        a = t;
    }
    return a;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    cout << (k / __gcd(n, k)) << '/' << (n / __gcd(n, k)) << endl;
    return 0;
}