#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <sstream>
using namespace std;
using namespace ariel;


TEST_CASE("Player constructor"){
   CHECK_NOTHROW(Player("Alice"));
   CHECK_NOTHROW(Player("Bob"));
   
}
TEST_CASE("Game constructor"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game(p1,p2));//The function does not throw an error
    Player p3("Sam");
    CHECK_THROWS(Game(p3,p3));//Can't put same player twise in one game
    CHECK_THROWS(Game(p1,p2));//One player can't join 2 games at the same time


}
  TEST_CASE("playTurn test"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playTurn());//The function does not throw an error
    game.playAll();
    if(p1.cardesTaken()!=p2.cardesTaken()){
            CHECK_THROWS(game.playTurn());//Try to play a turn after the end of the game

    }
    CHECK_NOTHROW(game.playTurn());//If both players won the same number of cards, they play again so the new turn is possible
  }

    TEST_CASE("Print last turn"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn());//The function does not throw an error

    /////Ptint functions test /////
    ostringstream output;
    streambuf* old_cout = cout.rdbuf(output.rdbuf());
    game.printLastTurn();
    cout.rdbuf(old_cout);
    CHECK(output.str() == ""); //No turn was plaied, nothing to print
    game.playTurn();
    game.printLastTurn();
    CHECK(output.str() != ""); //one turn was plaied, the output isn't empty


}
 TEST_CASE("stacksize"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(p1.stacksize());//The function does not throw an error
    CHECK(p1.stacksize()==25);//First, 52 cards are divided equally between 2 players.
    game.playTurn();
    game.playAll();
    CHECK(p2.stacksize()==0);//no cards in plaier hand after the end
    
}
TEST_CASE("cardesTaken"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(p1.cardesTaken());//No turn was plaied, no cards were taken
    game.playAll();
    CHECK_NOTHROW(p1.cardesTaken());//The function does not throw an error
    CHECK(p1.cardesTaken()<=52);//player will hold at most 52 cards
}
TEST_CASE("playAll"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll());//The function does not throw an error
    game.playAll();
    CHECK_THROWS(game.playAll());

}
TEST_CASE("printWiner"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());//No winner before the first turn
    game.playAll();
    CHECK_NOTHROW(game.printWiner());//The function does not throw an error

    /////Ptint functions test /////
    ostringstream output;
    streambuf* old_cout = cout.rdbuf(output.rdbuf());
    game.printWiner();
    cout.rdbuf(old_cout);
    if(p1.cardesTaken()!=p2.cardesTaken()){
    CHECK(output.str() != "");
    }//If both players won the same number of cards, they will play again so there is no winner
    CHECK(output.str() == "");

    
}
TEST_CASE("printLog"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLog());//The function does not throw an error

    /////Ptint functions test/////
    ostringstream output;
    streambuf* old_cout = cout.rdbuf(output.rdbuf());
    game.printLog();
    cout.rdbuf(old_cout);
    CHECK(output.str() == "");   //No game was played, no Log


}
TEST_CASE("printStats"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLog());//The function does not throw an error

    /////Ptint functions test /////
    ostringstream output;
    streambuf* old_cout = cout.rdbuf(output.rdbuf());
    game.printStats();
    cout.rdbuf(old_cout);
    CHECK(output.str() != "");   

}


