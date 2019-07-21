#include <queue>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    long long nums[1510] = {0};
    queue<long long> t2, t3, t5;
    nums[1] = 1;
    int curi = 1;
    while (nums[1501] == 0)
    {
        t2.push(nums[curi] * 2);
        t3.push(nums[curi] * 3);
        t5.push(nums[curi] * 5);
        long long tmp = min(min(t2.front(), t3.front()), t5.front());
        curi++;
        nums[curi] = tmp;
        if (t2.front() == tmp)
            t2.pop();
        if (t3.front() == tmp)
            t3.pop();
        if (t5.front() == tmp)
            t5.pop();
    }
    int n;
    cin >> n;
    while (n != 0)
    {
        cout << nums[n] << endl;
        cin >> n;
    }
    return 0;
}