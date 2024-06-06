#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <iostream>

namespace ariel{
    class Vertex{
        
        private:
            int vertexNum;
            bool settlement;
            
        public:
            Vertex(int vertexNum);
            void buildSettlement();
            bool hasSettlement();
    };
}

#endif // VERTEX_HPP