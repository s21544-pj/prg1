#include "person.h"

class Player:public Person{
    public:
    void setPlayerPosition(int a){
        player_location=a;
    }
    int getPlayerPosition(){
        return player_location;
    }
    void setTempPos(int b){
        tempPos=b;
    }
    int getTempPos(){
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
    int tempPos;
    int player_location;
};