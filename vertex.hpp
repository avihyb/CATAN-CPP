#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <iostream>

namespace ariel{
    class Vertex{
        
        private:
            int vertexNum;
            bool settlement;
            std::string owner;
            
        public:
            Vertex(int vertexNum);
            int getVertexNum();
            void buildSettlement(const std::string& playerName);
            bool hasSettlement();
            std::string getOwner();
    };
}

#endif // VERTEX_HPP