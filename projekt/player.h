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
    private:
    int tempPos;
    int player_location;
};