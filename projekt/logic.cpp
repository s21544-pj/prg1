#include <string>
#include "player.h"

int logic(string d,Player& p1,Person& enemy,int re){
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
    //damage based on "type" of monster?
    enemy.setLife(20);
    enemy.Back(4);
    if(d=="1"){
        r=re-2;
    }else if(d=="2"){
        r=0;
    }
    break;
    case 2:
    break;
    //need manualy change value of fight room
    case 5:
    p1.getDamage(50);
    enemy.getDamage(10);
    if(enemy.isDead()){
        r=enemy.getBack();
    }else{
        r=re-2;
    }
    break;
    
    default:
    break;
    }
    if(p1.isDead()){
    //last index of table
    r=re-1;
    }
    return r;
}