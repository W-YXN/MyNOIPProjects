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


int length = 0;


template<typename TN> void swap(TN& lhs,TN& rhs){
    TN __TMP_ = lhs;
    lhs = rhs;
    rhs = __TMP_;
}


int getParent(int i)
{
    return i / 2;
}

int getLeftChild(int i)
{
    return i << 1;
}

int getRightChild(int i)
{
    return i << 1 + 1;
}

void maintainMaxHeap(int arr[], int i)
{
    int largest;
    int l = getLeftChild(i);
    int r = getRightChild(i);
    if (l <= length && arr[l] > arr[i])
    {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r<= length&& arr[r] > arr[largest])
    {
        largest = r;
    }
    if(! (largest == i)){
        swap(arr[i],arr[largest]);
        maintainMaxHeap(arr,largest);
    }
}

void buildMaxHeap(int arr[]){
    length = sizeof(arr) / sizeof(int) ;
    for (int i = length / 2 ; i > 0; i--)
    {
        maintainMaxHeap(arr,i);
    }
    
}

int main(){
    
}

