#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int k;
    cin >> k;
    int *a = new int[k + 3];
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int f1[27], f2[27];
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    for (int i = 1; i <= k; i++)
    {
        f1[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && f1[i] < f1[j] + 1)
                f1[i] = f1[j] + 1;
        }
    }
    for (int i = k; i >= 1; i--)
    {
        f2[i] = 1;
        for (int j = i + 1; j <= k; j++)
        {
            if (a[i] > a[j] && f2[i] < f2[j] + 1)
                f2[i] = f2[j] + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
        if (ans < f1[i] + f2[i] - 1)
            ans = f1[i] + f2[i] - 1;
    cout << k - ans << endl;
    return 0;
}
