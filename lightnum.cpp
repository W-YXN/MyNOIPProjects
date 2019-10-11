#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int arr[100] = {0};
int cnt = 0;

unsigned int n = 1, l = 0, r = 0;
vector<int> num;
void cut(int length)
{
    int i = 0;
    l = 0;
    r = 0;
    while (i < length)
    {
        for (int j = i; j > 0; j--)
            num[i] *= 10;
        r += num[i];
        i++;
    }
    i = length;
    while (i < length * 2)
    {
        for (int j = i - length; j > 0; j--)
            num[i] *= 10;
        l += num[i];
        i++;
    }
}
void judge(int l, int r, int n)
{
   int sum = l + r;
    if (sum * sum == n){
        arr[++cnt] = n;
        }
}
int main()
{
    while (n > 0)
    {
        int n2 = n * n;
        int temp = n2;
        int length = 0;
        num.clear();
        while (temp > 0)
        {
            num.push_back(temp % 10);
            temp /= 10;
            length++;
        }
        if (length % 2 == 0)
        {
            length /= 2;
            cut(length);
            judge(l, r, n2);
        }
        n++;
        if (n2 <= 0)
        {
            return 0;
        }
    }
    int lft,rgh;
    cin>>lft>>rgh;
    for (int i = 0; i < 100; i++)
    {
        if(lft <= arr[i]&&arr[i]<= rgh){
            cout<<arr[i]<<endl;
        }
    }
    
}