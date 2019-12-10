class Player{
    public:
    void setPlayerPosition(int a){
        player_location=a;
    }
    int getPlayerPosition(){
        return player_location;
    }
    void setPlayerLife(int l){
        player_life=l;
    }
    int getPlayerLife(){
        return player_life;
    }
    bool isPlayerDead(){
        if(player_life>0){
            return 0;
        }
        else{
            return 1;
        }
    }
    void getDamage(int d){
        setPlayerLife(getPlayerLife()-d);
    }
    private:
    int player_location;
    int player_life;
};