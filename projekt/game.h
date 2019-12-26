#include "rooms.h"


using namespace std;

class Game {
public:
    Game(){
    //life,room,dmg
    RoomFight Rd("p0",20,5,10);
    Rf.push_back(Rd);
    RoomCorr f("rWalka",0);
    RoomCorr r0("r0",2,3,4);
    RoomCorr r1("r1",0,1);
    RoomCorr r2("r2",1,5);
    RoomCorr r3("r3");
    RoomCorr rEnd("rEnd");
    RoomsCorr.push_back(f);
    RoomsCorr.push_back(r0);
    RoomsCorr.push_back(r1);
    RoomsCorr.push_back(r2);
    RoomsCorr.push_back(r3);
    RoomsCorr.push_back(r3);
    RoomsCorr.push_back(rEnd);

    p1.setDMG(5);
    p1.setPlayerPosition(1);
    p1.setLife(50);
    }
    void View(int a){
    if(a==0){
        Rf[a].viewRoom();
    }
    p1.setPlayerPosition(a);
    RoomsCorr[a].viewRoom();
    }
    Player getPlayer(){
        return p1;
    }
    int passLogic(string d){
        if(p1.getPlayerPosition()==0){
            int t;
            t = Rf[0].fight(d,p1);
            return t;

        }else
        return RoomsCorr[p1.getPlayerPosition()].go(d);
    }
private:
    vector <RoomFight>Rf;
    Player p1;
    vector <RoomCorr>RoomsCorr;
};
