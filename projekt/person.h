class Person{
    public:
    void setLife(int l){
        life=l;
    }
    int getLife(){
        return life;
    }
    void Back(int b){
        room=b;
    }
    int getBack(){
        return room;
    }
    bool isDead(){
        if(life>0){
            return 0;
        }
        else{
            return 1;
        }
    }
    void getDamage(int d){
        setLife(getLife()-d);
    }
    protected:
    int room;
    int life;
};