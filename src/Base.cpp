#include "../header/Base.hpp"


Base::Base (int playerID) : life(100), gold(0), PLAYERID(playerID) {}


Base::~Base () {}


int Base::getGold() const { return gold; }


int Base::getLife() const { return life; }


int Base::getPlayerID() const { return PLAYERID; }


void Base::targeted (int damages) { life -= damages; }


void Base::goldPay(int pay) { gold += pay; }


void Base::buyUnit(int pay) { gold -= pay; }
