#include <string>
#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define MAX_L 20005
using namespace std;

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

unsigned long long hh = 0, mm = 0, ss = 0;
unsigned long long stars = 0, mods = 0, sharps = 0, ats = 0;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char tmp;
            cin >> tmp;
            while (tmp == '\n' || tmp == '\r')
            {
                cin >> tmp;
            }
            if (tmp == '.')
            {
                //Nothing to do.
            }
            else if (tmp == '*')
            {
                stars++;
            }
            else if (tmp == '%')
            {
                mods++;
            }
            else if (tmp == '#')
            {
                sharps++;
            }
            else if (tmp == '@')
            {
                ats++;
            }
        }
    }
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    char trush;
    cin >> hh >> trush >> mm >> trush >> ss;
    sharps += ats * c;
    mods += sharps * b;
    stars += mods * a;
    mm += stars;
    hh += mm / 60;
    mm = mm % 60;
    unsigned long long DD = hh / 24;
    hh = hh % 24;
    cout << DD << endl;
    cout << fixed << setw(2) << setfill('0') << hh << setw(1) << ':' << setw(2) << setfill('0') << mm << setw(1) << ':' << setw(2) << setfill('0') << ss << endl;
    return 0;
}
