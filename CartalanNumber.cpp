#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n,s,f[N];
int main(){
	f[0]=f[1]=1,f[2]=2;
	cin>>n;
	for(int i=3;i<=n;i++)
		for(int j=0;j<i;j++)
			f[i]+=f[j]*f[i-j-1];
	cout<<f[n]<<endl;
	return 0;
}
