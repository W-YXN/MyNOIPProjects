#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return (gcd(y, x % y));
}

int main()
{
    int p, q;
    while (cin >> p >> q)
    {
        cout << ((p + q) - gcd(p, q)) << endl;
    }
}