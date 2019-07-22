#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define SIZE 1000

void converts(int *a, string s)
{
    int i, len = s.size();
    for (i = 0; i < len; i++)
        a[i] = s[len - i - 1] - '0';
    for (; i < SIZE; i++)
        a[i] = 0;
}
void add(int *a, int *b, int len = SIZE)
{
    for (int i = 0; i < len; i++)
        if ((a[i] += b[i]) >= 10)
        {
            a[i + 1]++;
            a[i] -= 10;
        }
}
int main()
{
    int ans[260][1100] = {0};
    string tmp = "0";
    converts(ans[0], tmp);
    tmp = "1";
    converts(ans[1], tmp);
    tmp = "3";
    converts(ans[2], tmp);
    tmp = "6";
    converts(ans[3], tmp);
    for (int i = 3; i < 252; i++)
    {
        int temp[1100] = {0};
        add(temp, ans[i - 2]);
        add(temp, ans[i - 2]);
        add(temp, ans[i - 1]);
        for (int j = 0; j < SIZE; j++)
            ans[i][j] = temp[j];
    }
    int chen_zhe;
    while (cin >> chen_zhe)
    {
        if (chen_zhe == 0)
            cout << "0" << endl;
        else
        {
            int kkksc03;
            for (kkksc03 = SIZE - 1; kkksc03 > 0; kkksc03--)
                if (ans[chen_zhe][kkksc03] > 0)
                    break;
            for (; kkksc03 >= 0; kkksc03--)
                cout << ans[chen_zhe][kkksc03];
            cout << endl;
        }
    }
    return 0;
}