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
using std::string;

int main()
{
    int d, i;
    cin >> d >> i;
    d -= 1;
    i -= 1;
    int ans = 1;
    while(d != 0)
    {
        ans = ans << 1;
        if(i & (unsigned)1) ans = ans | 1;
        d -= 1;
        i = i >> 1;
    }
    cout << ans;
    return 0;
} 


