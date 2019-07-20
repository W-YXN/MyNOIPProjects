// #include <iostream>
// #include <cstdlib>
// #include <cmath>
// #include <algorithm>
// #include <string>
// #include <cstring>
// #define max(a, b) (((a) > (b)) ? (a) : (b))
// #define min(a, b) (((a) < (b)) ? (a) : (b))
// using std::cerr;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// typedef int myint;

// bool lessthan(myint* lhs,myint* rhs){
//     int i;
//     for(i=max(sizeof(lhs), sizeof(rhs))/sizeof(int)-1;i>=0&&lhs[i]==rhs[i];i--)
//     return i<0||lhs[i]<rhs[i];
// }

// int *multiply(int *a, int *b)
// {
//     int *c;
//     c = new int[105];
//     int maxsize = max(sizeof(a), sizeof(b))/sizeof(int);
//     for (int i = 0; i < maxsize; i++)
//         for (int j = 0; j < b[i]; j++)
//         {
//             int *d = c+i;
//             for (int k = 0; k < maxsize-i; k++)
//                 if ((d[k] += a[k]) >= 10)
//                 {
//                     d[k + 1]++;
//                     a[k] -= 10;
//                 }
//         }
//     return c;
// }

// void sub(myint *a, myint *b) {
//     int maxsize = max(sizeof(a), sizeof(b))/sizeof(int); 
// 	for(int i=0;i<maxsize;i++) 
// 		if((a[i]-=b[i])<0){  
// 			a[i+1]--;
// 			a[i]+=10;
// 		}
// }
// void sub(myint *a, myint *b,int maxsize) {
//     //int maxsize = max(sizeof(a), sizeof(b))/sizeof(int); 
// 	for(int i=0;i<maxsize;i++) 
// 		if((a[i]-=b[i])<0){  
// 			a[i+1]--;
// 			a[i]+=10;
// 		}
// }

// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     myint a[210],b[210];
//     int i,len=s1.size();
// 	for(i=0;i<len;i++) a[i]=s1[len-i-1]-'0';
// 	for(;i<210;i++) a[i]=0;
//     len=s2.size();
// 	for(i=0;i<len;i++) b[i]=s2[len-i-1]-'0';
// 	for(;i<210;i++) b[i]=0;
//     myint z[410];
//     for (int i = 0; i < 410; i++)
//     {
//         z[i]=0;
//     }
//     int tmp=405;
//     for(;b[tmp]==0;tmp--);
//     // for (int i=405-tmp;i>=0;i--)
//     // {
//     //     for(;lessthan(b,a+i,405-i),)
//     // }
// }