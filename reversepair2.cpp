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

int num = 0; 
void Merge(int A[], int p, int q, int r)
{
    int *L=new int[r-p+1], *R=new int[r-p+1];
    for (int i = 0; i <= q - p + 1; i++)
        L[i] = A[p + i];
    for (int i = 0; i <= r - q; i++)
        R[i] = A[q + 1 + i];
    L[q - p + 2] = 2147483600;
    R[r - q + 1] = 2147483600;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[i];
            num = num + 1;
            j++;
        }
    }
}

int Inversion(int A[], int p, int r)
{
    if (p < r)
        return 0;
    else
    {
        if (r - p + 1 == 1)
            return num;
        else
        {
            int q = (p + r) / 2;
            return Inversion(A, p, q) + Inversion(A, q + 1, r);
            Merge(A, p, q, r);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<' ';
    // }cout<<endl;
    Inversion(a, 0, n-1);
    cout << num;
    return 0;
}