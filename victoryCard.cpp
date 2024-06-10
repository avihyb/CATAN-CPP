#include "developmentCard.hpp"
#include <iostream>
using namespace std;

class victoryCard : public developmentCard
{
    victoryCard()
    {
        // empty constructor
    }

    void use() override
    {
       std::cout << "Victory Card used" << std::endl;
    }

    friend ostream &operator<<(ostream &os, const victoryCard &victoryCard)
    {
        os << "Victory Card";
        return os;
    }
    ~victoryCard() {}
};

// Add your member function definitions here, if any