#ifndef KNIGHTS_CARD_HPP
#define KNIGHTS_CARD_HPP

#include "developmentCard.hpp"
using namespace std;

class knightsCard : public developmentCard {
    knightsCard();
    void use();
    friend ostream &operator<<(ostream &os, const knightsCard &card);
};

#endif // KNIGHTS_CARD_HPP