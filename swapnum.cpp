#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int da_biao[] = {1, 1, 2, 6, 24, 120};

int hash(string s)
{
    int num = 0;
    for (int i = 0; i < 6 - 1; i++)
    {
        int temp = 0;
        for (int j = i + 1; j < 6; j++)
        {
            if (s[j] < s[i])
                temp++;
        }
        num += da_biao[6 - i - 1] * temp;
    }
    return num;
}

int BFS(string src, string dest)
{
    int vis[725] = {0}, step[725] = {0};
    int front, rear, s0, s1;
    string q[725];
    
    front = rear = 0;
    s1 = hash(dest);
    q[rear++] = src;
    s0 = hash(src);
    vis[hash(src)] = 1;
    step[s0] = 0;

    while (front < rear)
    {
        string cur = q[front++];
        s0 = hash(cur);

        if (s0 == s1)
            return step[s0];

        for (int i = 0; i < 6 - 1; i++)
        {
            string next = cur;

            char tmp = next[i];
            next[i] = next[i + 1];
            next[i + 1] = tmp;

            int ts = hash(next);
            if (vis[ts] == 0)
            {
                vis[ts] = 1;
                step[ts] = step[s0] + 1;
                q[rear++] = next;
            }
        }
    }
}

int main()
{
    string src, dest;
    while (cin >> src >> dest)
    {
        cout << BFS(src, dest) << endl;
    }
    return 0;
}