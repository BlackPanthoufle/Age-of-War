#include "../header/Unit.hpp"

Unit::Unit(int l, int p, int dmg, int playerID) : life(l), price(p), damage(dmg), PLAYERID(playerID), fstActionDone(false) {}

Unit::~Unit() {}


void Unit::targeted(int damages) { life -= damages; }


std::string Unit::getVisual() { return "_____ "; }


void Unit::switchOnFAD() { fstActionDone = true; }


void Unit::switchOffFAD() { fstActionDone = false; }
