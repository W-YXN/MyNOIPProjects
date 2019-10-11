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

int fa[5005];

int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

int main()
{
    int m, n, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        fa[find(r)] = find(l);
    }
    for (int i = 0; i < p; i++)
    {
        int l, r;
        cin >> l >> r;
        if(find(l)==find(r)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
