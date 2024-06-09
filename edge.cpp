#include "edge.hpp"
#include "vertex.hpp"

namespace ariel {
    Edge::Edge(Vertex* v, Vertex* u) : v(v), u(u) {
        this->road = false;
    }

    int Edge::getV() {
        return this->v->getVertexNum();
    }

    int Edge::getU() {
        return this->u->getVertexNum();
    }

    void Edge::buildRoad(std::string playerName) {
        this->road = true;
        this->owner = playerName;
    }

    bool Edge::hasRoad() {
        return this->road;
    }
}