#include <vector>
#include <string>
#include <fstream> 
#include <iostream>

using namespace std;

class Room {
public:
    Room(string n,int a=-1,int b=-1,int c=-1){
        if(a>=0)roomDirection.push_back(a);
        if(b>=0)roomDirection.push_back(b);
        if(c>=0)roomDirection.push_back(c);
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
using Room::Room;
public:
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

/*class RoomFight:public Room{
    public:
    int fight(string d,Player& p,Person& e){
        if(d=="a"){
            e.getDamage(1);
            p.getDamage(1);
        }
    }
};*/