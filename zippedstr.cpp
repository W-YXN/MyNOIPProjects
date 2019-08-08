#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;
    cin >> s;
    string cps;
    for (int i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            int n = s[i] - '0';
            string tmp;
            for (int j = i + 1; j < s.length() && !('0' <= s[j] && s[j] <= '9'); j++)
            {
                i = j;
                tmp += s[j];
            }
            for (int j = 0; j < n; j++)
            {
                cps += tmp;
            }
        }
        else
        {
            cps += s[i];
        }
    }
    cout << cps;
    return 0;
}
