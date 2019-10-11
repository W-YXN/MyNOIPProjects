#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

long long judge(long long a, long long b, long long c)
{
    //TODO: Complete it all.
    long long ma = a / 3, mb = b / 2, mc = c / 2;
    long long kkksc03 = std::min(std::min(ma, mb), mc);
    a -= kkksc03 * 3;
    b -= kkksc03 * 2;
    c -= kkksc03 * 2;
    kkksc03 *= 7;
    for (long long i = 1; (a > 0 || b > 0 || c > 0); i++)
    {
        switch (i)
        {
        case 1:
            if (a > 0)
            {
                a--;
                kkksc03++;
                break;
            }
            else
                return kkksc03;
        case 2:
            if (b > 0)
            {
                b--;
                kkksc03++;
            }
            else
                return kkksc03;
            break;
        case 3:
            if (c > 0)
            {
                c--;
                kkksc03++;
            }
            else
                return kkksc03;
            break;
        case 4:
            if (a > 0)
            {
                a--;
                kkksc03++;
                break;
            }
            else
                return kkksc03;
        case 5:
            if (c > 0)
            {
                c--;
                kkksc03++;
                break;
            }
            else
                return kkksc03;
        case 6:
            if (b > 0)
            {
                b--;
                kkksc03++;
                break;
            }
            else
                return kkksc03;
        case 7:
            if (a > 0)
            {
                a--;
                kkksc03++;
                i = 0;
                break;
            }
            else
                return kkksc03;
        default:
            break;
        }
    }
    return kkksc03;
}
/* a b c a c b a */
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = 0ll - 0x7ffff0;
    for (long long i = 1; i <= 7; i++)
    {
        long long days = 0;
        if (i == 1)
        {
            //std::cerr<<i<<endl;
            days = judge(a, b, c);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
        else if (i == 2)
        {
            //std::cerr<<i<<endl;
            days -= 1;
            days += judge(a + 1, b, c);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
        else if (i == 3)
        {
            //std::cerr<<i<<endl;
            days -= 2;
            days += judge(a + 1, b + 1, c);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
        else if (i == 4)
        {
            //std::cerr<<i<<endl;
            days -= 3;
            days += judge(a + 1, b + 1, c + 1);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
        else if (i == 5)
        {
            //std::cerr<<i<<endl;
            days -= 4;
            days += judge(a + 2, b + 1, c + 1);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
        else if (i == 6)
        {
            //std::cerr<<i<<endl;
            days -= 5;
            days += judge(a + 2, b + 1, c + 2);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
        else if (i == 7)
        {
            //std::cerr<<i<<endl;
            days -= 6;
            days += judge(a + 2, b + 2, c + 2);
            ans = std::max(ans, days);
            //std::cerr << days << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
