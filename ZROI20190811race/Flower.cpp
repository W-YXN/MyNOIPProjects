#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

int main()
{
    int n;
    double r;
    cin >> n >> r;
    double uppp = r * std::sin(3.14159265358979 / (n * 1.0));
    double downnn = 1.0 - std::sin(3.14159265358979 / (n * 1.0));
    double ans = uppp / downnn;
    cout << std::fixed << setprecision(7) << ans << endl;
    return 0;
}
