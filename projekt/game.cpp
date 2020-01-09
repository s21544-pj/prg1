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
RoomCorr r10("r10");
RoomCorr r11("r11");
RoomCorr r12("r12");
RoomCorr r13("r13");
RoomCorr r14("r14");
RoomCorr r15("r15");
RoomCorr r16("r16");
RoomCorr r17("r17");
RoomCorr r18("r18");
RoomCorr r19("r19");
RoomCorr r20("r20");
RoomCorr r21("r21");
RoomCorr r22("r22");
RoomCorr r23("r23");
RoomCorr r24("r24");
RoomCorr r25("r25");
RoomCorr r26("r26");
RoomCorr r27("r27");
RoomCorr r28("r28");
RoomCorr r29("r29");
RoomCorr r30("r30");
RoomCorr r31("r31");
RoomCorr r32("r32");
RoomCorr r33("r33");
RoomCorr r34("r34");
RoomCorr r35("r35");
RoomCorr r36("r36");
RoomCorr r37("r37");
RoomCorr r38("r38");
RoomCorr r39("r39");
RoomCorr r40("r40");
RoomCorr r41("r41");
RoomCorr r42("r42");
RoomCorr r43("r43");
RoomCorr r44("r44");
RoomCorr r45("r45");
RoomCorr r46("r46");
RoomCorr r47("r47");
RoomCorr rEnd("rEnd");
RoomCorr rEndAccuracy("rEnd");
RoomCorr rEndMagic("rEnd");

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

class Game {
    
public:
    Game(){
    //fight declaration = life,room,dmg,RewardType,RewardValue,Accuracy
    RoomFight Rd("p0",20,&r5,10,"dmg",40,10);
    RoomFight Rd2("p1",30,&r28,20,"life",40,50);
    RoomFight Rd3("p2",25,&r37,15,"accuracy",20,60);
    RoomFight Rd4("p3",66,&r38,40,"dmg",66,35);
    RoomFight Rd5("p4",100,&r46,30,"magic",100,50);
    Rf.push_back(Rd);
    Rf.push_back(Rd2);
    Rf.push_back(Rd3);
    Rf.push_back(Rd4);
    Rf.push_back(Rd5);
    f.setRoomAtrib(&f,&f,&f);
    r1.setRoomAtrib(&r2,&r3,&r4);
    //0,back,cos innego,fight room
    r2.setRoomAtrib(&f,&r1,&r1,0);
    /*
    test room =layout of room, back, success, failure, -1,test dificult(1,2,5),
    Reward type(magic,money,life,dmg),Reward value 
    */
    r3.setRoomAtrib(&r1,&r6,&r7,-1,1,"magic",10);
    r4.setRoomAtrib(&r1,&r8,&r9,-1,5,"money",20);
    r5.setRoomAtrib(&r10,&r13,&r13);
    r6.setRoomAtrib(&r13,&r13,&r13);
    r7.setRoomAtrib(&r13,&r13,&r13);
    r8.setRoomAtrib(&r14,&r14,&r14);
    r9.setRoomAtrib(&r14,&r14,&r14);
    r10.setRoomAtrib(&r13,&r11,&r12);
    r11.setRoomAtrib(&r10,&r15,&r15);
    r12.setRoomAtrib(&r10,&r16,&r16,-1,0.1,"life",40);
    r13.setRoomAtrib(&r10,&r26,&r27);
    r14.setRoomAtrib(&r27,&r13,&r13);
    r15.setRoomAtrib(&r11,&r19,&r20,-1,1,"dmg",10);
    r16.setRoomAtrib(&r17,&r22,&r22);
    r17.setRoomAtrib(&r16,&r18,&r18);
    r18.setRoomAtrib(&r17,&r18,&r13);
    r19.setRoomAtrib(&r21,&r21,&r21);
    r20.setRoomAtrib(&r21,&r21,&r21);
    r21.setRoomAtrib(&r21,&r25,&r25);
    r22.setRoomAtrib(&r16,&r23,&r24,-1,1,"magic",5);
    r23.setRoomAtrib(&r25,&r25,&r25);
    r24.setRoomAtrib(&r22,&r25,&r25);
    r25.setRoomAtrib(&r22,&r21,&f,3);
    r26.setRoomAtrib(&r13,&f,&f,1);
    r27.setRoomAtrib(&r13,&r29,&r30,-1,1,"magic",10);
    r28.setRoomAtrib(&r34,&r32,&r33,-1,1,"accuracy",20);
    r29.setRoomAtrib(&r31,&r31,&r31);
    r30.setRoomAtrib(&r27,&r31,&r31);
    r31.setRoomAtrib(&r34,&r34,&r34);
    r32.setRoomAtrib(&r34,&r34,&r34);
    r33.setRoomAtrib(&r34,&r34,&r34);
    r34.setRoomAtrib(&r35,&r36,&r36);
    r35.setRoomAtrib(&r10,&r34,&r34);
    r36.setRoomAtrib(&r34,&f,&f,2);
    r37.setRoomAtrib(&r42,&r42,&r42);
    r38.setRoomAtrib(&r35,&r39,&r40,-1,1,"accuracy",5);
    r39.setRoomAtrib(&r41,&r41,&r41);
    r40.setRoomAtrib(&r41,&r41,&r41);
    r41.setRoomAtrib(&r42,&r42,&r42);
    r42.setRoomAtrib(&f,&r43,&r43,4);
    r43.setRoomAtrib(&r43,&r44,&r45,-1,1,"magic",10);
    r44.setRoomAtrib(&r43,&r43,&r43);
    r45.setRoomAtrib(&r43,&r43,&r43);
    rEnd.setRoomAtrib(&rEnd,&rEnd,&rEnd);
    rEndAccuracy.setRoomAtrib(&rEnd,&rEnd,&rEnd);
    rEndMagic.setRoomAtrib(&rEnd,&rEnd,&rEnd);
    p1.setAccuracy(40);
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
                if(p1.getAccuracy()<=0)return &rEndAccuracy;
                if(p1.getMagic()<=0)return &rEndMagic;
                return (p1.getPlayerPosition())->getResult();
            }
            }
            return (p1.getPlayerPosition())->go(d);
        
        }
    private:

        vector <RoomFight>Rf;
        Player p1;
    };

