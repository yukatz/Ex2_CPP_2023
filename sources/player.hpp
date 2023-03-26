#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace ariel{
class Player{
  public:   
    string name;
 
    //Constructor:
    Player();
    Player(string n);

    public:
    int stacksize();//prints the amount of cards left. should be 21 but can be less if a draw was played
    int cardesTaken();// prints the amount of cards this player has won.
    
};
};