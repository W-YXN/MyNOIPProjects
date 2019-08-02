#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

char show[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
    long long n, r;
    while (cin >> n >> r)
    {
        string s;
        bool flag = true;
        if (n < 0)
        {
            flag = false;
            n = 0 - n;
        }
        while (n != 0)
        {
            s += show[n % r];
            n /= r;
        }
        std::reverse(s.begin(), s.end());
        if (!flag)
            cout << '-';
        cout << s << endl;
    }
    return 0;
}