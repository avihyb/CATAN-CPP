#include "catan.hpp"
#include "player.hpp"
#include <vector>
#include <iostream>
#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"
#include "developmentCard.hpp"
#include "knightsCard.hpp"
#include "victoryCard.hpp"
#include "promotionCard.hpp"


namespace ariel {
    Catan::Catan(Player* p1, Player* p2, Player* p3) {
        // Initialize the players
        // This assumes that the Player class has a copy constructor
        this->players.push_back(p1);
        this->players.push_back(p2);
        this->players.push_back(p3);

        
        
        for (int i = 1; i <= 55; ++i) {
            vertices.emplace_back(i);
        }

        this->edges = {
            Edge(&vertices[0], &vertices[1]),   // e1
            Edge(&vertices[1], &vertices[2]),   // e2
            Edge(&vertices[2], &vertices[3]),   // e3
            Edge(&vertices[3], &vertices[4]),   // e4
            Edge(&vertices[4], &vertices[5]),   // e5
            Edge(&vertices[5], &vertices[6]),   // e6
            Edge(&vertices[6], &vertices[7]),   // e7
            Edge(&vertices[7], &vertices[8]),   // e8
            Edge(&vertices[8], &vertices[9]),   // e9
            Edge(&vertices[9], &vertices[10]),  // e10
            Edge(&vertices[9], &vertices[4]),   // e10_5
            Edge(&vertices[10], &vertices[11]), // e11
            Edge(&vertices[11], &vertices[12]), // e12
            Edge(&vertices[11], &vertices[2]),  // e12_3
            Edge(&vertices[12], &vertices[13]), // e13
            Edge(&vertices[13], &vertices[0]),  // e14_1
            Edge(&vertices[13], &vertices[14]), // e14
            Edge(&vertices[14], &vertices[15]), // e15
            Edge(&vertices[15], &vertices[16]), // e16
            Edge(&vertices[16], &vertices[17]), // e17
            Edge(&vertices[17], &vertices[12]), // e18_13
            Edge(&vertices[17], &vertices[18]), // e18
            Edge(&vertices[18], &vertices[19]), // e19
            Edge(&vertices[19], &vertices[10]), // e20_11
            Edge(&vertices[19], &vertices[20]), // e20
            Edge(&vertices[20], &vertices[21]), // e21
            Edge(&vertices[21], &vertices[8]),  // e22_9
            Edge(&vertices[21], &vertices[22]), // e22
            Edge(&vertices[22], &vertices[23]), // e23
            Edge(&vertices[23], &vertices[24]), // e24
            Edge(&vertices[24], &vertices[7]),  // e25_8
            Edge(&vertices[36], &vertices[37]), // e37
            Edge(&vertices[35], &vertices[36]), // e36
            Edge(&vertices[34], &vertices[35]), // e35
            Edge(&vertices[16], &vertices[34]), // e17_35
            Edge(&vertices[33], &vertices[34]), // e34
            Edge(&vertices[32], &vertices[33]), // e33
            Edge(&vertices[18], &vertices[32]), // e19_33
            Edge(&vertices[31], &vertices[32]), // e32
            Edge(&vertices[30], &vertices[31]), // e31
            Edge(&vertices[20], &vertices[30]), // e21_31
            Edge(&vertices[29], &vertices[30]), // e30
            Edge(&vertices[22], &vertices[28]), // e23_29
            Edge(&vertices[28], &vertices[29]), // e29
            Edge(&vertices[27], &vertices[28]), // e28
            Edge(&vertices[26], &vertices[27]), // e27
            Edge(&vertices[23], &vertices[25]), // e24_26
            Edge(&vertices[25], &vertices[26]), // e26
            Edge(&vertices[35], &vertices[38]), // e36_39
            Edge(&vertices[33], &vertices[40]), // e34_41
            Edge(&vertices[39], &vertices[40]), // e40
            Edge(&vertices[38], &vertices[39]), // e39
            Edge(&vertices[40], &vertices[41]), // e41
            Edge(&vertices[41], &vertices[42]), // e42
            Edge(&vertices[31], &vertices[42]), // e32_43
            Edge(&vertices[42], &vertices[43]), // e43
            Edge(&vertices[43], &vertices[44]), // e44
            Edge(&vertices[29], &vertices[44]), // e30_45
            Edge(&vertices[44], &vertices[45]), // e45
            Edge(&vertices[45], &vertices[46]), // e46
            Edge(&vertices[46], &vertices[47]), // e47
            Edge(&vertices[39], &vertices[54]), // e40_55
            Edge(&vertices[53], &vertices[54]), // e54
            Edge(&vertices[52], &vertices[53]), // e53
            Edge(&vertices[41], &vertices[52]), // e42_53
            Edge(&vertices[51], &vertices[52]), // e52
            Edge(&vertices[50], &vertices[51]), // e51
            Edge(&vertices[43], &vertices[50]), // e44_51
            Edge(&vertices[48], &vertices[49]), // e49
            Edge(&vertices[45], &vertices[48]), // e46_49
            Edge(&vertices[49], &vertices[50])  // e50
        };

        /*
        Board layout:
        
              <t1> <t2> <t3>
            <t4> <t5> <t6> <t7>
        <t8> <t9> <t10> <t11> <t12>
           <t13> <t14> <t15> <t16>
             <t17> <t18> <t19>

        */

        Tile t1("Mountain", 10, {&vertices[0], &vertices[1], &vertices[2], &vertices[11], &vertices[12], &vertices[13]}, {&edges[0], &edges[1], &edges[2], &edges[3], &edges[4], &edges[5]});
        Tile t2("Pasture", 2, {&vertices[2], &vertices[3], &vertices[4], &vertices[9], &vertices[10], &vertices[11]}, {&edges[2], &edges[3], &edges[4], &edges[9], &edges[10], &edges[11]});
        Tile t3("Forest", 9, {&vertices[4], &vertices[5], &vertices[6], &vertices[7], &vertices[8], &vertices[9]}, {&edges[4], &edges[5], &edges[6], &edges[7], &edges[8], &edges[9]});
        Tile t4("Fields", 12, {&vertices[12], &vertices[13], &vertices[14], &vertices[15], &vertices[16], &vertices[17]}, {&edges[12], &edges[13], &edges[14], &edges[15], &edges[16], &edges[17], &edges[18]});
        Tile t5("Hills", 6, {&vertices[17], &vertices[18], &vertices[19], &vertices[12], &vertices[11], &vertices[10]}, {&edges[18], &edges[19], &edges[20], &edges[11], &edges[21]});
        Tile t6("Pasture", 4, {&vertices[19], &vertices[20], &vertices[21], &vertices[8], &vertices[9], &vertices[10]}, {&edges[21], &edges[22], &edges[23], &edges[8], &edges[10], &edges[24]});
        Tile t7("Hills", 10, {&vertices[21], &vertices[22], &vertices[23], &vertices[24], &vertices[8], &vertices[7]}, {&edges[23], &edges[25], &edges[26], &edges[27], &edges[7]});
        Tile t8("Fields", 9, {&vertices[37], &vertices[15], &vertices[16], &vertices[34], &vertices[35], &vertices[36]}, {&edges[15], &edges[35], &edges[34], &edges[33], &edges[32]});
        Tile t9("Forest", 9, {&vertices[34], &vertices[33], &vertices[32], &vertices[18], &vertices[16], &vertices[17]}, {&edges[32], &edges[31], &edges[30], &edges[19], &edges[18], &edges[17]});
        Tile t10("Desert", 0, {&vertices[32], &vertices[31], &vertices[30], &vertices[20], &vertices[19], &vertices[18]}, {&edges[30], &edges[29], &edges[28], &edges[21], &edges[19]});
        Tile t11("Forest", 3, {&vertices[30], &vertices[29], &vertices[28], &vertices[22], &vertices[21], &vertices[20]}, {&edges[29], &edges[28], &edges[27], &edges[26], &edges[25], &edges[24]});
        Tile t12("Mountain", 8, {&vertices[28], &vertices[27], &vertices[26], &vertices[25], &vertices[23], &vertices[22]}, {&edges[27], &edges[26], &edges[25], &edges[24], &edges[23]});
        Tile t13("Forest", 8, {&vertices[38], &vertices[35], &vertices[34], &vertices[33], &vertices[40], &vertices[39]}, {&edges[34], &edges[33], &edges[32], &edges[31], &edges[40], &edges[39]});
        Tile t14("Mountain", 3, {&vertices[40], &vertices[41], &vertices[42], &vertices[31], &vertices[32], &vertices[33]}, {&edges[31], &edges[41], &edges[42], &edges[30]});
        Tile t15("Fields", 4, {&vertices[42], &vertices[43], &vertices[44], &vertices[29], &vertices[30], &vertices[31]}, {&edges[42], &edges[43], &edges[44], &edges[29]});
        Tile t16("Pasture", 5, {&vertices[44], &vertices[45], &vertices[46], &vertices[47], &vertices[27], &vertices[29]}, {&edges[29], &edges[44], &edges[45], &edges[46]});
        Tile t17("Hills", 5, {&vertices[54], &vertices[53], &vertices[52], &vertices[41], &vertices[40], &vertices[39]}, {&edges[39], &edges[54], &edges[53], &edges[52], &edges[41], &edges[40]});
        Tile t18("Fields", 6, {&vertices[52], &vertices[51], &vertices[50], &vertices[41], &vertices[42], &vertices[43]}, {&edges[52], &edges[51], &edges[50], &edges[44], &edges[42], &edges[43]});
        Tile t19("Pasture", 11, {&vertices[50], &vertices[49], &vertices[48], &vertices[45], &vertices[44], &vertices[43]}, {&edges[43], &edges[48], &edges[47], &edges[46]});

        this->board.addTile(t1);
        this->board.addTile(t2);
        this->board.addTile(t3);
        this->board.addTile(t4);
        this->board.addTile(t5);
        this->board.addTile(t6);
        this->board.addTile(t7);
        this->board.addTile(t8);
        this->board.addTile(t9);
        this->board.addTile(t10);
        this->board.addTile(t11);
        this->board.addTile(t12);
        this->board.addTile(t13);
        this->board.addTile(t14);
        this->board.addTile(t15);
        this->board.addTile(t16);
        this->board.addTile(t17);
        this->board.addTile(t18);
        this->board.addTile(t19);
        
        knightsCard* knightCard;
        
        promotionCard* promotionCard1;
        promotionCard* promotionCard2;
        promotionCard* promotionCard3;

        victoryCard* victoryCard1;
        victoryCard* victoryCard2;
        victoryCard* victoryCard3;
        victoryCard* victoryCard4;
        victoryCard* victoryCard5;

        developmentCards.push_back(knightCard);
        developmentCards.push_back(promotionCard1);
        developmentCards.push_back(promotionCard2);
        developmentCards.push_back(promotionCard3);
        developmentCards.push_back(victoryCard1);
        developmentCards.push_back(victoryCard2);
        developmentCards.push_back(victoryCard3);
        developmentCards.push_back(victoryCard4);
        developmentCards.push_back(victoryCard5);

    }

