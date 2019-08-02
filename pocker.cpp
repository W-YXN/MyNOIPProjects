#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include <ctime>
using namespace std;

clock_t time_start,time_end;

int main(){
    time_start = clock();
    deque<long long> person1,person2;
    long long n;
    cin>>n;
    long long k1;
    cin>>k1;
    for (long long i = 0; i < k1; i++)
    {
        long long tmp;
        cin>>tmp;
        person1.push_back(tmp);
    }
    long long k2;
    cin>>k2;
    for (long long i = 0; i < k2; i++)
    {
        long long tmp;
        cin>>tmp;
        person2.push_back(tmp);
    }
    int ans=0;
    while(!person1.empty()&&!person2.empty()){
        long long p1=person1.front();
        long long p2=person2.front();
        person1.pop_front();
        person2.pop_front();
        if(p1<p2){
            person2.push_back(p1);
            person2.push_back(p2);
        }else{
             person1.push_back(p2);
            person1.push_back(p1);
        }
        time_end = clock();
        if(time_end-time_start>1600) {
            cout<<"-1";
            return 0;
        }
        ans++;
    }
    cout<<ans<<' ';
    if(person1.empty()){
        cout<<2<<endl;
    }
    if(person2.empty()){
        cout<<1<<endl;
    }
    return 0;
}