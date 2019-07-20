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

void edited_BucketSort(int arr[], int len, int maxnum)
{
    int i, j;
    int *buckets = new int[maxnum];

    for (int i = 0; i < maxnum; i++)
        buckets[i] = 0;

    for (i = 0; i < len; i++)
    {
        buckets[arr[i]]++;
        //cerr<<arr[i]<<' '<<buckets[arr[i]]<<endl;
    }
    for (i = 0; i < maxnum; i++)
    {
        if (buckets[i] > 0)
            cout << i << (1 == maxnum - 1 ? "" : " ");
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    edited_BucketSort(arr, n, 1e5);
    return 0;
}