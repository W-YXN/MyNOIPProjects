#include <bits/stdc++.h>
#define N 10010
using namespace std;
int n,cnt;
string s;
map<string,int> m;
map<string,int>::iterator it;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		m[s]++; 
	}
	while(!m.empty()){
		cnt++;
		for(it=m.begin();it!=m.end();++it){
			if(it->second>0) it->second--;
			else if (!m.empty()) m.erase(it);
		}
		it--;
    	cout<<it->second;
	}
	return 0;
}
