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
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        int *arr = new int[n + 1];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        std::sort(arr, arr + n);
        if (arr[n - 1] != 1)
            arr[n - 1] = 1;
        else
            arr[n - 1] = 2;
        std::sort(arr, arr + n);
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
        arr = nullptr;
        delete arr;
    }
    return 0;
}