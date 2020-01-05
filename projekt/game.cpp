#include "player.h"
#include "enemy.h"

using namespace std;

    RoomCorr f("rWalka");
    RoomCorr r1("r1");
    RoomCorr r2("r2");
    RoomCorr r3("r3");
    RoomCorr r4("r4");
    RoomCorr r5("r5");
    RoomCorr r6("r6");
    RoomCorr r7("r7");
    RoomCorr r8("r8");
    RoomCorr r9("r9");
    RoomCorr rEnd("rEnd");

class RoomFight:public Room{
    public:
    RoomFight(string n,int l,RoomCorr* r,int d,string re,int v,int ac):Room(n){
        e.setLife(l);
        e.setRoom(r);
        e.setDMG(d);
        e.setReward(re);
        e.setValue(v);
        e.setAccuracy(ac);
    };
    RoomCorr* fight(string f,Player& p){
            srand(time(0));
            int acc=(rand()%99)+1;
            int accEn=(rand()%99)+1;
            if(f=="1"){
            if(acc<(p.getAccuracy()+10)) e.getDamage(((p.getDMGWe()+rand()%9)+1)*2); else cout << "Nie trafiłeś | "; 
            if(acc<(e.getAccuracy()+10)) p.getDamage(((e.getDMGWe()+rand()%9)+1)*2);else cout <<"Stwór nie trafił | ";
            }else if(f=="2"){
            if(acc<p.getAccuracy()) e.getDamage(((p.getDMGWe()+rand()%9)+1));else cout << "Nie trafiłeś | ";
            if(acc<e.getAccuracy()) p.getDamage(((e.getDMGWe()+rand()%9)+1));else cout <<"Stwór nie trafił | ";
            }else if(f=="3"){
            if(acc<p.getAccuracy()) e.getDamage(((p.getDMGWe()+rand()%9)+1)/2);else cout << "Nie trafiłeś | ";
            if(acc<e.getAccuracy()) p.getDamage(((e.getDMGWe()+rand()%9)+1)/2);else cout <<"Stwór nie trafił | ";
            }
            if(e.isDead()) {
                if(e.getReward()=="magic") p.setMagic(p.getMagic()+e.getValue());
                if(e.getReward()=="money") p.setMoney(p.getMoney()+e.getValue());
                if(e.getReward()=="dmg") if(e.getValue()>p.getDMGWe()) p.setDMG(e.getValue());
                if(e.getReward()=="life") p.setLife(p.getLife()+e.getValue());
                p.setAccuracy(p.getAccuracy()+5);
                return e.getRoom();
            }
            else {
                cout<<"Pozostałe życie przeciwnika: "<<e.getLife();
                return p.getPlayerPosition();
        }
    }
    private:
        Enemy e;
};
    //fight declaration = life,room,dmg,RewardType,RewardValue,Accuracy
    RoomFight Rd("p0",20,&r5,10,"dmg",40,10);

class Game {
    
public:
    Game(){
    //fight declaration = life,room,dmg,RewardType,RewardValue,Accuracy
    RoomFight Rd("p0",20,&r5,10,"dmg",40,10);
    Rf.push_back(Rd);
    f.setRoomAtrib(&f,&f,&f);
    r1.setRoomAtrib(&r2,&r3,&r4);
    //0,back,cos innego,fight room
    r2.setRoomAtrib(&f,&r1,&rEnd,0);
    /*
    test room =layout of room, back, success, failure, -1,test dificult(1,2,5),
    Reward type(magic,money,life,dmg),Reward value 
    */
    r3.setRoomAtrib(&r1,&r6,&r7,-1,1,"magic",10);
    r4.setRoomAtrib(&r4,&r8,&r9,-1,5,"money",20);
    r5.setRoomAtrib(&r1,&r1,&r1);
    r6.setRoomAtrib(&r1,&r1,&r1);
    r7.setRoomAtrib(&r1,&r1,&r1);
    r8.setRoomAtrib(&r1,&r1,&r1);
    r9.setRoomAtrib(&r1,&r1,&r1);
    rEnd.setRoomAtrib(&r1,&r1,&r1);
    p1.setAccuracy(30);
    p1.setMagic(30);
    p1.setMoney(30);
    p1.setDMG(30);
    p1.setPlayerPosition(&r1);
    p1.setLife(50);
    View(&r1);
    }

    void View(RoomCorr* a){
    if(((p1.getPlayerPosition())!=&f)&&(p1.getTempPos())!=(p1.getPlayerPosition())&&a==&f){
        p1.setTempPos(p1.getPlayerPosition());
    }
    if(a==&f){
        Rf[(p1.getTempPos())->getFightNumber()].viewRoom();
    }
    p1.setPlayerPosition(a);
    a->viewRoom();
    }

    Player getPlayer(){
        return p1;
    }

    RoomCorr* passLogic(string d){
        if(p1.getPlayerPosition()==&f){
            return Rf[(p1.getTempPos())->getFightNumber()].fight(d,p1);
        }
        if((p1.getPlayerPosition())->getTr()>0){
            if(d=="1"){
                return (p1.getPlayerPosition())->go(d);
            }else{
                string RewardType = (p1.getPlayerPosition())->getRewardType();
                float t;
                if(RewardType=="magic") t=p1.getMagic();
                if(RewardType=="money") t=p1.getMoney();
                if(RewardType=="dmg") t=p1.getDMGWe();
                if(RewardType=="life") t=p1.getLife();
                if(RewardType=="accuracy") t=p1.getAccuracy();
                t = (p1.getPlayerPosition())->Test(t);
                if(RewardType=="magic") p1.setMagic(p1.getMagic()+t);
                if(RewardType=="money") p1.setMoney(p1.getMoney()+t);
                if(RewardType=="dmg") p1.setDMG(p1.getDMGWe()+t);
                if(RewardType=="life") p1.setLife(p1.getLife()+t);
                if(RewardType=="accuracy") p1.setAccuracy(p1.getAccuracy()+t);
                if(p1.getMoney()<=0)p1.setMoney(1);
                if(p1.getDMGWe()<5)p1.setDMG(5);
                if(p1.getAccuracy()<0)return &rEnd;
                if(p1.getMagic()<0)return &rEnd;
                return (p1.getPlayerPosition())->getResult();
            }
            }
            return (p1.getPlayerPosition())->go(d);
        
        }
private:

    vector <RoomFight>Rf;
    Player p1;
};

