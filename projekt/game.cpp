#include "player.h"
#include "enemy.h"

using namespace std;

RoomCorr f("rWalka");
    RoomCorr r1("r1");
    //fight = 0,back,-1,enemy room(Rf)
    RoomCorr r2("r2");
    /*
    test room =layout of room, back, success, failure, -1,test dificult(1,2,5),
    Reward type(magic,money,life,dmg),Reward value 
    */
    RoomCorr r3("r3");
    RoomCorr r4("r4");
    RoomCorr r5("r5");
    RoomCorr r6("r6");
    RoomCorr r7("r7");
    RoomCorr rEnd("rEnd");
    //fight declaration = life,room,dmg
    RoomFight Rd("p0",20,&r5,10);

class Game {
    
public:
    Game(){
    Rf.push_back(Rd);
    f.setRoomAtrib(&f);
    r1.setRoomAtrib(&r2,&r3,&r4);
    r2.setRoomAtrib(&r1,&f);
    r3.setRoomAtrib(&r1,&r6,&r7,-1,1,"money",10);
    p1.setMagic(30);
    p1.setMoney(30);
    p1.setDMG(30);
    p1.setPlayerPosition(&r1);
    p1.setLife(50);
    }

    void View(RoomCorr* a){
        //cannot if with pointers?
    if(((p1.getPlayerPosition())!=&f)&&(p1.getTempPos())!=(p1.getPlayerPosition())&&a==&f){
        p1.setTempPos(p1.getPlayerPosition());
    }
    if(a==&f){
        Rf[(*p1.getTempPos()).getFightNumber()].viewRoom();
    }
    p1.setPlayerPosition(a);
    (*a).viewRoom();
    }

    Player getPlayer(){
        return p1;
    }

    RoomCorr* passLogic(string d){
        if(p1.isDead()) return &rEnd; else {

        if(p1.getPlayerPosition()==&f){
            return Rf[(*p1.getTempPos()).getFightNumber()].fight(d,p1);
        }else
        if((*p1.getPlayerPosition()).getTr()<0){
            return (*p1.getPlayerPosition()).go(d);
        }else{
            if(d=="1"){
                return (*p1.getPlayerPosition()).go(d);
            }else{
                string RewardType = (*p1.getPlayerPosition()).getRewardType();
                float t;
                if(RewardType=="magic") t=p1.getMagic();
                if(RewardType=="money") t=p1.getMoney();
                if(RewardType=="dmg") t=p1.getDMGWe();
                if(RewardType=="life") t=p1.getLife();
                RoomCorr* n=(*p1.getPlayerPosition()).Test(t);
                t=(*p1.getPlayerPosition()).getResult();
                if(RewardType=="magic") p1.setMagic(p1.getMagic()+t);
                if(RewardType=="money") p1.setMoney(p1.getMoney()+t);
                if(RewardType=="dmg") p1.setDMG(p1.getDMGWe()+t);
                if(RewardType=="life") p1.setLife(p1.getLife()+t);
                return n;
            }
        }
        }
    }
private:

    vector <RoomFight>Rf;
    Player p1;
    //vector <RoomCorr>RoomsCorr;
};
