#include "game.h"
#include <cstdlib>

using namespace std;

int main (){
string decision;
int room;
Game game1;
game1.setRooms("r1");
game1.setRooms("r2");
game1.View(0);
game1.Start(0);
while(1){
cin>>decision;
room=game1.logic(decision);
system("clear");
game1.View(room);
}
};