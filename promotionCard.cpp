#include "developmentCard.hpp"
#include <iostream>
using namespace std;

class promotionCard : public developmentCard {
    promotionCard(){
        // empty constructor
    }
    
    void use() override {
        std::cout << "Promotion Card used" << std::endl;
        
    }

    friend ostream &operator<<(ostream &os, const promotionCard &promotionCard)
    {
        os << "Promotion Card";
        return os;
    }


};