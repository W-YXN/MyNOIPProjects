#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// char gameMap[510][510] = {0};

// bool canup[510] = {0};
// bool candown[510] = {0};

// int main(){
//     int n,m;
//     cin>>n>>m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin>>gameMap[i][j];
//         }

//     }

// }

/*
 *
 * ######
 * #...##
 * #...D#
 * #C...#
 * ##.###
 * 
 *  */

char gameMap[510][510] = {0};
char yangli[5][6] = {{'#', '#', '#', '#', '#', '#'},
                     {'#', '.', '.', '.', '#', '#'},
                     {'#', '.', '.', '.', 'D', '#'},
                     {'#', 'C', '.', '.', '.', '#'},
                     {'#', '#', '.', '#', '#', '#'}};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> gameMap[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!gameMap[i][j] == yangli[i][j])
            {
                std::cout << -1 << std::endl;
                return 0;
            }
            if (i == n - 1 && j == m - 1)
            {
                std::cout << 3 << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
