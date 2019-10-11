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


long long ans = 0;

long long solve(string str){
    int last = -1;
    long long ret = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]=='L'||str[i]=='C'||str[i]=='T')
        {
            if(last == -1){
                last = i;
            }else
            {
                long long kkk = i - last ;
                last = i;
                kkk %= (long long)1e9 +7;
                kkk *= kkk;
                kkk %= (long long)1e9 +7;
                //cout<<str<<' '<<kkk<<endl;
                ret += kkk;
            }
        }
    }
    return ret;
}

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void perm(string list[], int low, int high)
{
    if (low == high)
    {
        string tmp;
        for (int i = 0; i <= high; i++)
        {
            tmp += list[i];
        }
        ans += solve(tmp);
        ans %= (int)1e9 +7;
    }
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap(list[i], list[low]);
            perm(list, low + 1, high);
            swap(list[i], list[low]);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string *strs = new string[n + 3];
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    perm(strs,0,n-1);
    cout<<ans;
    return 0;
}
