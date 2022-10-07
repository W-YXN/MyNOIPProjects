#include <iostream>
#include <cstdio>
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

int a1[100010], a2[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a2[a1[i]];
    }
    
}

