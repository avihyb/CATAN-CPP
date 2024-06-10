#include "vertex.hpp"

namespace ariel {

    Vertex::Vertex(int vertexNum) {
        this->vertexNum = vertexNum;
        this->settlement = false;
        this->owner = "";
    }

    int Vertex::getVertexNum() {
        return this->vertexNum;
    }

    void Vertex::buildSettlement(const std::string& playerName) {
        this->settlement = true;
        this->owner = playerName;
    }

    bool Vertex::hasSettlement() {
        return this->settlement;
    }

    std::string Vertex::getOwner() {
        return this->owner;
    }

    void Vertex::upgradeSettlement() {
        this->upgraded = true;
    }

    bool Vertex::isUpgraded() {
        return this->upgraded;
    }
}