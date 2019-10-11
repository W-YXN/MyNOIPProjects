#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	int n,m,cnt,cur=0,Time=0;
	char c;
	while (T--){
		Time++;
		cin>>n>>m;
		cur=0;
		for (int i=0;i<n;i++){
			cnt=0;
			for (int j=0;j<m;j++){
				c=getchar(); 
				if (c=='*') cnt++;
			}
			getchar();
			if (cnt>2) cur++;
		}
		if (cur==3) printf("Case %d: Eight\n",Time);
		else printf("Case %d: Zero\n",Time);
	}
	return 0;
}

