class Enemy:public Person{   
public:
    void setRoom(int e){
        room=e;
    }
    int getRoom(){
        return room;
    }
private:
int room;
};

