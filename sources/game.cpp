
#include "game.hpp"
namespace ariel{
    Game::Game(){

    }
    Game::Game(Player p_1, Player p_2){

    }
    
    void Game::playTurn(){};
    void Game::printLastTurn(){};//print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
    void Game::playAll(){}; //playes the game untill the end
    void Game::printWiner(){}; // prints the name of the winning player
    void Game::printLog(){}; // prints all the turns played one line per turn (same format as game.printLastTurn())
    void Game::printStats(){};// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )



};