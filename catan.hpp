#ifndef CATAN_HPP
#define CATAN_HPP

#include "player.hpp"

namespace ariel {
    class Catan{
        public:
            Catan(Player& p1, Player& p2, Player& p3);

            void chooseStartingPlayer();
            
    };
}
#endif