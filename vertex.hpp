#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <iostream>

namespace ariel{
    class Vertex{
        
        private:
            int vertexNum;
            bool settlement;
            std::string owner;
            bool upgraded;
            
        public:
            Vertex(int vertexNum);
            int getVertexNum();
            void buildSettlement(const std::string& playerName);
            bool hasSettlement();
            std::string getOwner();
            void upgradeSettlement();
            bool isUpgraded();
    };
}

#endif // VERTEX_HPP