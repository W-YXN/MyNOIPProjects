#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(){
    string num1,num2;
    cin>>num1;
    cin>>num2;
    std::reverse(num1.begin(),num1.end());
    std::reverse(num2.begin(),num2.end());
    // cerr<<num1<<endl<<num2;
    int zeros = 0;
    while(num1[0]=='0'){
        zeros++;
        num1.erase(num1.begin());
    }
    while(num2[0]=='0'){
        zeros++;
        num2.erase(num2.begin());
    }
    // cerr<<num1<<endl<<num2;
    int c[420]={0};
    for(int i=0;i<num1.length();i++){
        for (int j = 0; j < num2.length(); j++)
        {
            c[i+j]+= int(num1[i]-'0')*int(num2[j]-'0');
        }
    }
    string ans;
    for (int i = 0; i < 420; i++)
    {
        if (c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        ans += char(c[i]+'0');
    }
    //cerr<<ans<<endl;
    std::reverse(ans.begin(),ans.end());
    while(ans[0]=='0'){
        ans.erase(ans.begin());
    }
    cout<<ans;
    for (int i = 0; i < zeros; i++)
    {
        cout<<0;
    }
    cout<<endl;
    return 0;
}