#include <vector>
#include <string>
#include <fstream> 
#include <iostream>
#include "player.h"
#include "enemy.h"
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
    RoomCorr(string n,int a=-1,int b=-1,int c=-1,int f=-1,int tr=-1,string type="",int value=-1):Room(n){
    if(a>=0)roomDirection.push_back(a);
        if(b>=0)roomDirection.push_back(b);
        if(c>=0)roomDirection.push_back(c);
        if(f>=0)fight=f;
        if(tr>=0)
        {
            TestDificult=tr;
            RewardType=type;
            RewardValue=value;
        };
}
    int getTr(){
        return TestDificult;
    }
    int Test(Player& p){
        //less or equal is sucess
        float t;
        if(RewardType=="magic") t=p.getMagic();
        if(RewardType=="money") t=p.getMoney();
        if(RewardType=="dmg") t=p.getDMGWe();
        if(RewardType=="life") t=p.getLife();
            if(t/TestDificult<=(rand()%99)+1){
                t=RewardValue;
            }else{
                t=RewardValue*(-1);
            };
        if(RewardType=="magic") p.setMagic(p.getMagic()+t);
        if(RewardType=="money") p.setMoney(p.getMoney()+t);
        if(RewardType=="dmg") p.setDMG(p.getDMGWe()+t);
        if(RewardType=="life") p.setLife(p.getLife()+t);
        if(t>0) return roomDirection[1];
        if(t<0) return roomDirection[2];

    }
    int go(string d){
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
    int fight;
    int TestDificult;
    int RewardValue;
    string RewardType;
    vector <int> roomDirection;
};

class RoomFight:public Room{
    public:
    RoomFight(string n,int l,int r,int d):Room(n){
        e.setLife(l);
        e.setRoom(r);
        e.setDMG(d);
    };
    int fight(string f,Player& p){
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
            if(p.isDead()) return 8;
            else
            if(e.isDead()) return e.getRoom();
            else {
                cout<<"zycie przeciwnika: "<<e.getLife();
                return 0;
        }
    }
    private:
        Enemy e;
};