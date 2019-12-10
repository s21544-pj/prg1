#include "rooms.h"
#include "logic.cpp"

using namespace std;

class Game {
public:
    void Start(){
        for(int i=0;i<5;i++){
            setRooms("r"+to_string(i));
        }
        setRooms("rWalka");
        setRooms("rEnd");
        p1.setPlayerPosition(0);
        p1.setLife(50);
    }
    void setRooms(string n){
        Room r;
        r.setLayout(n);
        Rooms.push_back(r);
    }
    void View(int a){
        p1.setPlayerPosition(a);
        Rooms[a].viewRoom();
    }
    Player getPlayer(){
        return p1;
    }
    Person getEnemy(){
        return Enemy;
    }
    int passLogic(string d){
        return logic(d,p1,Enemy);
    }
private:
    Person Enemy;
    Player p1;
    vector <Room> Rooms;
};
