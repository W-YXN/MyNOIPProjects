#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int n,table[11]= {0,1,0,0,2,10,4,40,92,352,724};

// unsigned int n;
// int lines[50] = {0};
// unsigned int upperlimit, ans = 0;

// void test(unsigned int row, unsigned int ld, unsigned int rd)
// {
//     unsigned int pos, p;
//     if (row != upperlimit)
//     {
//         pos = upperlimit & (~(row | ld | rd));
//         while (pos)
//         {
//             p = pos & (~pos + 1);
//             pos = pos - p;
//             test(row | p, (ld | p) << 1, (rd | p) >> 1);
//         }
//     }
//     else
//         ++ans;
// }

// int place(long t,int row) {
// 	// int i=1;
//     long i=1;
// 	while(i<row){
// 		if (t == lines[i] || std::abs(row-i) == std::abs(t - lines[i])) {
// 			return 0;
// 		}
// 		++i;
// 	}
// 	return 1;
// }

// void test(int m) {
// 	int i;
// 	for (i=1; i <= n; i++) {
// 		lines[m] = i;
// 		if (place(i,m)) {
// 			if (m == n) {
// 				ans++;
// 			}
// 			else {
// 				test(m + 1);
// 			}
// 		}
// 	}
// }

int main()
{
    cin >> n;
    while (n!=0)
    {
        // upperlimit = (1 << n) - 1;
        // test(0, 0, 0);
        // cout << ans;
        cout<<table[n]<<endl;
        cin >> n;
    }
    return 0;
}