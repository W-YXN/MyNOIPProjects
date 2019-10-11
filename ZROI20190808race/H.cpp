#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+15;
ll lg[N],f[N][N][12][12];
int query(int x1,int y1,int x2,int y2){
	int k1=lg[x2-x1+1],k2=lg[y2-y1+1];
    int max1=f[x1][y1][k1][k2];
    int max2=f[x2-(1<<k1)+1][y1][k1][k2];
    int max3=f[x1][y2-(1<<k2)+1][k1][k2];
    int max4=f[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2];
    int res=max(max(max1,max2),max(max3,max4));
    return res;
}
int main(){
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) cin>>f[i][j][0][0];
	for (int k=0;(1<<k)<=n+10;k++){
    	for (int l=0;(1<<l)<=m+10;l++){
	        if (k==0&&l==0) 
    	        continue;
        	for (int i=1;i+(1<<k)-1<=n+10;i++){
            	for (int j=1;j+(1<<l)-1<=m+10;j++){
                	if (k==0)
                    	f[i][j][k][l] = max(f[i][j][k][l-1],f[i][j+(1<<(l-1))][i][l-1]);
	                else if (l == 0)
    	                f[i][j][k][l] = max(f[i][j][k-1][l],f[i+(1<<(k-1))][j][k-1][l]);
        	        else
            	        f[i][j][k][l] = max(f[i][j][k][l-1],f[i][j+(1<<(l-1))][k][l-1]);
        	    }
        	}
    	}
	}
    int Max=0x3f3f3f3f,cur,mini,minj;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cur=max(max(query(0,0,i-1,j-1),query(0,j+1,i-1,m)),max(query(i+1,0,n,j-1),query(i+1,j+1,n,m)));
			if (cur<Max) mini=i,minj=j,Max=cur;
		}
	cout<<mini<<' '<<minj<<endl;
	return 0;
}
//
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &val[i][j]);
            dp[i][j][0][0] = val[i][j];
        }

    for (int i = 0; (1 << i) <= n; i++) {
        for (int j = 0; (1 << j) <= m; j++) {
            if (i == 0 && j == 0) continue;
            for (int row = 1; row + (1 << i) - 1 <= n; row++)
                for (int col = 1; col + (1 << j) - 1 <= m; col++) {
                    //当x或y等于0的时候，就相当于一维的RMQ了
                    if (i == 0) dp[row][col][i][j] = max(dp[row][col][i][j - 1], dp[row][col + (1 << (j - 1))][i][j - 1]);
                    else if (j == 0) dp[row][col][i][j] = max(dp[row][col][i - 1][j], dp[row + (1 << (i - 1))][col][i - 1][j]);
                    else dp[row][col][i][j] = max(dp[row][col][i][j - 1], dp[row][col + (1 << (j - 1))][i][j - 1]);
                }
                
        }
    }
}
//本来一维RMQ询问的时候是一个区间，现在变成了一个矩形，所以需要四个角度
int Query(int x1, int y1, int x2, int y2) {
    int kx = 0, ky = 0;
    while (x1 + (1 << (1 + kx)) - 1 <= x2) kx++;
    while (y1 + (1 << (1 + ky)) - 1 <= y2) ky++;
    int m1 = dp[x1][y1][kx][ky];
    int m2 = dp[x2 - (1 << kx) + 1][y1][kx][ky];
    int m3 = dp[x1][y2 - (1 << ky) + 1][kx][ky];
    int m4 = dp[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];

    return max(max(m1, m2), max(m3, m4));
}
 
