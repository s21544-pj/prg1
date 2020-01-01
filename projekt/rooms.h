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
    void setRoomAtrib(RoomCorr* a,RoomCorr* b,RoomCorr* c,int f=-1,int tr=-1,string type="",int value=-1){
        roomDirection.push_back(a);
        roomDirection.push_back(b);
        roomDirection.push_back(c);
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
    float Test(float t){
        //less or equal is sucess
            if(t/TestDificult<=(rand()%99)+1){
                result = roomDirection[1];
                return RewardValue;
                
            }else{
                result = roomDirection[2];
                return RewardValue*(-1);
                
            };

    }
    RoomCorr* getResult(){
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
    RoomCorr* result;
    int fight;
    int TestDificult;
    int RewardValue;
    string RewardType;
    vector <RoomCorr*> roomDirection;
};


