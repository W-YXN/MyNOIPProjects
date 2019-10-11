#include <iostream>
// #include <iomanip>
#include <cstdio>
#include <cstdlib>
// #include <cmath>
#include <algorithm>
// #include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> s;
    int len = s.length();
    //std::cerr<<s<<' '<<len;
    for (register int i = std::max(1, len / 2 - 3); i <= len; i++)
    {
        string s1, s2;
        s1 = s.substr(0, i);
        s2 = s1;
        //std::cerr<<s1<<' '<<s2;
        // string::iterator it;
        // for (it = s2.begin(); it != s2.end(); it++)
        // {
        //     if (*it == 'a')
        //     {
        //         s2.erase(it);
        //         it--;
        //     }
        // }
        s2.erase(std::remove(s2.begin(), s2.end(), 'a'), s2.end());
        // string tmp = s1 + s2;
        if (s == s1 + s2)
        {
            cout << s1 << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;

    // chen_zhe NB!!!!!
    //kkksc03 NB!!!!!!
}

// #include <iostream>
// #include <iomanip>
// #include <cstdio>
// #include <cstdlib>
// #include <cmath>
// #include <algorithm>
// // #include <cstring>
// #include <string>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// string s;
// // char s[10010];

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin >> s;
//     int len = 10001;
//     //std::cerr<<s<<' '<<len;
//     for (register int i = 1; i <= len; i++)
//     {
//         string s1, s2;
//         // char s1[10010], s2[10010];
//         s1 = s.substr(0, i);
//         // cout<<s1<<endl;
//         // std::memcpy(s1, s, i);
//         s2 = s1;
//         // std::strcpy(s2, s1);
//         //std::cerr<<s1<<' '<<s2;
//         // string::iterator it;
//         // for (it = s2.begin(); it != s2.end(); it++)
//         // {
//         //     if (*it == 'a')
//         //     {
//         //         s2.erase(it);
//         //         it--;
//         //     }
//         // }
//         // const char s[2] = "a";
//         // char *token;
//         // token = std::strtok(s2, s);
//         // char tmp[10010];
//         // while (token != NULL)
//         // {
//         //     std::strcat(tmp, token);
//         //     token = std::strtok(NULL, s);
//         // }
//         s2.erase(std::remove(s2.begin(), s2.end(), 'a'), s2.end());
//         string temp = s1 + s2;
//         // char temp[10010];
//         // std::strcat(temp, s1);
//         // std::strcat(temp, tmp);
//         // if (std::strcmp(s, temp))
//         if(temp == s)
//         {
//             cout << s1 << endl;
//             return 0;
//         }
//     }
//     cout << ":(" << endl;
//     return 0;
// }
