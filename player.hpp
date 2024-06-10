#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "board.hpp"
#include "catan.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "developmentCard.hpp"

#include <string>
#include <vector>
#include <map>

namespace ariel{
    class Catan; // Forward declaration of the Catan class
    
    class Player{
        private:
            std::string name; // name of the player
            int points; // points of the player
            std::vector<Vertex*> settlements; // vector of the player's settlements
            std::vector<Edge*> roads; // vector of the player's roads
            bool turn; // true if it's the player's turn, false otherwise
            std::map<std::string, int> resources; // map of the player's resources
            bool hasDevelopmentCard; // true if the player has a development card, false otherwise
            std::vector<developmentCard*> developmentCards; // vector of the player's development cards
            
            
        public:
            Player(const std::string& name); // Constructor
            Player(const Player& other); // Copy constructor
            const std::string& getName() const; // Getter for name
            void printPoints(); // Prints player's points
            void placeSettlement(const std::vector<int>& placesNum, Catan& catan);
            void placeRoad(const std::vector<int>& placesNum, Catan& catan);
            void rollDice(Catan& catan); // Simulates rolling a dice
            void endTurn(Catan& catan); // Ends the turn of the player
            void buyDevelopmentCard(Catan& catan); // Buys a development card
            bool isValidPlaces(const std::vector<int>& placesNum);
            void setTurn(bool turn);
            void printPlayerStats();
            int getSettlementsSize();
            int getRoadsSize();
            std::vector<Vertex*> getSettlements();
            std::vector<Edge*> getRoads();
            void setResources(std::string resource, int amount);
            int getPoints();
            void trade(Player& otherPlayer, std::string resourceA, std::string resourceB, int amountA, int amountB);
            void buyKnightsCard();
            void buyPromotionCard();
            void buyVictoryCard();
            void upgradeSettlement(int vertexNum, Catan& catan);
    };
}
#endif