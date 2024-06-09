#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <map>
#include <string>


namespace ariel {

    Tile::Tile(std::string resource, int number, std::vector<Vertex*> vertcies, std::vector<Edge*> edges){
            this->resource = resource;
            this->number = number;
            this->vertcies = vertcies;
            this->edges = edges;
        }

    std::vector<Vertex*> Tile::getVertices(){
        return vertcies;
    }

    std::string Tile::getResource(){
        if(this->resource == "Mountain"){
            return "ORE";
        } 

        if(this->resource == "Hills"){
            return "BRICK";
        }

        if(this->resource == "Fields"){
            return "WHEAT";
        }

        if(this->resource == "Pasture"){
            return "SHEEP";
        }
        
        if(this->resource == "Forest"){
            return "WOOD";
        }
        return  "NONE";
    }
}