    Board Catan::getBoard() {
        return this->board;
    }

    void Catan::chooseStartingPlayer() {
        // first player starts:
        currentPlayer = 0;
        players[0]->setTurn(true);
        std::cout << "Starting player: " << players[0]->getName() << std::endl;
    }

    Vertex* Catan::getVertex(int v) {
        return &vertices[v];
    }

    Edge* Catan::getEdge(int v, int u) {
        for(auto &edge : this->edges) {
            if(edge.getV() == v && edge.getU() == u) {
                return &edge;
            }
        }
        throw std::invalid_argument("Edge not found between the specified vertices.");
    }

    void Catan::nextTurn() {
        currentPlayer = (currentPlayer + 1) % 3;
        players[currentPlayer]->setTurn(true);
        std::cout << "Next turn: " << players[currentPlayer]->getName() << std::endl;
        if(finishedInitialization() && firstRound) {
            std::cout << "Initialization round is done. Starting the game!" << std::endl;
            firstRound = false;

            std::cout << "Giving out resources..." << std::endl;
            
            getResources(this->players[0]);
            getResources(this->players[1]);
            getResources(this->players[2]);
        } 

        

    }

    bool Catan::finishedInitialization() {
        for(auto &player : players) {
            if(player->getSettlementsSize() < 2) {
                return false;
            }
        }
        
        return true;
    }

