#include <iostream>
#include <cstdlib>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

long long n = 0;

int main()
{
    cin >> n;
    if (n > 1e6)
    {
        cout << "Yes";
    }
    else
    {
        bool flag = false;
        for (long long i = 1; i <= n / 2 + 1; i++)
        {
            for (long long j = 0; j < i + 1; j++)
            {
                long long tmp = i * j;
                if (i + j + tmp == n)
                {
                    //std::cerr<<i<<' '<<j<<' '<<tmp<<endl;
                    flag = true;
                    break;
                }
                else
                    continue;
            }
            if (flag == true)
            {
                break;
            }
            else
                continue;
        } //O(n^2)
        if (flag == false)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
    }
    return 0;
}