#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int nums[1000] = {0};

int LCA(int a, int b)
{
    for (a; a != 0; a /= 2)
    {
        nums[a] = 1;
    }
    for (b; b != 0; b /= 2)
    {
        if (nums[b] == 1)
        {
            return b;
        }
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << LCA(x, y);
    return 0;
}