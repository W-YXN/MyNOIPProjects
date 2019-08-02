#include<cstdio>
#include<iostream>
#include<cstring>
int v1[1001]={0},v2[1001]={0};
int main()
{
	int n,m,k,p;
	char s1[10],s2[10];
	while(std::cin>>n>>m>>k,n!=0||m!=0||k!=0)
	{
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
		int ans=n*m*k;
        int p;
		std::cin>>p;
		while(p--)
		{
            int x,y;
			std::cin>>s1>>x>>s2>>y;
			if(s1[0]=='c') 
			{
				v1[y]++;
				ans-=(k-v2[y]);
			}
			else 
			{
				v2[x]++;
				ans-=(n-v1[x]);
			}
		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}
