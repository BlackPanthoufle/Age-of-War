#include "Unit.hpp"

Unit::Unit(int playerID): PLAYERID(playerID) {}

Unit::~Unit() {}

void Unit::attack(Unit target) { target.targeted(damage); }

void Unit::targeted(int damages) { life -= damages; }
