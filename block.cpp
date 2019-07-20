/*#include <iostream>
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

int block[3][3] = {0};
int used[12] = {0};
bool solved = false;

void solve()
{
    if (!solved)
    {
        for (int i = 0; i < 9; i++)
        {
            if (block[i / 3][i % 3] == 0)
            {
                if (i != 4)
                {
                    if (block[2 - (i / 3)][2 - (i % 3)] != 0)
                    {
                        block[i / 3][i % 3] = 10 - block[2 - (i / 3)][2 - (i % 3)];
                        used[10 - block[2 - (i / 3)][2 - (i % 3)]] = 1;
                    }
                    else
                    {
                        for (int j = 0; j < 9; j++)
                        {
                            if (!used[j])
                            {
                                block[i / 3][i % 3] = j;
                                used[j]=1;
                                solve();
                                if (solved)
                                    return;
                                    else
                                    {
                                        block[i / 3][i % 3] = 0;
                                        used[j]=0;
                                    }
                                    
                            }
                        }
                    }
                }
                else
                {
                    block[1][1] = 5;
                    used[5] = 1;
                }
            }
        }
        solved = true;
        return;
    }
    else
        return;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> block[i / 3][i % 3];
        used[block[i / 3][i % 3]] = 1;
    }
    solve();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << block[i][i] << ' ';
        }
        cout << endl;
    }
}
*/