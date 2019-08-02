#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

namespace sortstr{
    stringstream ss;
    typedef string magic;
    const bool operator<(const magic& lhs,const magic& rhs){
        int l,r;
        ss<<lhs;
        ss>>l;
        ss<<rhs;
        ss>>r;
        if(l<r) return false;
        if(l>r) return true;
        if(l==r) return lhs.length()<rhs.length();
    }
}

using namespace sortstr;

// int main(){
//     set<magic> st;
//     magic 
// }