#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


TEST_CASE("Player creation"){
   CHECK_NOTHROW(Player("Alice"));
   CHECK_NOTHROW(Player("Bob"));
   
}
TEST_CASE("Game creation"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game(p1,p2));
}
  TEST_CASE("Play turn test"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playTurn());
}
    TEST_CASE("Print last turn"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn());
    game.playAll();

}
 TEST_CASE("stacksize"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    CHECK_NOTHROW(p1.stacksize());
    game.playAll();
    CHECK(p2.stacksize()==0);

}
TEST_CASE("cardesTaken"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(p1.cardesTaken());
}
TEST_CASE("playAll"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll());
}
TEST_CASE("printWiner"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printWiner());
    game.playAll();
    
}
TEST_CASE("printLog"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLog());
}
TEST_CASE("printStats"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLog());
}


