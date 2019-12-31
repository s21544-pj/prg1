
class Enemy:public Person{   
public:
    void setRoom(RoomCorr* e){
        room=e;
    }
    RoomCorr* getRoom(){
        return room;
    }
private:
    RoomCorr* room;
};

