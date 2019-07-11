#include<iostream>
#include<cmath>
#include<algorithm>

int main(){
    int t;
    std::cin>>t;
    for (int i = 0; i < t; i++)
    {
        int num;
        std::cin>>num;
        for(int j=(int)sqrt(num);j>0;--j){
            if(num%j == 0){
                std::cout<<(j+num/j)*2<<std::endl;
                break;
            }
        }
    }
}
