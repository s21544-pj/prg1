class Person{
    public:
    void setLife(int l){
        life=l;
    }
    int getLife(){
        return life;
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
    void setDMG(int c){
        dmgWea=c;
    }
    int getDMGWe(){
        return dmgWea;
    }
    protected:
    int dmgWea;
    int life;
};