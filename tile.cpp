#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <map>
#include <string>


namespace ariel {

    Tile::Tile(std::string resource, int number, std::vector<Vertex> vertcies, std::vector<Edge> edges){
            resource = resource;
            number = number;
            vertcies = vertcies;
            edges = edges;
        }

    

}