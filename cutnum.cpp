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

int main()
{
    int chen_zhe[70][70] = {0};
    memset(chen_zhe, 0, 70 * sizeof(int));
    chen_zhe[1][1] = 1;
    for (int i = 1; i <= 65; i++)
        for (int j = 1; j < 66; j++)
        {
            if (i == 1 || j == 1)
            {
                chen_zhe[i][j] = 1;
            }
            else if (i < j)
                chen_zhe[i][j] = chen_zhe[i][i];
            else if (i == j)
                chen_zhe[i][j] = chen_zhe[i][j - 1] + 1;
            else if (i > j)
            {
                chen_zhe[i][j] = chen_zhe[i - j][j] + chen_zhe[i][j - 1];
            }
        }
    int in;
    while (cin >> in)
    {
        cout << chen_zhe[in][in + 1] << endl;
    }
}