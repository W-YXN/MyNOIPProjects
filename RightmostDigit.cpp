#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

long long quick_algorithm(long long a, long long b, long long c)
{
    a = a % c;
    long long ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        long long num;
        cin >> num;
        if (num == 0 || num == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            cout << quick_algorithm(num, num, 10) << endl;
        }
    }
    return 0;
}