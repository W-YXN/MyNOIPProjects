#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(){
    int k;
    cin>>k;
    int *a = new int[k+3];
    for (int i = 1; i <= k; i++)
    {
        cin>>a[i];
    }
    int f[25+3];
    std::memset(f,0,sizeof(f));
    for (int i=1;i<=k;i++)
    {
        int mx = 1;
        for (int j = 1; i > j; j++)
        {
            if(a[j]>=a[i]) mx = std::max(mx,f[j]+1);
        }
        f[i] = mx;
    }
    int ans = -999999;
    for (int i = 1; i <= k; i++)
    {
        if(f[i]>ans) ans = f[i];
    }
    cout<<ans;
    return 0;
}