#ifndef VICTORY_CARD_HPP
#define VICTORY_CARD_HPP

#include "developmentCard.hpp"
using namespace std;

class victoryCard : public developmentCard {
    victoryCard();
    void use();
    friend ostream &operator<<(ostream &os, const victoryCard &card);
};

#endif // KNIGHTS_CARD_HPP