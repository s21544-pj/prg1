#include <vector>
#include <string>
#include <fstream> 
#include <iostream>
#include "player.h"
#include "enemy.h"

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
    vector <int> roomDirection;
    string Layout;
};

class RoomCorr:public Room{
public:
    RoomCorr(string n,int a=-1,int b=-1,int c=-1):Room(n){
    if(a>=0)roomDirection.push_back(a);
        if(b>=0)roomDirection.push_back(b);
        if(c>=0)roomDirection.push_back(c);
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
            e.getDamage(10+p.getDMGWe());
            p.getDamage(10+e.getDMGWe());
            if(p.isDead()) return 6;
            else
            if(e.isDead()) return e.getRoom();
            else {
                cout<<"zycie przeciwnika: "<<e.getLife();
                return 0;
            }
        }
    }
    private:
        Enemy e;
};