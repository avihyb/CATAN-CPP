#ifndef EDGE_HPP
#define EDGE_HPP
#include "vertex.hpp"

namespace ariel{
    class Edge{
        
        private:
            Vertex v;
            Vertex u;
            bool road;
            
        public:
            Edge(Vertex& v, Vertex& u);
            void buildRoad();
            bool hasRoad();
    };

}

#endif 