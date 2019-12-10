#include "game.h"
#include <cstdlib>

using namespace std;

int main (){
string decision;
int room;
Game game1;
game1.setRooms("r0");
game1.setRooms("r1");
game1.setRooms("r2");
game1.setRooms("r3");
game1.setRooms("r100");
game1.View(0);
game1.Start(0);
while(1){
cin>>decision;
room=logic(decision,game1.getplayer());
system("clear");
cout<<"Twoje zycie:"<<game1.getplayer().getPlayerLife()<<endl;
game1.View(room);
}
};