/*#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>

int main()
{
    int n = 0;
    std::cin >> n;
    char str[6010] = {0};
    for (int i = 0; i < n; ++i)
    {
        char tmp;
        std::cin >> tmp;
        //std::cerr<<tmp<<std::endl;
        str[i] = tmp;
        str[i + n] = tmp;
    }
    str[n * 2] = '\0';
    int cnt = 0;
    for (int len = 2; len <= n; len++)
    {
        //std::cerr << "len= " << len << ' ';
        int maxBegin = n - 1;
        for (int beg = 0; beg <= maxBegin; beg++)
        {
            //std::cerr << "beg= " << beg << std::endl;
            for (int i = 0; i <= (len / 2) - 1; i++)
            {
                char l = str[beg + i], r = str[beg + len - 1 - i];
                //std::cerr << "i= " << i << ' ' << l << ' ' << r << std::endl;
                if (l != r && (l != '?' && r != '?'))
                {
                    break;
                }
                else if (l == r || (l == '?' || r == '?'))
                {
                    if (i == (len / 2) - 1)
                    {
                        cnt++;
                        //std::cout << "cnt=" << cnt << std::endl;
                    }
                    continue;
                }
            }
        }
    }
    std::cout << cnt;
    return 0;
}
//b?aba*/