#ifndef TILE_HPP
#define TILE_HPP
#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <map>
#include <string>

namespace ariel{

    class Tile{

        private:
            std::string resource;
            int number;
            std::vector<Vertex*> vertcies;
            std::vector<Edge*> edges;
            
        public:
            Tile(std::string resource, int number, std::vector<Vertex*> vertcies, std::vector<Edge*> edges);
            std::vector<Vertex*> getVertices();
            std::string getResource();
            int getTileNum();
            
        
            
    };
}
#endif