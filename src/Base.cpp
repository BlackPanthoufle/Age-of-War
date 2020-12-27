#include "../header/Base.hpp"

Base::Base (int playerID) : life(100), gold(0), PLAYERID(playerID) {}

Base::~Base () {}

int Base::getGold() const { return gold; }

int Base::getLife() const { return life; }

int Base::getPlayerID() const { return PLAYERID; }

void Base::spawn (int choice)
{
  switch (choice) {
    case 1:
      army.push_back(Warrior(PLAYERID));
      break;
    case 2:
      army.push_back(Archer(PLAYERID));
      break;
    case 3:
      army.push_back(Trebuchet(PLAYERID));
      break;
    default: ;
  }
}

void Base::targeted (int damages) { life -= damages; }

void Base::goldPay(int pay) { gold += pay; }
