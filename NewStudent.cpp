#include <iostream>
#include <cstdlib>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// #define max(a, b) (((a) > (b)) ? (a) : (b));
// #define min(a, b) (((a) < (b)) ? (a) : (b));

// int memC[50][50] = {0};

// int C(long long n, long long m)
// {
//     if (memC[n][m]!=0)
//         return memC[n][m];
//     else
//     {
//         long long mi = n-m;
//         long long mx = max(m,mi);
//         long long mn = min(mi,m);
//         long long ans=1;
//         for(long long i=n;i>mx;i--){
//             ans *= i;
//         }
//         long long k=1;
//         for(long long i=2;i<=mn;i++){
//             k*=i;
//         }
//         memC[n][m] = ans/k;
//     }
//     return memC[n][m];
// }

long long  CC[35][35];

// int CCC(int n, int m)
// {
//     if (m == 0)
//         return 1;
//     if (m == 1)
//         return n;
//     if (m > 1)
//         return CCC(n - 1, m - 1) + CCC(n - 1, m);
// }

// long long c(int n, int m)
// {
//     long long c;

//     if (n < m)
//         c = 0;
//     else if (n == m || m == 0)
//         c = 1;
//     else
//     {
//         c = 1;
//         n = n - m + 1;
//         for (int i = 1; i <= m; i++)
//         {
//             c *= n++;
//             c /= i;
//         }
//     }

//     return c;
// }

int main()
{
    int n, m;
    for (int i = 0; i < 35; i++)
    {
        CC[i][0] = 1;
    }
    CC[1][0] = 0;
    CC[1][1] = 0;
    for (int i = 1; i < 35; i++)
    {
        for (int j = 0; j < i; j++)
        {
            CC[i][j] = CC[i - 1][j - 1] + CC[i - 1][j];
        }
        CC[i][i]=1;
    }
    int t;
    cin>>t;
    while (t--)
    {
        cin >> n >> m;
        if (n < m)
            cout << 0 << endl;
        else
            // cout << CCC(n, m) << endl;
            cout << CC[n][m] << endl;
        // cout << c(n, m) << endl;
    }
}

// int C(int n,int m){
//     if(m==1) return n;
//     if(m>n/2) return C(n,n-m);
//     if(m>1) return C(n-1,m-1)+C(n-1,m);
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int m, n;
//         cin >> m >> n;
//         if (n == 0)
//         {
//             cout << 1 << endl;
//             continue;
//         }
//         else if (m < n)
//         {
//             cout << 0 << endl;
//             continue;
//         }
//         else
//         {
//             cout << C(m, n)<<endl;
//         }
//     }
//     return 0;
// }