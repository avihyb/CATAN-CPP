#include "edge.hpp"
#include "vertex.hpp"

namespace ariel {
    Edge::Edge(Vertex& v, Vertex& u) : v(v), u(u) {
        this->road = false;
    }

    void Edge::buildRoad() {
        this->road = true;
    }

    bool Edge::hasRoad() {
        return this->road;
    }
}