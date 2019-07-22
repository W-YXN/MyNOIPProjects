#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define SIZE 10000000

void copy(int *a,int *b){
	for(int i=0;i<SIZE;i++) a[i]=b[i];
}
bool le(int *a, int *b, int len=SIZE) {
	int i;
	for(i=len-1; i>=0&&a[i]==b[i]; i--) ;
	return i<0 || a[i]<b[i];
}
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void sub(int *a, int *b, int len=SIZE) {
	for(int i=0;i<len;i++) 
		if((a[i]-=b[i])<0){  
			a[i+1]--;
			a[i]+=10;
		}
} 
void add(int *a,int *b,int len=SIZE){
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){
			a[i+1]++; 
			a[i]-=10;
		}
}
void mul(int *c,int *a,int *b) {
	converts(c,"0");
	for(int i=0;i<SIZE;i++) 
		for(int j=0; j<b[i]; j++)
			add(c+i, a, SIZE-i);
} 
void pow(int* save,int* num,int tmes){
    int *n;
    for (int i = 0; i < tmes; i++)
    {
        //un
    }
}
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int main(){
    
    return 0;
}