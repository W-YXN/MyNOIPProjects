
// x = x - n,y = n - y;

//   int yihao = 0;
//    if(x < 0 && y > 0){

//    if(y - x > (n-1)) yihao = 0;
//    if(y - x = (n-1)) yiaho = 1;
//    if(y - x < (n-1)) yihao = n - y;
//    yihao += 0;
//    }

//     int erhao = 0;

//    if(x >= 0 && y >= 0){

//    if(y + x > (n-1))  erhao = n - y;
//    if(y + x = (n-1)) erhao = 1;
//    if(y + x < (n-1)) erhao = 0;

//    ans += yihao;
//    ans -= 1（四角特判）
//    }

//    x < 0 && y < 0?

//    y + x > -(n-1) , 0;
//    y + x = -(n-1) , 1;
//    y + x < -(n-1) ,  n-x ;

//    ans += yihao;
//    ans -= 1 ;

//    x >=0 && y <= 0

//    y - x > (n-1) , 0;
//    y - x = (n-1) , 1;
//    y - x < (n-1) ,  n - x ;

//    ans += yihao
//    ans += erhao;
//    ans += sanhao
//    ans -= 2;

//      /

#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = 3000   2 + 2;
int a[N][N], sum[N][N];
int main()
{
    cin>>n>>q;
    int m = n   2 - 1;
    if (n == 2)
        a[1][2] = a[2][1] = a[2][3] = a[3][2] = 1;
    else
    {
        for (register int i = 1; i <= m; i++)
            for (register int j = 1; j <= m; j++)
                if (i + j == n + 1 || i + j == n + m || abs(i - j) == n - 1)
                    a[i][j] = 1;
    }
    for (register int i = 1; i <= m; i++)
        for (register int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    while (q--)
    {
        int x1, y1, x2, y2;
        cin>>x1>>x2>>y1>>y2;
        cout<<sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1]<<endl;;
    }
    return 0;
}

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    while (n--)
    {
        std::cout << 0 << std::endl;
    }
    return 0;
}