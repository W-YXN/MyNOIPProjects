#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(){
    priority_queue<int,vector<int>,greater<int> > q;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int code;
        cin>>code;
        if(code==1){
            int tmp;
            cin>>tmp;
            q.push(tmp);
        }else{
            cout<<q.top()<<endl;
            q.pop();
        }
    }
    return 0;
}