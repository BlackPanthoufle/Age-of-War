#include "Unit.hpp"

Unit::Unit(int l, int p, int dmg, int playerID, std::vector<int> rng):life(l), price(p), damage(dmg), PLAYERID(playerID), range(rng) {}

Unit::~Unit() {}

bool Unit::fstAction(std::vector<Unit*> ground) {return true;}

bool Unit::sndAction(std::vector<Unit*> ground) {return true;}

bool Unit::thdAction(std::vector<Unit*> ground) {return true;}

void Unit::targeted(int damages) { life -= damages; }
