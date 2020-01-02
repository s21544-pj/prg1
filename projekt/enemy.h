
class Enemy:public Person{   
public:
    void setRoom(RoomCorr* e){
        room=e;
    }
    RoomCorr* getRoom(){
        return room;
    }
    void setReward(string a){
        Reward=a;
    }
    string getReward(){
        return Reward;
    }
    void setValue(int b){
        value=b;
    }
    int getValue(){
        return value;
    }
private:
    string Reward;
    int value;
    RoomCorr* room;
};

