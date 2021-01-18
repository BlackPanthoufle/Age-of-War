#ifndef BASE
#define BASE

#include <vector>
#include "Unit.hpp"
#include "Archer.hpp"
#include "Trebuchet.hpp"
#include "Warrior.hpp"


class Base
{
  int life, gold;
  const int PLAYERID;

public:
  Base(int playerID);
  ~Base();
  int getGold() const;
  int getLife() const;
  int getPlayerID() const;
  void spawn(int choice, std::vector<Unit*> *ground, std::vector<bool> *occupied);
  void targeted(int damages);
  void goldPay(int pay);
};

#endif
