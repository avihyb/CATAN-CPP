#include "catan.hpp"
#include <vector>
#include <iostream>

namespace ariel {
    Catan::Catan(Player& p1, Player& p2, Player& p3) {
        // Initialize the players
        // This assumes that the Player class has a copy constructor
        this->players.push_back(p1);
        this->players.push_back(p2);
        this->players.push_back(p3);
    }

    void Catan::chooseStartingPlayer() {
        int startingPlayerIndex = rand() % this->players.size();
        std::cout << "Starting player: " << this->players[startingPlayerIndex].getName() << std::endl;
    }
}