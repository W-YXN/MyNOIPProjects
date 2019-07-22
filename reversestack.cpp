#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <deque>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    bool reversed = false;
    deque<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int code;
        cin >> code;
        if (code == 1)
        {
            int x;
            cin >> x;
            if (!reversed)
            {
                q.push_front(x);
                cout << q.front() << endl;
            }
            else
            {
                q.push_back(x);
                cout << q.back() << endl;
            }
        }
        else if (code == 2)
        {
            if (!reversed)
            {
                q.pop_front();
            }
            else
            {
                q.pop_back();
            }
            if (!q.empty())
            {
                if (!reversed)
                {
                    cout << q.front() << endl;
                }
                else
                {
                    cout << q.back() << endl;
                }
            }
            else
                cout << "-1" << endl;
        }
        else
        {
            reversed = 1 - reversed;
            if (!q.empty())
            {
                if (!reversed)
                {
                    cout << q.front() << endl;
                }
                else
                {
                    cout << q.back() << endl;
                }
            }
            else
                cout << "-1" << endl;
        }
    }
    return 0;
}