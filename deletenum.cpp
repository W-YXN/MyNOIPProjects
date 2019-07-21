#include <iostream>
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

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (long unsigned int i = 0; i < k; i++)
    {
        for (long unsigned int j = 0; j < s.length() - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                s.erase(j, 1);
                break;
            }
            if (j == s.length() - 2)
            {
                s.erase(j + 1, 1);
            }
        }
    }
    while (s[0] == '0')
    {
        s.erase(s.begin());
    }
    if (s.length() == (long unsigned int)0)
    {
        s = "0";
    }
    cout << s;
    return 0;
}