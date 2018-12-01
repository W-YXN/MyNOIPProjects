#include<iostream>
#define cO cout //DEBUG
using namespace std;

typedef struct Rooms{
    bool hasStair;
    int key=-1024;
    int x=-1024;
    int y=-1024;
}rooms;

int m,n;
rooms room[10010][105];

inline rooms &nextRoom(int x,int y){
    cO<<endl<<endl;
    rooms &nowroom = room[x][y];
    int now_y = y;
    int next = nowroom.key;
    cO<<"&Next = "<<next<<endl;
    int cnt=0;
    if(nowroom.hasStair==1) cnt++;
    cO<<"cnt_beg="<<cnt<<endl;
    cO<<"nowroom= "<<nowroom.x<<" "<<nowroom.y<<endl;
    cO<<endl;
    if(cnt==next) return nowroom;
    while(true){
        now_y += 1;
        if(now_y>m-1) now_y=0;
        nowroom=room[x][now_y];
        if(nowroom.hasStair==1) cnt++;
        cO<<"nowroom= "<<nowroom.x<<" "<<nowroom.y<<endl;
        cO<<"cnt="<<cnt<<endl;
        cO<<"Next = "<<next<<endl;
        cO<<"cnt=next? "<<(cnt==next)<<endl;
        if(cnt==next) return nowroom;
    }
    cO<<endl<<endl;
}

int main(){
    int ans=0;
    cin>>n>>m;
    cO<<endl<<endl<<"n="<<n<<"\tm="<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin>>room[i][j].hasStair>>room[i][j].key;
            room[i][j].x=i;
            room[i][j].y=j;
        }
    }
    cO<<endl;
    rooms tmp_room = room[1][1];
    ans += tmp_room.key;
    cO<<"tmp_room= "<<tmp_room.x<<" "<<tmp_room.y<<endl;
    tmp_room = nextRoom(1,1);
    cO<<"tmp_room= "<<tmp_room.x<<" "<<tmp_room.y<<endl;
    cO<<"ans="<<ans<<endl;
    for(int i=2;i<=n;i++){
        tmp_room = room[tmp_room.x+1][tmp_room.y];
        ans += tmp_room.key;
        cO<<"tmp_room= "<<tmp_room.x<<" "<<tmp_room.y<<endl;
        tmp_room = nextRoom(tmp_room.x,tmp_room.y);
        cO<<"ans="<<ans<<endl;
    }
    cO<<endl;
    cout<<ans<<endl;
    return 0;
}