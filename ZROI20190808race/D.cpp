#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,c,s1,s2;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		s1=s2=0;
		cin>>a>>b>>c; s1+=a*3600+b*60+c;
		cin>>a>>b>>c; s2+=a*3600+b*60+c;
		if(s1==s2) cout<<"Case "<<i<<": Yes"<<endl;
		else cout<<"Case "<<i<<": No"<<endl;
	}
	return 0;
}
