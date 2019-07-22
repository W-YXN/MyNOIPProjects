#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::string;

void slv(queue<int> qin, stack<int> stk, queue<int> qout)
{
    if (qin.empty())
    {
        if (stk.empty())
        {
            while (!qout.empty())
            {
                cout << qout.front() << ' ';
                qout.pop();
            }
            cout << endl;
            return;
        }
        else
        {
            int tmp = stk.top();
            stk.pop();
            qout.push(tmp);
            slv(qin, stk, qout);
        }
    }
    else
    {
        if (!stk.empty())
        {
            queue<int> cpqin = qin;
            queue<int> cpqout = qout;
            stack<int> cpstk = stk;
            int tmp = cpstk.top();
            cpqout.push(tmp);
            cpstk.pop();
            slv(cpqin, cpstk, cpqout);
        }
        int tmp = qin.front();
        stk.push(tmp);
        qin.pop();
        slv(qin, stk, qout);
    }
}

int main()
{

    int n;
    cin >> n;
    queue<int> qin;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        qin.push(tmp);
    }
    stack<int> stk;
    queue<int> qout;
    slv(qin, stk, qout);
}