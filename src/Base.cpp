#include "../header/Base.hpp"


Base::Base (int playerID) : life(100), gold(0), PLAYERID(playerID) {}


Base::~Base () {}


int Base::getGold() const { return gold; }


void Base::setGold(int newAmount) { gold = newAmount; }


int Base::getLife() const { return life; }


void Base::setLife(int newAmount) { life = newAmount; } 


int Base::getPlayerID() const { return PLAYERID; }


void Base::targeted (int damages) { life -= damages; }


void Base::goldPay(int pay) { gold += pay; }


void Base::buyUnit(int pay) { gold -= pay; }
