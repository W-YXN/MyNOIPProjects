#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
using std::cin;
using std::cout;
using std::endl;

int chosenFront[40] = {0}, chosenBack[20] = {0};
int hitFront = 0, hitBack = 0;

int judge(void)
{
    if (hitFront == 5)
    {
        if (hitBack == 2)
        {
            return 5000000;
        }
        else if (hitBack == 1)
        {
            return 250000;
        }
        else if (hitBack == 0)
        {
            return 3000;
        }
    }
    else if (hitFront == 4)
    {
        if (hitBack == 2)
        {
            return 3000;
        }
        else if (hitBack == 1)
        {
            return 200;
        }
        else if (hitBack == 0)
        {
            return 10;
        }
    }
    else if (hitFront == 3)
    {
        if (hitBack == 2)
        {
            return 200;
        }
        else if (hitBack == 1)
        {
            return 10;
        }
        else if (hitBack == 0)
        {
            return 5;
        }
    }
    else if (hitFront == 2)
    {
        if (hitBack == 2)
        {
            return 10;
        }
        else if (hitBack == 1)
        {
            return 5;
        }
        else if (hitBack == 0)
        {
            return 0;
        }
    }
    else if (hitFront == 1)
    {
        if (hitBack == 2)
        {
            return 5;
        }
        else if (hitBack == 1)
        {
            return 0;
        }
        else if (hitBack == 0)
        {
            return 0;
        }
    }
    else if (hitFront == 0)
    {
        if (hitBack == 2)
        {
            return 5;
        }
        else if (hitBack == 1)
        {
            return 0;
        }
        else if (hitBack == 0)
        {
            return 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int tmp = 0;
        cin >> tmp;
        chosenFront[tmp] = 1;
    }
    for (int i = 0; i < 2; i++)
    {
        int tmp = 0;
        cin >> tmp;
        chosenBack[tmp] = 1;
    }
    for (int i = 0; i < 5; i++)
    {
        int tmp = 0;
        cin >> tmp;
        if (chosenFront[tmp] == 1)
        {
            hitFront += 1;
        }
        else
            continue;
    }
    for (int i = 0; i < 2; i++)
    {
        int tmp = 0;
        cin >> tmp;
        if (chosenBack[tmp] == 1)
        {
            hitBack += 1;
        }
        else
            continue;
    }
    cout << judge() << endl;
    return 0;
}