#include "rooms.h"
#include "player.h"

using namespace std;

class Game {
public:
    int logic(string d){
    int r;
    switch(p1.getPlayerPosition()){
    case 0:
    if(d=="1"){
    p1.setPlayerPosition(1);
    r=1;
    }else if(d=="2"){

    }else if(d=="3"){

    }
    return r;
    break;
    case 1:
    break;
    case 2:
    break;
    default:
    break;
    }
    }
    void Start(int n){
        p1.setPlayerPosition(n);
    }
    void setRooms(string n){
        Room r;
        r.setLayout(n);
        Rooms.push_back(r);
    }
    void View(int a){
        Rooms[a].viewRoom();

    }

private:
    Player p1;
    vector <Room> Rooms;
};
