#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    priority_queue<string,vector<string>,greater<string> > arr[160];
    priority_queue<pair<int,string>,deque<pair<int,string> >,greater<pair<int,string> > > k;
    for (int i = 0; i < n; i++)
    {
        string str;
        int pts;
        cin>>str>>pts;
        arr[pts].push(str);
        k.push(make_pair(pts,str));
    }
    cout<<"1~9 ";
    for (int i = 1; i < 15; i++)
    {
        cout<<i*10<<'~'<<i*10+9<<' ';
    }
    cout<<endl;
    for (int i = 0; i < 149; i+=10)
    {
        int ans = 0;
        for (int j = i; j < i+10; j++)
        {
            ans += arr[j].size();
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    while (!k.empty())
    {
        pair<int,string> t = k.top();
        string tmp = t.second;
        int temp = t.first;
        cout<<tmp<<' '<<temp<<endl;
        k.pop();
    }
    cout<<arr[150].size()<<endl;
    if (arr[150].size()==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        while (!arr[150].empty())  
        {
            cout<<arr[150].top()<<endl;
            arr[150].pop();
        }
    }
    return 0;
}


