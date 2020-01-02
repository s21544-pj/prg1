#include "rooms.h"

class Person{
    public:
    void setLife(float l){
        life=l;
    }
    int getLife(){
        return life;
    }
    bool isDead(){
        if(life>0){
            return 0;
        }
        else{
            return 1;
        }
    }
    void getDamage(int d){
        setLife(getLife()-d);
    }
    void setDMG(int c){
        dmgWea=c;
    }
    int getDMGWe(){
        return dmgWea;
    }
    void setAccuracy(int ac){
        accuracy=ac;
    }
    int getAccuracy(){
        return accuracy;
    }
    protected:
    int accuracy;
    int dmgWea;
    float life;
};