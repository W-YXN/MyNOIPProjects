#include <bits/stdc++.h>
#define N 200010
using namespace std;
string s;
int len,cnt,l[N];
int main(){
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++) if(i+8<=len-1&&s[i]=='h'&&s[i+1]=='a'&&s[i+2]=='p'&&s[i+3]=='p'&&s[i+4]=='i'&&s[i+5]=='n'&&s[i+6]=='e'&&s[i+7]=='s'&&s[i+8]=='s') {l[cnt++]=i+1;}
	if(cnt==2) cout<<"YES "<<l[0]<<" "<<l[1]<<endl;
	else if(cnt==1) cout<<"YES "<<l[0]<<" "<<1<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
