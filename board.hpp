#ifndef BOARD_HPP
#define BOARD_HPP

#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"


namespace ariel{

    class Board{
        private:
            std::vector<Tile> tiles;
            
        public:
            Board();
            void addTile(Tile t);
            
    };
}
#endif