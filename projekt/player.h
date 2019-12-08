class Player{
    public:
    void setPlayerPosition(int a){
        player_location=a;
    }
    int getPlayerPosition(){
        return player_location;
    }
    private:
    int player_location;
};