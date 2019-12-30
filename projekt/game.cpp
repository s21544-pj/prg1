#include "rooms.h"

using namespace std;

class Game {
public:
    Game(){
    //fight declaration = life,room,dmg
    RoomFight Rd("p0",20,5,10);
    Rf.push_back(Rd);
    RoomCorr f("rWalka",0);
    RoomCorr r1("r0",2,3,4);
    //fight = 0,back,-1,enemy room(Rf)
    RoomCorr r2("r1",0,1,-1,0);
    /*
    test room =layout of room, back, success, failure, -1,test dificult(1,2,5),
    Reward type(magic,money,life,dmg),Reward value
    */
    RoomCorr r3("r2",1,6,7,-1,1,"money",10);
    RoomCorr r4("r3");
    RoomCorr r5("r4");
    RoomCorr r6("r5");
    RoomCorr r7("r6");
    RoomCorr rEnd("rEnd");
    RoomsCorr.push_back(f);
    RoomsCorr.push_back(r1);
    RoomsCorr.push_back(r2);
    RoomsCorr.push_back(r3);
    RoomsCorr.push_back(r4);
    RoomsCorr.push_back(r5);
    RoomsCorr.push_back(r6);
    RoomsCorr.push_back(r7);
    RoomsCorr.push_back(rEnd);
    if(RoomsCorr.size()==9){cout<<"jest okej!";}
    p1.setMagic(30);
    p1.setMoney(30);
    p1.setTempPos(-1);
    p1.setDMG(30);
    p1.setPlayerPosition(1);
    p1.setLife(50);
    }

    void View(int a){
    if(p1.getPlayerPosition()!=0&&p1.getTempPos()!=p1.getPlayerPosition()&&a==0){
        p1.setTempPos(p1.getPlayerPosition());
    }
    if(a==0){
        Rf[RoomsCorr[p1.getTempPos()].getFightNumber()].viewRoom();
    }
    p1.setPlayerPosition(a);
    RoomsCorr[a].viewRoom();
    }

    Player getPlayer(){
        return p1;
    }

    int passLogic(string d){
        if(p1.isDead()) return 8; else {

        if(p1.getPlayerPosition()==0){
            return Rf[RoomsCorr[p1.getTempPos()].getFightNumber()].fight(d,p1);
        }else
        if(RoomsCorr[p1.getPlayerPosition()].getTr()<0){
            return RoomsCorr[p1.getPlayerPosition()].go(d);
        }else{
            if(d=="1"){
                return RoomsCorr[p1.getPlayerPosition()].go(d);
            }else{
                return RoomsCorr[p1.getPlayerPosition()].Test(p1);
            }
        }
        }
    }
private:
    vector <RoomFight>Rf;
    Player p1;
    vector <RoomCorr>RoomsCorr;
};
