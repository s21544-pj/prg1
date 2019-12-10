#include <string>
#include "player.h"

int logic(string d,Player p1){
    int r;
    switch(p1.getPlayerPosition()){
    case 0:
    if(d=="1"){
    p1.setPlayerPosition(1);
    r=1;
    }else if(d=="2"){
        p1.setPlayerPosition(2);
        r=2;
    }else if(d=="3"){
        p1.setPlayerPosition(3);
        r=3;
    }
    break;
    case 1:
    break;
    case 2:
    break;
    default:
    break;
    }
    if(p1.isPlayerDead()){
    r=4;
    }
    return r;
}