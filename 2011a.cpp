#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const static string tmp="12345678901234567890";
int main(){
    string s;
    cin>>s;
    stringstream ss;
    long long a=0,b=0;
    ss<<s;
    ss>>a;
    //cout<<"a="<<a<<endl;
    if(a<0){
    	s[0]=0;
        reverse(s.begin(),s.end());
        ss.clear();
        ss<<s;
        //cout<<"s="<<s<<endl;
    	ss>>b;
    	b=0-b;
    	//cout<<"b="<<b<<endl;
    }else{
        reverse(s.begin(),s.end());
        ss.clear();
        ss<<s;
        //cout<<"s="<<s<<endl;
    	ss>>b;
    	//cout<<"b="<<b<<endl;
    }
    cout<<b<<endl;
    getchar();
}
