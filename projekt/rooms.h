#include <vector>
#include <string>
#include <fstream> 
#include <iostream>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>

using namespace std;

class Room {
public:
Room(string n){
        string L,F;
        ifstream file(n+".txt");
        while (getline (file, F)) {
        L.append(F);
        L.append("\n");
        }
        Layout = L;
        file.close();
    };
    void viewRoom(){
        cout<<Layout;
    };
protected:
    string Layout;
};

class RoomCorr:public Room{
public:
    RoomCorr(string n):Room(n){};
    void setRoomAtrib(RoomCorr* a=NULL,RoomCorr* b=NULL,RoomCorr* c=NULL,int f=-1,int tr=-1,string type="",int value=-1){
        if(&a!=NULL)roomDirection.push_back(a);
        if(&b!=NULL)roomDirection.push_back(b);
        if(&c!=NULL)roomDirection.push_back(c);
        if(f!=-1)fight=f;
        if(tr!=-1)
        {
            TestDificult=tr;
            RewardType=type;
            RewardValue=value;
        };
    }
    int getTr(){
        return TestDificult;
    }
    string getRewardType(){
        return RewardType;
    }
    RoomCorr* Test(float t){
        //less or equal is sucess
            if(t/TestDificult<=(rand()%99)+1){
                t=RewardValue;
            }else{
                t=RewardValue*(-1);
            };
        if(t>0) {
            result = t;
            return roomDirection[1];
        };
        if(t<0) {
            result = t;
            return roomDirection[2];
        };

    }
    int getResult(){
        return result;
    }
    RoomCorr* go(string d){
        if(d=="1"){
            return roomDirection[0];
        }else if(d=="2"){
            return roomDirection[1];
        }else if(d=="3"){
            return roomDirection[2];
        }
    }
    int getFightNumber(){
        return fight;
    }
    private:
    int result;
    int fight;
    int TestDificult;
    int RewardValue;
    string RewardType;
    vector <RoomCorr*> roomDirection;
};

class RoomFight:public Room{
    public:
    RoomFight(string n,int l,RoomCorr* r,int d):Room(n){
        e.setLife(l);
        e.setRoom(r);
        e.setDMG(d);
    };
    RoomCorr* fight(string f,Player& p){
        if(f=="a"){
            e.getDamage(p.getDMGWe()*2);
            p.getDamage(e.getDMGWe()*2);
            }else if(f=="p"){
            e.getDamage(p.getDMGWe());
            p.getDamage(e.getDMGWe());
            }else if(f=="d"){
            e.getDamage(p.getDMGWe()/2);
            p.getDamage(e.getDMGWe()/2);
            }
            if(e.isDead()) return e.getRoom();
            else {
                cout<<"zycie przeciwnika: "<<e.getLife();
        }
    }
    private:
        Enemy e;
};
