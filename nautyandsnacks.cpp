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

// int main()
// {
//     long long a, b;
//     cin >> a >> b;
//     int c = (b / 2) * 3;
//     if (a == 0 && b == 0)
//     {
//         cout << "0 0" << endl;
//     }
//     else if (a == c)
//     {
//         cout << a / 3 << ' ' << 0 << endl;
//     }
//     else if (b == 0 && a != 0)
//     {
//         cout << 0 << ' ' << a << endl;
//     }
//     else if (!b % 2)
//     {
//         cout << -1 << endl;
//     }
//     else if ((a - c) / 2 < 0 || (a - c) / 2 > a)
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         int d = (a - c) / 2;
//         cout << d << ' ' << a - d << endl;
//     }
//     return 0;
// }
int main()
{
    long long x, y, a, b;
    cin >> a >> b;
    if (b >= a || b % 2)
    {
        cout << -1 << endl;
    }
    else
    {
        int c = (b / 2) * 3;
        if (c > a)
        {
            cout<<-1<<endl;
        }
        else if(c==a){
            cout<<a/3<<' '<<0<<endl;
        }
        else
        {
            cout<<c/3<<' '<<a-c<<endl;
        }
    }
    return 0;
}
