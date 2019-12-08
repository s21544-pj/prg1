#include "rooms.h"
#include "player.h"

using namespace std;

class Game {
public:
    void setRooms(string n){
        Room r;
        r.setLayout(n);
        Rooms.push_back(r);
    }
    void View(int a){
        Rooms[a].viewRoom();
    }
    
private:
    vector <Room> Rooms;
};
