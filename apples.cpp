#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using std::cin;
using std::cout;
using std::endl;


int main(){
    int n;
    cin>>n;
    std::priority_queue<int,std::vector<int>,std::greater<int> > q;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    int ans=0;
    for (int i = 0; i < n-1; i++)
    {
        int a = q.top();
        q.pop();
        int b=q.top();
        q.pop();
        int c=a+b;
        ans+=c;
        q.push(c);
    }
    cout<<ans;
}