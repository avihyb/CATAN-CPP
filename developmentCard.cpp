#include "developmentCard.hpp"
#include <iostream>
using namespace std;

void developmentCard::use() {
    // Implementation for the use() function goes here
    // This is an abstract function, so it should not have any implementation here
    // Derived classes will provide their own implementation
}

ostream &operator<<(ostream &os, const developmentCard &card) {
    // Implementation for the << operator goes here
    // This is an abstract function, so it should not have any implementation here
    // Derived classes will provide their own implementation
    return os;
}

