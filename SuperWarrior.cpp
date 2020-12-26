#include "SuperWarrior.hpp"

SuperWarrior::SuperWarrior(int playerID): Warrior(playerID) {}

SuperWarrior::~SuperWarrior() {}

bool SuperWarrior::fstAction(std::vector<Unit*> ground) {return true;}
bool SuperWarrior::sndAction(std::vector<Unit*> ground) {return true;}
bool SuperWarrior::thdAction(std::vector<Unit*> ground) {return true;}
