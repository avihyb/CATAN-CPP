#include "developmentCard.hpp"
#include <iostream>
using namespace std;

class knightsCard : public developmentCard {
    knightsCard::knightsCard(){
        // empty constructor
    }
    
    void use() override {
        std::cout << "Knights Card used" << std::endl;
        
    }

    friend ostream &operator<<(ostream &os, const knightsCard &knightsCard)
    {
        os << "Knights Card";
        return os;
    }
};