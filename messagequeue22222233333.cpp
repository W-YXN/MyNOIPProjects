// #include <iostream>
// #include <cstdlib>
// #include <cmath>
// #include <algorithm>
// #include <string>
// #include <cstring>
// #include <queue>
// #include <vector>
// using namespace std;

// int main(){
//     int n,q;
//     cin>>n>>q;
//     queue<int> ques[300010];
//     int* haveread = new int[300010];
//     int* ifread = new int[300010];
//     memset(haveread,0,sizeof(haveread));
//     memset(ifread,0,sizeof(ifread));
//     vector<int> msgs;
//     int unread = 0;
//     for (int i = 0; i < q; i++)
//     {
//         int tp;
//         cin>>tp;
//         if(tp==1) {
//         	int x;
//         	cin>>x;
//         	msgs.push_back(x);
//         	ques[x].push(1);
//         	unread++;
//         	cout<<unread<<endl;
// 		}
// 		else if(tp==2){
// 			int x;
// 			cin>>x;
// 			int num = ques[x].size();
// 			haveread[x]+=num;
// 			unread -= num;
// 			while(!ques[x].empty()) ques[x].pop();
// 			cout<<unread<<endl;
// 		}
// 		else if(tp==3){
// 			int t;
// 			cin>>t;
// 			for(int i=0;i<t;i++){
// 				int x = msgs[i];
// 				ifread[x]++;
// 				//cerr<<"ifread"<<x<<'='<<ifread[x]<<endl;
// 			}
// 			for(int i=0;i<=n;i++){
// 				if(ifread[i]>=haveread[i]){
// 					//cerr<<"ifread"<<i<<'='<<ifread[i]<<endl;
// 					int mns = ifread[i]-haveread[i];
// 					haveread[i]+=mns;
// 					unread -= mns;
// 					for(int j=0;j<mns;j++) if(!ques[i].empty()) ques[i].pop();
// 				}
// 				ifread[i]=0;
// 			}
// 			cout<<unread<<endl;
// 		}
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool read[300010];
queue<int> q[300010];
queue<pair<int,int> > s;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int op,tar;
		int sum=0,idx=1;
        for(int i=1; i<=m; i++)
        {
            cin>>op>>tar;
            if(op==1)
            {
                q[tar].push(idx);
                s.push(make_pair(tar,idx++));
                sum++;
            }
            else if(op==2)
            {
                sum-=q[tar].size();
                while(!q[tar].empty())
                {
                    read[q[tar].front()]=1;
                    q[tar].pop();
                }
            }
            else if(op==3)
            {
                while(!s.empty()&&s.front().second<=tar)
                {
                    int appi=s.front().first;
                    int noti=s.front().second;
                    s.pop();
                    if(!read[noti])
                    {
                        read[noti]=1;
                        q[appi].pop();
                        sum--;
                    }
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}