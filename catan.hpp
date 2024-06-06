#ifndef CATAN_HPP
#define CATAN_HPP

#include "player.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"

namespace ariel {
    class Catan{
        private:
            Board board;
            std::vector<Player> players;

        public:
            Catan(Player& p1, Player& p2, Player& p3);
            Board getBoard();
            void chooseStartingPlayer();
            void printWinner();
            
    };
}
#endif