#ifndef EDGE_HPP
#define EDGE_HPP
#include "vertex.hpp"

namespace ariel{
    class Edge{
        
        private:
            Vertex* v;
            Vertex* u;
            bool road;
            std::string owner;
            
        public:
            Edge(Vertex* v, Vertex* u);
            int getV();
            int getU();
            void buildRoad(std::string playerName);
            bool hasRoad();
    };

}

#endif 