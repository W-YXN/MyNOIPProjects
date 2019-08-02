#include <iostream>
#include <cstdlib>
#include <iomanip>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

long long cp[23];
inline void get_cp()
{
    cp[1] = 0ll;
    cp[2] = 1ll;
    for (int i = 3; i <= 22; i++)
        cp[i] = (i - 1) * (cp[i - 2] + cp[i - 1]);
}

long long cc[23];
inline void get_cc()
{
    cc[1] = 1ll;
    cc[2] = 2ll;
    for (int i = 3; i <= 22; i++)
        cc[i] = cc[i - 1] * i;
}

int main()
{
    get_cc();
    get_cp();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m;
        cout << std::fixed << std::setprecision(2) << (double(cp[m]) / double(cc[m])) * 100.00 << '%' << endl;
    }
    return 0;
}

