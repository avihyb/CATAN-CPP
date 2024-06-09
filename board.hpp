#ifndef BOARD_HPP
#define BOARD_HPP

#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"


namespace ariel{

    class Board{
        private:
            std::vector<Tile> tiles;
            std::vector<Vertex> vertices;
            std::vector<Edge> edges;

            
        public:
            Board();
            void addTile(Tile t);
            Vertex* getVertex(size_t v);
            Edge* getEdge(int v, int u);
            std::vector<Tile> getTiles();
            
    };
}
#endif