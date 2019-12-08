#include <vector>
#include <string>
#include <fstream> 
#include <iostream>

using namespace std;

class Room {
public:
    void setLayout(string n){
        string L,F;
        ifstream file(n+".txt");
        while (getline (file, F)) {
        L.append(F);
        L.append("\n");
        }
        Layout = L;
        file.close();
    };
    void viewRoom(){
        cout<<Layout;
    };
private:
    string Layout;
};