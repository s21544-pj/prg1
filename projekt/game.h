#include "rooms.h"
#include "player.h"


using namespace std;

class Game {
public:
    Game(){
    //RoomFight Rf();
    RoomCorr f("rWalka");
    RoomCorr r0("r0",2,3,4);
    RoomCorr r1("r1",0,1);
    RoomCorr r2("r2",1,5);
    RoomCorr r3("r3");
    RoomsCorr.push_back(f);
    RoomsCorr.push_back(r0);
    RoomsCorr.push_back(r1);
    RoomsCorr.push_back(r2);
    RoomsCorr.push_back(r3);
        
        p1.setPlayerPosition(1);
        p1.setLife(50);
    }
    void View(int a){
        p1.setPlayerPosition(a);
    RoomsCorr[a].viewRoom();
    }
    Player getPlayer(){
        return p1;
    }
    Person getEnemy(){
        return Enemy;
    }
    int passLogic(string d){
        /*if(p1.getPlayerPosition()==0){

            Rf.fight(d,p1,Enemy);
            return 0;
        }*/
        return RoomsCorr[p1.getPlayerPosition()].go(d);
    }
private:
    //RoomFight Rf;
    Person Enemy;
    Player p1;
    vector <RoomCorr>RoomsCorr;
};
