#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct ___MISSIONS_
{
    int id;
    int cometime;
    int timeremain;
    int init;
    
} missions;

bool operator<(const missions &lhs,const missions &rhs)
    {
        if (lhs.cometime > rhs.cometime)
        {
            return true;
        }
        else if (lhs.cometime == rhs.cometime)
        {
            return lhs.init < rhs.init;
        }
        else
        {
            return false;
        }
    }

#ifdef MAXN
#undef MAXN
#endif
#define MAXN 100000
class my_stack
{
private:
    missions stk[MAXN] = {0};
    int stkindex = 1;

public:
    void push(missions x) { stk[stkindex++] = x; }
    void pop(void) { stkindex--; }
    missions top(void) { return stk[stkindex]; }
    int size(void) { return stkindex; }
    bool empty(void) { return stkindex <= 1; }
};
#ifdef MAXN
#undef MAXN
#endif

int main()
{
    priority_queue<missions> q;
    int id, tme, rem, init;
    while (cin >> id >> tme >> rem >> init)
    {
        missions tmp;
        tmp.id = id;
        tmp.cometime = tme;
        tmp.timeremain = rem;
        tmp.init = init;
        q.push(tmp);
    }
    int t = 0;
    missions dealing = q.top();
    q.pop();
    my_stack stk;
    while (!q.empty())
    {
        
    }
    return 0;
}