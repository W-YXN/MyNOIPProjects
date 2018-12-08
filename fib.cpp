#include<iostream>
using namespace std;
typedef long long _LL;

_LL a[10000] = {0};
_LL fi[10000] = {0};

_LL easyfib(_LL n=1){
    if(n==1||n==0){
        return 1;
    }else{
        return easyfib(n-1)+easyfib(n-2);
    }
}

_LL fib2(_LL n=1){
    if(fi[n]!=0){
        return fi[n];
    }else{
        a[n]++;
        if(0==n||1==n){
            fi[n]=1;
            return fi[n];
        }
        else{
            fi[n]=(fib2(n-1)+fib2(n-2));
            return fi[n];
        }
    }
}


_LL fib1(_LL n=1){
    fi[0]=fi[1]=1;
    if(0==n||1==n){
        return 1;
    }else{
        for(int i=2;i<=n;i++){
            fi[i]=fi[i-1]+fi[i-2];
        }
        return fi[n];
    }
}

int main(){
    _LL k;
    cin>>k;
    cout<<easyfib(k)<<endl;
    return 0;
}