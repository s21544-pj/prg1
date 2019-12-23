#include "rooms.h"


using namespace std;

class Game {
public:
    Game(){

    RoomFight Rd("p0");
    Rf.push_back(Rd);
    RoomCorr f("rWalka",0);
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
        if(a==0){
            p1.setTempPos(p1.getPlayerPosition());
        }
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
        if(p1.getPlayerPosition()==0){
            Enemy.setDMG(10);
            Enemy.setLife(20);
            Rf[0].fight(d,p1,Enemy);
            return 0;
        }else
        return RoomsCorr[p1.getPlayerPosition()].go(d);
    }
private:
    vector <RoomFight>Rf;
    Person Enemy;
    Player p1;
    vector <RoomCorr>RoomsCorr;
};
