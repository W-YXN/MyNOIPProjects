#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    int n, s;
    cin >> n >> s;
    unsigned long long int ans = 0;
    int lst = 999999;
    for (int i = 0; i < n; i++)
    {
        int c, y;
        cin >> c >> y;
        int pr = min(lst, c);
        ans += y * pr;
        lst = pr + s;
    }
    cout << ans;
    return 0;
}