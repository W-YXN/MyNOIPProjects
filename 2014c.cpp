#include<iostream>
#include<iomanip>
#undef INT_MAX
#define INT_MAX 214700000
#define __P_RIGHT 1
#define __P_DOWN 2
#define __P_LEFT 3
#define __P_UP 4
using namespace std;

typedef int Matrix;
typedef struct __Location
{
    int x;
    int y;
    short position;
}Location;

Matrix matrix[30010][30010]={(Matrix)0};
Location location;
Matrix my_now_Value=(Matrix)0;

inline void changePosition(Location& _L){
    _L.position+=1;
    if(_L.position==5) _L.position=1;
}

void locationGo(Location& _L){
    switch (_L.position)
    {
        case __P_RIGHT:
            if(matrix[_L.x][_L.y+1]!=0){
                changePosition(_L);
                locationGo(_L);
            }else{
                _L.y+=1;
            }
            break;
        case __P_DOWN:
            if(matrix[_L.x+1][_L.y]!=0){
                changePosition(_L);
                locationGo(_L);
            }else{
                _L.x+=1;
            }
            break;
        case __P_LEFT:
            if(_L.y==0||matrix[_L.x][_L.y-1]!=0){
                changePosition(_L);
                locationGo(_L);
            }else{
                _L.y-=1;
            }
            break;
        case __P_UP:
            if(_L.x==0||matrix[_L.x-1][_L.y]!=0){
                changePosition(_L);
                locationGo(_L);
            }else{
                _L.x-=1;
            }
            break;
        default:
            break;
    }
}

void printMatrix(int n){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            cout<<fixed<<setw(10)<<matrix[i][j];
        }
        cout<<endl;
    }
}

int main(){
	location.x=0;
    location.y=0;
	location.position=__P_RIGHT;
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++){
        matrix[i][n]=INT_MAX;
        matrix[n][i]=INT_MAX;
    }
    matrix[n+1][n+1]=INT_MAX;
    for(int i=0;i<n*n;i++){
        matrix[location.x][location.y]=my_now_Value;
        my_now_Value+=1;
        locationGo(location);
    }
    printMatrix(n);
    cout<<(int)matrix[x][y]<<endl;
    return 0;
}
