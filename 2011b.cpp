#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cctype>
#define cO cout //debug
#define pT(x) printf(x)
using namespace std;

inline char ToUpper(char ch){
    if(ch==' ') return ' ';
    else return toupper(ch);
}

int main(){
    string s1,s;
    char a[110],b[1000010];
    scanf("%[^\n]%*c%[^\n]%*c",a,b);
    int space=0;
    s1=a;
    transform(s1.begin(),s1.end(),s1.begin(),ToUpper);
    s=b;
    transform(s.begin(),s.end(),s.begin(),ToUpper);
    int first_appeared=-1,cnt=0;
    int place = 0;
    bool flag=0;
    string temp=s;
    while(true){
        //pT("\n");
        temp=temp.substr(place);
        //cO<<"$S1="<<s1<<endl;
        //cO<<"$temp="<<temp<<endl;
        place=temp.find(s1);
        //cO<<"$Place="<<place<<endl;
        if(place>=1000010||place<0){
            break;
        }else{
            if (temp[place + s1.length()]==' '){
                cnt++;
                //cO<<"@cnt="<<cnt<<endl;
                if(flag==0){
                    first_appeared=place;
                    flag=1;
                }
                place+=s1.length();
            }else{
                temp[place]=' ';
                for(int i=place-1;temp[i]!=' ';i--) temp[i]=' ';
                for(int i=place+1;temp[i]!=' ';i++) temp[i]=' ';
                place=0;
            }
        }
    }
    if(cnt==0){
        cout<<-1<<endl;
    }else{
        cout<<cnt<<' '<<first_appeared<<endl;
    }
    return 0;
}