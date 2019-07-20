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
typedef string mystring;

bool operator<(const mystring lhs, const mystring rhs)
{
    return lhs.length() < rhs.length();
}

void InsertSort(mystring arr[], int len)
{
    for (int j = 1; j < len; j++)
    {
        mystring key = arr[j];
        int i = j - 1;
        while (i >= 0 && key < arr[i])
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        mystring *s = new mystring[n + 3];
        int maxs = 0;
        for (int i = 0; i <= n; i++)
        {
            std::getline(cin, s[i]);
            if (s[i] == "stop" || s[i] == "stop\n" || s[i] == "stop\r" || s[i] == "stop\r\n")
            {
                maxs = i;
                break;
            }
            maxs = i + 1;
        }
        InsertSort(s, maxs);
        for (int i = 0; i < maxs; i++)
        {
            if (s[i] != "" && s[i] != "\n" && s[i] != "\r" && s[i] != "\r\n")
                cout << s[i] << endl;
        }
    }
    return 0;
}