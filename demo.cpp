/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"

using namespace std;
using namespace ariel;

int main()
{
    // initialize the players: Amit, Yossi, Dana.
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");

    Catan catan(&p1, &p2, &p3); // initialize the game with the players.
    
    catan.chooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    Board board = catan.getBoard(); // get the board of the game.
    vector<int> placesNum = {5, 6};
    p1.placeSettlement(placesNum, catan);
    p1.placeRoad(placesNum, catan);
    p1.placeSettlement({7, 8}, catan);
    p1.placeRoad({7, 8}, catan);
    p1.endTurn(catan);

    
    try{
        p1.placeSettlement(placesNum, catan);
    } catch(const std::exception &e) { // should print "It's not your turn!"
        std::cerr << " - " << e.what() << std::endl;
    }

    try{
        p2.placeSettlement(placesNum, catan);
    } catch(const std::exception &e) { // should print "One of the places already has a settlement!"
        std::cerr << " - " << e.what() << std::endl;
    }

    p2.placeSettlement({1, 2}, catan);
    try{
        p2.placeRoad({3,4}, catan);
    } catch(const std::exception &e) { // should print "You can't build a road on a place that you don't own!"
        std::cerr << " - " << e.what() << std::endl;
    }

    p2.placeRoad({1,2}, catan);
    p2.placeSettlement({11,12}, catan);
    p2.placeRoad({11,12}, catan);
    p2.endTurn(catan);

    p3.placeSettlement({9,10}, catan);
    try{
        p3.placeRoad({9,14}, catan);
    } catch(const std::exception &e) { // should print "There is no road between the two places!"
        std::cerr << " - " << e.what() << std::endl;
    }
    p3.placeRoad({9,10}, catan);
    p3.placeSettlement({13,14}, catan);
    p3.placeRoad({13,14}, catan);
    p3.endTurn(catan);

    //catan.currentTurn(); // should print the name of the current player, it should be Amit again after a full round.

    p1.printPlayerStats();

    return 0;
}