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

#ifdef MAXN
#undef MAXN
#endif
#define MAXN 100000

int stack[MAXN] = {0}, stackindex = 1;

void push(int x) { stack[stackindex++] = x; }
void pop(void) { stackindex--; }
int top(void) { return stack[stackindex]; }
int size(void) { return stackindex; }
bool empty(void) { return stackindex == 0; }

#ifdef MAXN
#undef MAXN
#endif

int main()
{
    char ch;
    do
    {
        cin >> ch;
        if (ch == '(')
            push(10);
        if (ch == ')')
            pop();
        if (stackindex <= 0)
        {
            cout << "NO";
            return 0;
        }
    } while (ch != '@');
    if (stackindex == 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}