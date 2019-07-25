#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;


// int count(int m,int n){
//     if (m>n)
//     {
//         return 0;
//     }else{
//         if(!m^n) return 1;
//         return count(m*2,n)+count(m*2+1,n)+1;
//     }
// }

int main()
{
    int m, n;
    cin>>m>>n;
    while (m!=0 && n!=0)
    {
        // cout<<count(m,n)<<endl;
        int l=m,r=m;
        int cnt=0;
        while(r<n){
            cnt+=(r-l+1);
            l=l*2;
            r=r*2+1;
        }
        if(l<=n){
            cnt+=(n-l+1);
        }
        cout<<cnt<<endl;
        cnt=0;
        cin>>m>>n;
    }
    return 0;
}