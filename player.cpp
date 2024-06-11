#include "player.hpp"
#include "catan.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <iostream>
#include <random>

namespace ariel {
    Player::Player(const std::string& name) {
        this->name = name;
        this->points = 0;
        resources["WOOD"] = 0;
        resources["BRICK"] = 0;
        resources["ORE"] = 0;
        resources["WHEAT"] = 0;
        resources["SHEEP"] = 0;
    }

    Player::Player(const Player& other) {
        this->name = other.name;
        this->points = other.points;
        
    }

    const std::string& Player::getName() const {
        return this->name;
    }

    void Player::printPoints() {
        std::cout << this->name << " has " << this->points << " points." << std::endl;
    }

    void Player::placeSettlement(const std::vector<int>& placesNum, Catan& catan) {
        if(!this->turn){
            throw std::invalid_argument("It's not your turn!");
        }
        if(!isValidPlaces(placesNum)) {
            throw std::invalid_argument("Invalid places or placesNum!");
        }

        if(catan.getVertex(placesNum[0])->hasSettlement() || catan.getVertex(placesNum[1])->hasSettlement()) {
            throw std::invalid_argument("One of the places already has a settlement!");
        }

        try{
            Edge* edge = catan.getEdge(placesNum[0], placesNum[1]);
        } catch (const std::exception &e) {
            throw std::invalid_argument("There is no road between the two places!");
        }

        catan.getVertex(placesNum[0])->buildSettlement(this->name);
        this->settlements.push_back(catan.getVertex(placesNum[0]));
        std::cout << this->name << " has placed a settlement on " << placesNum[0] << std::endl;
        this->points++;

    }

    void Player::placeRoad(const std::vector<int>& placesNum, Catan& catan) {
        if(!this->turn){
            throw std::invalid_argument("It's not your turn!");
        }

        if(!isValidPlaces(placesNum)) {
            throw std::invalid_argument("Invalid places or placesNum!");
        }

        try{
            Edge* edge = catan.getEdge(placesNum[0], placesNum[1]);
        } catch (const std::exception &e) {
            throw std::invalid_argument("There is no road between the two places!");
        }

        if(catan.getVertex(placesNum[0])->getOwner() == this->name){
            Edge* edge = catan.getEdge(placesNum[0], placesNum[1]);
            edge->buildRoad(this->name);
            this->roads.push_back(edge);
            std::cout << this->name << " has placed a road between " << placesNum[0] << " and " << placesNum[1] << std::endl;
        } else {
            throw std::invalid_argument("You can't build a road on a place that you don't own!");
        }
    }

    void Player::rollDice(Catan& catan) {
        // Seed the random number generator with a random device
        if(!this->turn){
            throw std::invalid_argument("It's not your turn!");
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 6);

        // Roll two dice
        int die1 = dis(gen);
        int die2 = dis(gen);

        int total = die1 + die2;

        // Output the result
        std::cout << this->name << " Rolled a " << die1 << " and a " << die2 << " for a total of " << total << std::endl;
        catan.collectResources(total);
        
    }   

    void Player::endTurn(Catan& catan) {
        if(!this->turn){
            throw std::invalid_argument("It's not your turn!");
        }
        if(catan.isFirstRound()) {
            if(this->settlements.size() < 2 || this->roads.size() < 2) {
            throw std::invalid_argument("You need to place two settlements before ending your turn!");
            }
        }
        

        this->turn = false;
        std::cout << this->name << " has ended their turn." << std::endl;
        catan.nextTurn();
        

    }




    bool Player::isValidPlaces(const std::vector<int>& placesNum) {
        if(placesNum.size() != 2) {
            return false;
        }
        if(placesNum[0] == placesNum[1]) {
            return false;
        }
        for(size_t i = 0; i < 2; i++) {
            
            // Check if the number is between 1 and 55 which is the valid range of vertex numbers
            if(placesNum[i] < 1 || placesNum[i] > 55) {
                return false;
            }
        }
        
        return true;
    }

    void Player::setTurn(bool turn) {
        this->turn = turn;
    }

    void Player::printPlayerStats() {
        std::cout << "------------------" << std::endl;
        std::cout << "Player: " << this->name << std::endl;
        std::cout << "Points: " << this->points << std::endl;
        std::cout << "Settlements: " << this->settlements.size() << std::endl;
        std::cout << "Roads: " << this->roads.size() << std::endl;
        for(auto &resource : this->resources) {
            std::cout << resource.first << ": " << resource.second << std::endl;
        }
        std::cout << "------------------" << std::endl;
    }

    int Player::getSettlementsSize() {
        return this->settlements.size();
    }

    int Player::getRoadsSize() {
        return this->roads.size();
    }

    std::vector<Vertex*> Player::getSettlements() {
        return this->settlements;
    }

    std::vector<Edge*> Player::getRoads() {
        return this->roads;
    }

    void Player::setResources(std::string resource, int amount) {
        resources[resource] += amount;
    }

    int Player::getPoints() {
        return this->points;
    }

    void Player::trade(Player& otherPlayer, std::string resourceA, std::string resourceB, int amountA, int amountB) {
        if(!this->turn){
            throw std::invalid_argument("It's not your turn!");
        }

        if(this->resources[resourceA] < amountA || otherPlayer.resources[resourceB] < amountB) {
            throw std::invalid_argument("You don't have enough resources to trade!");
        }

        this->resources[resourceA] -= amountA;
        this->resources[resourceB] += amountB;
        otherPlayer.resources[resourceA] += amountA;
        otherPlayer.resources[resourceB] -= amountB;

        std::cout << this->name << " has traded " << amountA << " " << resourceA << " for " << amountB << " " << resourceB << " with " << otherPlayer.getName() << std::endl;

    }

    void Player::buyDevelopmentCard(Catan& catan) {
        if(!this->turn){
            throw std::invalid_argument("It's not your turn!");
        }

        if(this->resources["ORE"] < 1 || this->resources["WHEAT"] < 1 || this->resources["SHEEP"] < 1) {
            throw std::invalid_argument("You don't have enough resources to buy a development card!");
        }

        this->resources["ORE"]--;
        this->resources["WHEAT"]--;
        this->resources["SHEEP"]--;

        this->hasDevelopmentCard = true;
        developmentCard* c = catan.pickDevelopmentCard();
        
        std::cout << this->name << " has picked " << std::endl;
        this->developmentCards.push_back(c);
        
        

        std::cout << this->name << " has bought a development card!" << std::endl;

    }
}