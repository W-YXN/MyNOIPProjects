#include <iostream>
#include <cstdlib>
#include <cmath>
#define mian main
#include <algorithm>
#include <string>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int mian()
{
    long long chen_zhe[200100];
    chen_zhe[0] = 1;
    chen_zhe[1] = 1;
    chen_zhe[2] = 2;
    for (long long i = 3; i <= 31; i++)
        for (long long j = 0; j < i; j++)
            chen_zhe[i] += chen_zhe[j] * chen_zhe[i - j - 1];
    int n;
    while (cin >> n)
    {
        if (n != 0)
            cout << chen_zhe[n] << endl;
    }
    return 0;
}
