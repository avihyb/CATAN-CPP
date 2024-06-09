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

    Vertex* Board::getVertex(size_t v) {
        return &this->vertices[v];
    }

    Edge* Board::getEdge(int v, int u) {
        for(auto &edge : this->edges) {
            if(edge.getV() == v && edge.getU() == u) {
                return &edge;
            }
        }
        throw std::invalid_argument("Edge not found between the specified vertices.");
    }

    std::vector<Tile> Board::getTiles() {
        return this->tiles;
    }
}