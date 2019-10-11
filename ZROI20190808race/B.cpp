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

int main()
{
    int t;
    cin >> t;
    int cpt = 0;
    while (t--)
    {
        cpt++;
        int num, mx;
        cin >> num >> mx;
        int cpmx = mx;
        int cnt = 0;
        while (cpmx > 0)
        {
            cpmx /= 2;
            cnt++;
            num--;
        }
        if (num == 1 && cpmx > 1)
        {
            cnt += cpmx;
        }
        cout << "case " << cpt << ": " << cnt << endl;
    }
    return 0;
}