    void Catan::currentTurn(){
        std::cout << "Current turn: " << players[currentPlayer]->getName() << std::endl;
    }

    bool Catan::isFirstRound() {
        return firstRound;
    }

    std::vector<Tile> Catan::getAdjTiles(Vertex* v) {
       
        std::vector<Tile> adjTiles;   
        for(auto tile : this->board.getTiles()) {
            
            for(auto vertex : tile.getVertices()) {
                
                if(vertex->getVertexNum() == v->getVertexNum()) {
                    adjTiles.push_back(tile);
                }
                
            }
        }
        return adjTiles;
    }

    void Catan::getResources(Player* p){
        
        std::vector<Tile> adjTiles = getAdjTiles(p->getSettlements()[1]);
        
        for(auto tile : adjTiles) {
            p->setResources(tile.getResource(), 1);
            std::cout << "Player " << p->getName() << " got 1 " << tile.getResource() << std::endl;
        }
    }

    void Catan::collectResources(int diceResult) {
        for(auto &player : players) {
            if(player->getSettlementsSize() > 0) {
                for(size_t i = 0; i < player->getSettlementsSize(); i++){
                    std::vector<Tile> adjTiles = getAdjTiles(player->getSettlements()[i]);
                    for(auto tile : adjTiles) {
                        if(tile.getTileNum() == diceResult) {
                            if(player->getSettlements()[i]->isUpgraded()){
                                player->setResources(tile.getResource(), 2);
                                std::cout << "Player " << player->getName() << " got 2 " << tile.getResource() << std::endl;
                            } else {
                            player->setResources(tile.getResource(), 1);
                            std::cout << "Player " << player->getName() << " got 1 " << tile.getResource() << std::endl; 
                            }
                        }
                    }
                }
               
            }
        }
    }

    developmentCard* Catan::pickDevelopmentCard(){
        int random = rand() % developmentCards.size();
        developmentCard* card = developmentCards[random];
        std::cout << "Player " << players[currentPlayer]->getName() << " picked " << card << std::endl;
        developmentCards.erase(developmentCards.begin() + random);
        return card;
    }

    void Catan::printWinner() {
        int maxPoints = 10;
        std::string winner = "";
        for(auto &player : players) {
            if(player->getPoints() == maxPoints) {
                winner = player->getName();
            }
        }
        std::cout << "The winner is: " << winner << " with " << maxPoints << " points!" << std::endl;
    }
}
