#include "Base.hpp"

Base::Base (int playerID) : life(100), gold(0), PLAYERID(playerID) {}

Base::~Base () {}

int Base::getGold() const { return gold; }

int Base::getLife() const { return life; }

int Base::getPlayerID() const { return PLAYER_ID; }

void Base::spawn (Unit newSoldier) { army.push_back(newSoldier); }

void Base::targeted (int damages) { life -= damages; }

void Base::goldPay(int pay) { gold += pay; }
