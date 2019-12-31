#include "game.cpp"

using namespace std;

int main (){
srand(time(0));
string decision;
RoomCorr* room;
Game game1;



while(1){
cin>>decision;
room=game1.passLogic(decision);
system("clear");
cout<<endl<<"Twoje zycie:"<<game1.getPlayer().getLife()<<endl;
game1.View(room);
}
};