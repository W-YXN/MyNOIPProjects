#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

struct student
{
    string name;
    int id;
    int score;
};
int n;
student s[305];
bool cmp(student a, student b)
{
    if (a.score == b.score)
        return a.id < b.id;
    return a.score > b.score;
}
int main()
{
    bool flag;
    int first;
    student r[305];
    while (cin >> n)
    {
        flag = false;
        first = 9999999;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].name >> s[i].score;
            s[i].id = i;
            getchar(); //Drop CR/LF
        }
        sort(s, s + n, cmp);
        for (int i = 0; i < n; i++)
        {
            cin >> r[i].name >> r[i].score;
            getchar();
            if (r[i].score > first)
            {
                flag = true;
            }
            first = r[i].score;
        }
        if (flag)
        {
            cout << "Error" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << s[i].name << " " << s[i].score << endl;
            }
        }
        else
        {
            bool ans = false;
            for (int i = 0; i < n; i++)
            {
                if (s[i].name.compare(r[i].name) != 0)
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
            {
                cout << "Not Stable" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << s[i].name << " " << s[i].score << endl;
                }
            }
            else
                cout << "Right" << endl;
        }
    }
    return 0;
}