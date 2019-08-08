#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int pows2[30];

bool check(int num)
{
    for (int i = 1; i < 28; i++)
    {
        if (num == pows2[i])
        {
            return true;
        }
    }
    return false;
}

void solve(int n){
    if (n == 0)
    {
        return;
    }
    bool flag = check(n);
    if (flag)
    {
        n = n - 1;
    }
    int k = 0;
    if(k < n)
    {
        for (int i = 0; i < 28; i++)
        {
            if (k + pows2[i] > n)
            {
                n -= pows2[i - 1];
                if (k == n && pows2[i - 1] == 2)
                {
                    cout << "1 1 ";
                    break;
                }
                else
                {
                    cout << pows2[i - 1] << ' ' << std::flush;
                    solve(n);
                    break;
                }
            }
        }
    }
    if (flag)
    { 
        cout << "1 ";
    }
}

int main()
{
    for (int i = 0; i < 30; i++)
    {
        pows2[i] = (1 << i);
    }
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    solve(n);
    cout << endl;
    return 0;
}



// FIXED

#include <bits/stdc++.h>
using namespace std;
int pows2[32];
inline bool check(int n){
	if (n == 1) return 0;
    return (n & (n - 1)) == 0;
}
inline void solve(int n){
    if (n == 0) return;
    bool flag = check(n);
    if (flag) n--;
    int k = 0;
    if(k < n)
    {
    	int i = upper_bound(pows2 + 0, pows2 + 31, n - k) - pows2;
    	n -= pows2[i - 1];
        if (k == n && pows2[i - 1] == 2) printf("1 1 ");
        else{
        	printf("%d ", pows2[i - 1]);
            solve(n);
		}   
    }
    if (flag) putchar('1');
}

int main()
{
    
    for (register int i = 0; i < 31; i++) pows2[i] = (1 << i);
    int n;
    cin >> n;
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    solve(n);
    printf("\n");
    return 0;
}


