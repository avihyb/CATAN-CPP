#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "board.hpp"
#include <string>
#include <vector>
#include <map>

namespace ariel{
    class Player{
        private:
            std::string name; // name of the player
            int points; // points of the player
            // data structures to hold the resources and points of the player
            
        public:
            Player(const std::string& name); // Constructor
            const std::string& getName() const; // Getter for name
            void printPoints(); // Prints player's points
            void Player::placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
            void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
            void rollDice(); // Simulates rolling a dice
            void endTurn(); // Ends the turn of the player
            void trade(Player& otherPlayer, std::string resourceA, std::string resourceB, int amountA, int amountB); // Trades resources with another player
            void buyDevelopmentCard(); // Buys a development card
    };
}
#endif