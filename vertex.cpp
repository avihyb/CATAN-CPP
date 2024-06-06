#include "vertex.hpp"

namespace ariel {

    Vertex::Vertex(int vertexNum) {
        this->vertexNum = vertexNum;
        this->settlement = false;
    }

    void Vertex::buildSettlement() {
        this->settlement = true;
    }

    bool Vertex::hasSettlement() {
        return this->settlement;
    }
}