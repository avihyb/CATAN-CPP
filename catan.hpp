#ifndef CATAN_HPP
#define CATAN_HPP

#include "player.hpp"
#include "board.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"


namespace ariel {
    class Player;
    class Catan{
        private:
            Board board;
            std::vector<Player*> players;
            std::vector<Edge> edges;
            std::vector<Vertex> vertices;
            int currentPlayer;
            bool firstRound;

        public:
            Catan(Player* p1, Player* p2, Player* p3);
            Board getBoard();
            std::vector<Vertex> getVertices();
            std::vector<Edge> getEdges();
            void chooseStartingPlayer();
           // void printWinner();
            Vertex* getVertex(int v);
            Edge* getEdge(int v, int u);
            void nextTurn();
            void currentTurn();
            bool finishedInitialization();
            bool isFirstRound();
            std::vector<Tile> getAdjTiles(Vertex* v);
            void getResources(Player* p);
            
    };
}
#endif