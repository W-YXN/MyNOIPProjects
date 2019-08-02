// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cmath>
// #include <algorithm>
// using std::cin;
// using std::cout;
// using std::endl;

// long long n, m;
// long long thingswei[10010] = {0}, thingsval[10010] = {0};
// long long f[10010][10010] = {0};

// long long main()
// {
//     cin >> n >> m;

//     for (long long i = 1; i <= n; i++)
//     {
//         cin >> thingswei[i] >> thingsval[i];
//     }

//     for (long long j = 0; j <= m; j++)
//         f[0][j] = 0;
//     for (long long i = 1; i <= n; i++)
//     {
//         for (long long j = 0; j <= m; j++)
//         {
//             j < thingswei[i] ? f[i][j] = f[i - 1][j] : f[i][j] = std::max(f[i - 1][j], f[i - 1][j - thingswei[i]] + thingsval[i]);
//         }
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }

#include <iostream>
inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}
int main()
{
    long long N;
    unsigned long long M;
    std::cin >> N >> M;
    long long *need = new long long[N + 1];
    long long *value = new long long[M + 1];
    need[0] = 0;
    value[0] = 0;
    for (long long i = 1; i <= N; ++i)
        std::cin >> need[i] >> value[i];
    long long *best = new long long[M + 1];
    for (long long j = 0; j <= M; ++j)
        best[j] = 0;
    for (long long i = 1; i <= N; ++i)
    {
        for (long long j = 1; j <= M; ++j)
        {
            if (j >= need[i])
                best[j] = max(best[j], best[j - need[i]] + value[i]);
            else
                best[j] = best[j];
        }
    }
    std::cout << best[M] << std::endl;
    delete[] best;
    return 0;
}
