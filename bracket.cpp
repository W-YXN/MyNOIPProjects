/*
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
stack<int> st;
int main(){
    string s;
    cin>>s;
    //cout<<"F@ck you";
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(i);
        if(s[i]==')') st.pop();
        if(s[i]=='*') cout<<st.size();
    }
    return 0;
}
*/