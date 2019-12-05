#include <vector>
#include <string>
#include <fstream> 
#include <iostream>

using namespace std;

class Game {
public:
    void setRooms(string n="r1"){
        Room r;
        r.setLayout(n);
        Rooms.push_back(r);
    }
    void View(int a){
        Rooms[a-1].viewRoom();
    }
private:
    vector <Room> Rooms;
};
class Room {
public:
    string setLayout(string n){
        string L="";
        ifstream file(n.append(".txt"));
        while (getline (file, L)) {
        L.append("\n");
        L.append(L);
        }
        Layout = L;
    };
    void viewRoom(){
        cout<<Layout;
    };
private:
    string Layout;
}