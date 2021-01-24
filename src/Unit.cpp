#include "../header/Unit.hpp"


Unit::Unit(int l, int p, int dmg, int playerID) : life(l), price(p), damage(dmg), PLAYERID(playerID), fstActionDone(false) {}


Unit::~Unit() {}


void Unit::targeted(int damages) { life -= damages; }


std::string Unit::getVisual() { return "_____ "; }


bool Unit::getEvolution() const { return false; }


void Unit::superWarriorEvolution() {}


int Unit::getPlayerID() const { return PLAYERID; }


int Unit::getLife() const { return life; }


int Unit::getPrice() const { return price; }


int Unit::getDamages() const { return damage; }


bool Unit::getActionBool() const { return fstActionDone; }


void Unit::switchOnFAD() { fstActionDone = true; }


void Unit::switchOffFAD() { fstActionDone = false; }


void Unit::setLife(int lifeLevel) { life = lifeLevel; }
