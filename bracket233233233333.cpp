#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

bool judge(const char &lhs, const char &rhs)
{
    int l, r;
    switch (lhs)
    {
    case '<':
        l = 1;
        break;
    case '(':
        l = 2;
        break;
    case '[':
        l = 3;
        break;
    case '{':
        l = 4;
        break;
    }
    switch (rhs)
    {
    case '<':
        r = 1;
        break;
    case '(':
        r = 2;
        break;
    case '[':
        r = 3;
        break;
    case '{':
        r = 4;
        break;
    }
    return l <= r;
}

bool same(const char &lhs, const char &rhs)
{

    if (lhs == '<')
    {
        return rhs == '>';
    }
    if (lhs == '(')
    {
        return rhs == ')';
    }
    if (lhs == '[')
    {
        return rhs == ']';
    }
    if (lhs == '{')
    {
        return rhs == '}';
    }
}


int main()
{
    int t;
    cin >> t;
    stack<char> stk;
    while (t--)
    {
        string s;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{' || ch == '<')
            {
                if (stk.empty())
                {
                    stk.push(ch);
                }
                else
                {
                    char top = stk.top();
                    if (!judge(ch, top))
                    {
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                    else
                    {
                        stk.push(ch);
                    }
                }
            }
            else
            {
                if (stk.empty())
                {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
                else
                {
                    char top = stk.top();
                    if (!same(ch, top))
                    {
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                    else
                    {
                        stk.pop();
                    }
                }
            }
        }
        if (flag && stk.empty())
        {
            cout << "YES" << endl;
            continue;
        }
        else if (flag && !stk.empty())
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
