
#include "player.hpp"
namespace ariel{
    
    //Constructor:
    Player::Player(){};
    Player::Player(string n){
        name = n;
    }

    int Player::stacksize(){
        return 0;
        };//prints the amount of cards left. should be 21 but can be less if a draw was played
    int Player::cardesTaken(){
        return 0;
        };// prints the amount of cards this player has won.
    
};