#include "game.h"
#include <cstdlib>

using namespace std;

int main (){
string decision;
int room;
Game game1;
game1.View(1);

while(1){
cin>>decision;
room=game1.passLogic(decision);
system("clear");
cout<<"Twoje zycie:"<<game1.getPlayer().getLife()<<endl;
game1.View(room);
if(game1.getPlayer().getTempPos()>0){
cout<<endl<<"zycie przeciwnika"<<game1.getEnemy().getLife();
}
}
};