#include "rooms.h"
#include "logic.cpp"

using namespace std;

class Game {
public:
    void Start(int n){
        p1.setPlayerPosition(n);
        p1.setPlayerLife(50);
    }
    void setRooms(string n){
        Room r;
        r.setLayout(n);
        Rooms.push_back(r);
    }
    void View(int a){
        Rooms[a].viewRoom();

    }
    Player getplayer(){
        return p1;
    }
private:
    Player p1;
    vector <Room> Rooms;
};
