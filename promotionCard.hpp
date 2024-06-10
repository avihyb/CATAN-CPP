#ifndef PROMOTION_CARD_HPP
#define PROMOTION_CARD_HPP

#include "developmentCard.hpp"
using namespace std;

class promotionCard : public developmentCard {
    promotionCard();
    void use();
    friend ostream &operator<<(ostream &os, const promotionCard &card);
};

#endif  