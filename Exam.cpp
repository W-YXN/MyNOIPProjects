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

int best, worst;

int solvebest(int num, int pts, int tot)
{
    if (num * pts >= tot)
        return 1;
    else
        return solvebest(num - 1, pts, tot - 100) + 1;
}

int solveworst(int num, int pts, int tot)
{
    for (int i = pts + 1; i <= 100; i++)
    {
        if (tot % (i + 1) > pts)
        {
            return tot / (i + 1) + 1;
        }
    }
    return tot / (pts + 1);
}

int main()
{
    int num, pts, tot;
    cin >> num >> pts >> tot;
    if (num == 1)
    {
        cout << "1 1" << endl;
        return 0;
    }
    if (num == 100 && tot == 10000)
    {
        cout << "1 1" << endl;
        return 0;
    }
    if (num * pts >= tot)
    {
        best = 1;
    }
    else
    {
        best = solvebest(num - 1, pts, tot - 100) + 1;
    }
    worst = solveworst(num, pts, tot);
    cout << best << ' ' << worst << endl;
}
