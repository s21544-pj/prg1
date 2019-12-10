#include <string>
#include "player.h"

int logic(string d,Player& p1,Person& enemy){
    int r;
    switch(p1.getPlayerPosition()){
    case 0:
    if(d=="1"){
    r=1;
    }else if(d=="2"){
        r=2;
    }else if(d=="3"){
        r=3;
    }
    break;
    case 1:
    enemy.setLife(20);
    enemy.Back(4);
    if(d=="1"){
        r=5;
    }else if(d=="2"){
        r=0;
    }
    break;
    case 2:
    break;
    case 5:
    p1.getDamage(5);
    enemy.getDamage(10);
    if(enemy.isDead()){

        r=enemy.getBack();
    }else{
        r=5;
    }
    break;
    
    default:
    break;
    }
    if(p1.isDead()){
    //last index of table
    r=6;
    }
    return r;
}