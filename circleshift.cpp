#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

// typedef unsigned short us;

// int main()
// {
//     ios::sync_with_stdio(true);
//     us t;
//     cin >> t;
//     // scanf("%uh", &t);
//     for (us i = 0; i < t; i++)
//     {
//         us num1, num2;
//         cin >> num1 >> num2;
//         // scanf("%uh %uh", &num1, &num2);
//         // bool fff = false;
//         us f;
//         // for (int j = 0; j <= 16; j++)
//         // {
//         //     if (j == 16)
//         //     {
//         //         cout << "NO" << endl;
//         //         // printf("NO\n");
//         //     }
//         //     // us f = num1 & 1;
//         //     // // int f = num1 & 1;
//         //     // num1 >>= 1;
//         //     // num1 |= f << 15;
//         //     // us tmp = (num1<<j)+(num1>>16-j);
//         //     us tmp = (num1<<j)|(num1>>16-j);
//         //     if(tmp==num2)
//         //     // if (num1 == num2)
//         //     {
//         //         cout << "YES" << endl;
//         //         // printf("YES\n");
//         //         break;
//         //     }
//         // }
//         int j;
//         for (j = 0; j < 16; j++)
//         {
//             f = num1 & 1;
//             num1 >>= 1;
//             num1 |= f << 15;
//             if (num1 == num2)
//             {
//                 printf("YES\n");
//                 break;
//             }
//         }
//         if (j == 16)
//             printf("NO\n");
//     }
//     // if (!fff)
//     // {
//     //     // cout << "NO" << endl;
//     //     printf("NO\n");
//     // }

//     return 0;
// }
   
int main()  
{  
    int n, i, j;  
    unsigned short a, b;  
    int fff;  
   
    while (scanf("%d", &n) != EOF)  
    {  
        for (i=0; i<n; i++)  
        {  
            scanf("%hu%hu", &a, &b);  
            for (j=0; j<16; j++)  
            {  
                fff = a&1;  
                a >>= 1;  
                a |= fff<<15;  
                if (a == b)  
                {  
                    printf("YES\n");  
                    break;  
                }  
            }  
            if (j==16)  
              printf("NO\n");  
        }  
    }  
   
    return 0;  
}  