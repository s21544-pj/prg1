#include "game.cpp"

using namespace std;

int main (){
system("clear");
string decision;
RoomCorr* room;
Game game1;



while(!game1.getPlayer().isDead()){
cin>>decision;
if(decision=="1"||decision=="2"||decision=="3"){
room=game1.passLogic(decision);
system("clear");
cout<<endl<<"Twoje zycie:"<<game1.getPlayer().getLife()<<endl;
cout<<"Twoje pieniadze:"<<game1.getPlayer().getMoney()<<endl;
cout<<"Twoja magia:"<<game1.getPlayer().getMagic()<<endl;
cout<<"Dmg Twojej Broni:"<<game1.getPlayer().getDMGWe()<<endl;
cout<<"Twoja Celność: "<<game1.getPlayer().getAccuracy()<<"%"<<endl;
game1.View(room);
}
else{
    cout<<"Błędny klawisz!"<<endl;
}
}
system("clear");
if(game1.getPlayer().isDead())game1.View(&rEnd);
};