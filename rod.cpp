/// A solution for "rod" problem by 11chun.
/// Thanks a lot.

#include<bits/stdc++.h>//递归切割钢条
using namespace std;
int r[1001];//缓存
int inof(int a[],int n){//注意，这里的"a"数组是主函数的"b"
    if(n==0){
    	return 0;
	}else{
		if(r[n]!=-1)return r[n];//如果已经缓存过就直接读缓存
        int s=0;
        for(int i=1;i<=n;i++){
            s=max(s,a[i]+inof(a,n-i));	//比较最大
		}
		r[n]=s;//没缓存过的加缓存
        return s;//返回最大
    }
}

int main(){

	//freopen("rod.data","r",stdin)
	//freopen("rod.out","w",stdout)

//=========================================================//


	int n,a[1000],b[1000];//n:number a:length b:prize
	cin>>n;
	for(int i=1;i<=1000;i++)r[i]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]; //input
	}
	
	for(int i=1;i<=n;i++){
		cout<<inof(b,i)<<endl;//把每一个长度的最高价值输出
	}
	return 0;
}



