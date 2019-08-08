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

int main()
{
    int n, m;
    cin >> n >> m;
    int *arr = new int[n + 3];
    arr[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << endl;
    }
    return 0;
}