#ifndef TILE_HPP
#define TILE_HPP
#include <vector>
#include <map>
#include <string>

namespace ariel{

    class Tile{

        private:
            std::string resource;
            int number;
            std::vector<Vertex> vertcies;
            std::vector<Edge> edges;
            
        public:
            Tile(std::string resource, int number, std::vector<Vertex> vertcies, std::vector<Edge> edges);

        
            
    };
}
#endif