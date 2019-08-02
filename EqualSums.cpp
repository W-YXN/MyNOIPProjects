#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> __Pair;
map<int,__Pair> hsh;

int main(){
    int n;
    cin>>n;
	hsh.clear();
	bool flag = false;
    for (int  i = 0; i < n; i++)
    {
        int l;
        cin>>l;
        int *a = new int[l];
        int sum = 0;
        for(int j=0;j<l;j++){
            cin>>a[i];
            sum+=a[i];
        }
        for(int j=0;j<l;j++){
            int mns = sum -a[j];
            
            if(!flag&&hsh.count(mns)&&hsh[mns].first!=i+1){
                flag = true;
				cout<<"YES"<<endl
                    <<i+1<<" "<<j+1<<endl
					<<hsh[mns].first<<' '<<hsh[mns].second<<endl;
                return 0;
            }
            
			__Pair pir;
			pir.first = i+1;
			pir.second = j+1;
			hsh[mns] = pir;
            // hsh[mns] = (__Pair)make_pair(i+1,j+1);    
        }
    }
	if(!flag)
    cout<<"NO"<<endl;
    return 0;
}
