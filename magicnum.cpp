#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

long long n = 0;

int main()
{
    cin >> n;
        long long tmp=n+1;
        for(long long i=2;i<=sqrt(tmp)+1;i++){
            if (tmp%i == 0) {
                cout<<"Yes";
                return 0;
            } 
        }
        cout<<"No";
        return 0;
}