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

void hanoi(int n, char from, char stackk, char to)
{
    if (n == 0)
    {
        return;
    }
    else if (n == 1)
    {
        cout << n << ':' << from << "->" << to << endl;
        return;
    }
    else
    {
        hanoi(n - 1, from, to, stackk);
        cout << n << ':' << from << "->" << to << endl;
        hanoi(n - 1, stackk, from, to);
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    char sk1, sk2, sk3;
    cin >> sk1 >> sk2 >> sk3;
    hanoi(n, sk1, sk2, sk3);
    return 0;
}