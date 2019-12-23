#include "rooms.h"
#include "logic.cpp"

using namespace std;

class Game {
public:
    Game(){
        Room1 f("rWalka");
        Room1 r0("r0",2,3,4);
        Room1 r1("r1",0,1);
        Rooms.push_back(f);
        Rooms.push_back(r0);
        Rooms.push_back(r1);
        
        p1.setPlayerPosition(0);
        p1.setLife(50);
    }
    void View(int a){
        p1.setPlayerPosition(a);
        Rooms[a].viewRoom();
    }
    Player getPlayer(){
        return p1;
    }
    Person getEnemy(){
        return Enemy;
    }
    int passLogic(string d){
        return Rooms[p1.getPlayerPosition()].go(d);
        //return logic(d,p1,Enemy,Rooms.size());
    }
private:
    Person Enemy;
    Player p1;
    vector <Room1> Rooms;
};
