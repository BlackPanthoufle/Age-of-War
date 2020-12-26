#include "Archer.hpp"

Archer::Archer(int playerID): Unit(8, 12, 3, playerID, {2,3,4}) {}

Archer::~Archer() {}

bool Archer::fstAction(std::vector<Unit*> ground) {return true;}
bool Archer::sndAction(std::vector<Unit*> ground) {return true;}
bool Archer::thdAction(std::vector<Unit*> ground) {return true;}
