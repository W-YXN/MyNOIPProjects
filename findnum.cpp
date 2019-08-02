#include <iostream>
#include <cstdlib>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int *arr;
int n;

int search(int x)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    int mid = (1 + n) / 2;
    while (l < r - 1)
    {
        if (x < arr[mid])
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
        mid = (l + r) / 2;
    }
    if (std::abs(arr[l] - x) <= std::abs(arr[l + 1] - x) && l < n)
        ans = arr[l];
    else
    {
        ans = arr[l + 1];
    }
    //      if(x-a[l]>a[l+1]-x&&l<n)
    //        l++;
    return ans;
}

int main()
{
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    std::sort(arr, arr + n);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int fd;
        cin >> fd;
        // int *a = std::lower_bound(arr, arr + n + 1, fd);
        // int *b = std::upper_bound(arr, arr + n + 1, fd);
        // if (*a == 0)
        // {
        //     cout << arr[n - 1] << endl;
        //     continue;
        // }
        // if (*a == arr[0])
        // {
        //     cout << *a << endl;
        //     continue;
        // }
        // if (*a == fd)
        // {
        //     cout << fd << endl;
        //     continue;
        // }
        // cout << (((fd - *(a - 1)) <= (*b - fd)) ? (*(a - 1)) : (*b));
        // cout << endl;
        if (fd >= arr[n - 1])
            cout << arr[n - 1] << endl;
        else if (fd <= arr[0])
            cout << arr[0] << endl;
        else if (n == 1)
            cout << arr[0] << endl;
        else
        {
            cout << search(fd) << endl;
        }
    }
    return 0;
}
