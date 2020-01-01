#include "person.h"

class Player:public Person{
    public:
    void setPlayerPosition(RoomCorr* a){
        player_location=a;
    }
    RoomCorr* getPlayerPosition(){
        return player_location;
    }
    void setTempPos(RoomCorr* b){
        tempPos=b;
    }
    RoomCorr* getTempPos(){
        return tempPos;
    }
    void setMagic(int c){
        magic=c;
    }
    int getMagic(){
        return magic;
    }
    void setMoney(int d){
        money=d;
    }
    int getMoney(){
        return money;
    }
    private:
    int magic;
    int money;
    RoomCorr* tempPos;
    RoomCorr* player_location;
};
