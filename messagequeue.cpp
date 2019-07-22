#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::queue;
using std::string;

typedef struct ____MESSAGES__
{
    int init;
    string message;
} msgs;

struct cmp
{
    bool operator()(const msgs &lhs, const msgs &rhs) { return lhs.init > rhs.init; }
};

int main()
{
    string code;
    int n;
    cin >> n;
    priority_queue<msgs, vector<msgs>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> code;
        if (code == "GET")
        {
            if (!pq.empty())
            {
                msgs tmp = pq.top();
                cout << tmp.message<< endl;
                pq.pop();
            }
            else
                cout << "EMPTY QUEUE!" << endl;
        }
        if (code == "PUT")
        {
            msgs tmp;
            cin>>tmp.message>>tmp.init;
            pq.push(tmp);
        }
    }
    return 0;
}