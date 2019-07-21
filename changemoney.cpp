#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#ifdef max
#undef max
#endif
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
    int n;
    cin >> n;
    double lastmark = 0;
    double lastdollar = 100;
    for (int i = 0; i < n; i++)
    {
        int exchange_rate;
        cin >> exchange_rate;
        double tmp = lastdollar;
        lastdollar = max(lastdollar, (lastmark / exchange_rate * 100));
        lastmark = max(lastmark, (tmp / 100 * exchange_rate));
    }
    cout << std::fixed << std::setprecision(2) << lastdollar << endl;
    return 0;
}