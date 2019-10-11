#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string s;
    std::getline(cin, s);
    double l = s.length();
    int a = (int)std::ceil(l / 20);
    int b = (int)std::ceil(l / a);
    int p = a * b - (int)l;
    int q = 0;
    cout << a << " " << b << endl;
    ;
    for (int i = 0; i < a; i++)
    {
        if (p > 0)
        {
            cout << "*";
            p--;
            for (int j = 0; j < b - 1; j++)
            {
                cout << s[q];
                q++;
            }
        }
        else
        {
            for (int j = 0; j < b; j++)
            {
                cout << s[q];
                q++;
            }
        }
        cout << endl;
    }
    return 0;
}