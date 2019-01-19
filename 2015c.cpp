#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct __Tape{
    int color;
    int number;
}Tape;

typedef struct __Group{
    int x;
    int y;
    int z;
}Group;

typedef int __Score;

Tape tape[100010];
int n,m;
__Score score;

__Score getScore(Group g){
    if(g.x>=g.y||g.y>=g.z||g.x>=g.z){
        //cerr<<"MyGroup:Invaid order!"<<endl;
        return (__Score)0 ;
    }else if(g.y-g.x!=g.z-g.y){
        //cerr<<"Mygroup:Wrong value!"<<endl;
        return (__Score)0 ;
    }
    else{
        if(tape[g.x].color==tape[g.z].color){
            __Score temp_score;
            temp_score = (g.x%10007 + g.z%10007)%10007 * (tape[g.x].number%10007 + tape[g.z].number%10007)%10007;
            //printf("$x=%d  $y=%d  $z=%d \n$xc=%d $yc=%d $zc=%d \n",g.x,g.y,g.z,tape[g.x].color,tape[g.y].color,tape[g.z].color);
            //cerr<<"$temp_score="<<temp_score<<endl;
            return temp_score%10007;
        }else{
            //cerr<<"$temp_score=0"<<endl;
            return (__Score)0 ;
        }
    }
}

inline void input(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) cin>>tape[i].number;
    for(int i=1;i<=n;i++){
        scanf("%d ",&tape[i].color);
        if (tape[i].color>m) {
            cerr<<"Myinput:WRONG_COLOR"<<endl; 
        }
    }
    //cerr<<"DONE!\n"<<flush;
}

int main(){
    input();
    for(int i = 1; i <= n-2; i++)
   {
       for(int j = 1; j <= (n-i+1)/2 ; j++)
       {
           //for(int f = j; f <= n; f++)
           //{
                //printf("$x=%d $y=%d $z=%d",i,j,f);
                Group tmp_group;
                tmp_group.x=i;
                tmp_group.y=i+j;
                tmp_group.z=i+j+j;
                if(tmp_group.z<=n){
                    score += getScore(tmp_group);
                    score %= 10007;
                }
            //}
        }
    }

   /*
   for(int i = 1; i <= n; i++)
   {
       for(int j = i; j <= n; j++)
       {
           for(int f = j; f <= n; f++)
           {
                //printf("$x=%d $y=%d $z=%d",i,j,f);
                Group tmp_group;
                tmp_group.x=i;
                tmp_group.y=j;
                tmp_group.z=f;
                if(tmp_group.z<=n){
                    score += getScore(tmp_group);
                    score %= 10007;
                }
            }
        }
    }
   */ //deleted
    cout<<(int)score<<endl;
    return 0;
}
