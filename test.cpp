#include "doctest.h"
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using namespace ariel;

// TEST_SUITE - Keeps the initialization code together

TEST_SUITE("Catan Initialization Test Suite") {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(&p1, &p2, &p3);

    TEST_CASE("Choose Starting Player Outputs Amit") {
        // Capture the output of chooseStartingPlayer
        stringstream buffer;
        streambuf *old = cout.rdbuf(buffer.rdbuf());
        catan.chooseStartingPlayer();
        // Restore the original cout buffer
        cout.rdbuf(old);
        // Check the output
        string output = buffer.str();
        CHECK(output == "Starting player: Amit\n");
    }

    
    TEST_CASE("Placing a settlement and road on the board") {
        vector<int> placesNum = {5, 6};
        p1.placeSettlement(placesNum, catan);
        p1.placeRoad(placesNum, catan);
        p1.placeSettlement({7, 8}, catan);
        p1.placeRoad({7, 8}, catan);
        p1.endTurn(catan);
        // Attempting to place a settlement not on the player's turn:
        CHECK_THROWS_WITH(p1.placeSettlement(placesNum, catan),"It's not your turn!");
    }

    TEST_CASE("Second player placing a settlment on a taken spot") {
         vector<int> placesNum = {5, 6};
        CHECK_THROWS_WITH(p2.placeSettlement(placesNum, catan), "One of the places already has a settlement!");
    }

    TEST_CASE("Placing a road on a spot that the player doesn't own") {
        p2.placeSettlement({1, 2}, catan);
        CHECK_THROWS_WITH(p2.placeRoad({3,4}, catan), "You can't build a road on a place that you don't own!");
    }

    TEST_CASE("Building a road on illegal spots"){
        p2.placeRoad({1,2}, catan);
        p2.placeSettlement({11,12}, catan);
        p2.placeRoad({11,12}, catan);
        p2.endTurn(catan);
        p3.placeSettlement({9,10}, catan);

        CHECK_THROWS_WITH(p3.placeRoad({9,14}, catan), "There is no road between the two places!");
    }

    TEST_CASE("Ending first round before building 2 roads and 2 settlements") {
        p3.placeRoad({9,10}, catan);
        p3.placeSettlement({13,14}, catan);
        CHECK_THROWS_WITH(p3.endTurn(catan), "You need to build a road first!");
    }
}
