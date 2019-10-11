#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int mian(){
    priority_queue<int,deque<int>,greater<int> > q;
    int n;
    cin>>n;
    while (n--){
        char ch;
        cin>>ch;
        if(ch == 'q'){
            cout<<q.top();
            q.pop();
        }
        if (ch == 'i')
        {
            int num;
            cin>>num;
            q.push(num);
        }
    }
    return 0;
}

