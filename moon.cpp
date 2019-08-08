#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            int num;
            cin>>num;
            if(num == 15){
                cout<<"DOWN"<<endl;
            }else if(num == 0){
                cout<<"UP"<<endl;
            }else{
                cout<<-1<<endl;
            }
            continue;
        }
        else if(n==0){
            cout<<"-1"<<endl;
            continue;
        }
        else{
            int *arr = new int[n+3];
            for (int i = 0; i < n; i++)
            {
                cin>>arr[i];
            }
            int num = arr[n-1];
             if(num == 15){
                cout<<"DOWN"<<endl;
            }else if(num == 0){
                cout<<"UP"<<endl;
            }else{
                if(arr[n-2]>arr[n-1]){
                    cout<<"DOWN"<<endl;
                }
                if(arr[n-2]<arr[n-1]){
                    cout<<"UP"<<endl;
                }
            }
            continue;
        }
    }
    return 0;
}

//chen_zhe NB!!!

