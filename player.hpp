#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "board.hpp"
#include <string>
#include <vector>
#include <map>

namespace ariel{
    class Player{

        public:
            Player(const std::string& name); // Constructor
            const std::string& getName() const; // Getter for name
            void printPoints(); // Prints player's points
            void placeSettlement(std::vector<std::string>& places, std::vector<int>& placesNum, Board board);



    };
}
#endif