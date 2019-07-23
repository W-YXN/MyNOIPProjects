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

int k = 0;
auto ans=0;

void hanoi(int n, char from, char stackk, char to)
{
    if (n == 0)
    {
        return;
    }
    else if (n == 1)
    {
        //cout << n << ':' << from << "->" << to << endl;
        if(n==k){ans++;}
        return;
    }
    else
    {
        hanoi(n - 1, from, to, stackk);
        //cout << n << ':' << from << "->" << to << endl;
        if(n==k){ans++;}
        hanoi(n - 1, stackk, from, to);
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ans=0;
        int a;
        cin >> a >> k;
        char sk1 = 'a', sk2 = 'b', sk3 = 'c';
        hanoi(n, sk1, sk2, sk3);
        cout<<ans<<endl;
    }
    return 0;
}