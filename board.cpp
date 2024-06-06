#include "board.hpp"
#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"

namespace ariel {
    Board::Board() {
        
    }

    void Board::addTile(Tile t) {
        this->tiles.push_back(t);
    }
    
}