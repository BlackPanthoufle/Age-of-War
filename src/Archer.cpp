#include "../header/Archer.hpp"


Archer::Archer(int playerID): Unit(8, 12, 3, playerID) {}


Archer::Archer(int playerID, int life):Unit(life, 20, 6, playerID) {}


Archer::~Archer() {}


std::string Archer::getVisual() { return "__A__ "; }
