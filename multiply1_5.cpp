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

const int MAX = 1010;

int main()
{
    string std1, std2;
    cin >> std1 >> std2;
    if(std1.length()==1&&std1[0]==0||std2.length()==1&&std2[0]==0){
        cout<<0;
        return 0;
    }
    int length1 = std1.length();
    int length2 = std2.length();
    int a[MAX] = {0};
    int b[MAX] = {0};
    int result[2 * MAX] = {0};
    int i = 0, j = 0;
    for (i = length1 - 1, j = 0; i >= 0; i--, j++)
    {
        a[j] = std1[i] - '0';
    }
    for (i = length2 - 1, j = 0; i >= 0; i--, j++)
    {
        b[j] = std2[i] - '0';
    }
    for (i = 0; i < length1; i++)
    {
        for (j = 0; j < length2; j++)
        {
            result[i + j] += a[i] * b[j];
        }
    }
    for (i = 0; i < (length1 + length2); i++)
    {
        if (result[i] > 9)
        {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    for (i = length1 + length2; i >= 0; i--)
    {
        if (result[i] == 0)
            continue;
        else
            break;
    }
    for (; i >= 0; i--)
        cout << result[i];
    return 0;
}