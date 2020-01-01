#include "game.cpp"

using namespace std;

int main (){
srand(time(0));
string decision;
RoomCorr* room;
Game game1;



while(!game1.getPlayer().isDead()){
cin>>decision;
room=game1.passLogic(decision);
system("clear");
cout<<endl<<"Twoje zycie:"<<game1.getPlayer().getLife()<<endl;
game1.View(room);
}

};