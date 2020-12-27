#ifndef BASE
#define BASE

#include <vector>
#include "Unit.hpp"
#include "Archer.hpp"
#include "Trebuchet.hpp"
#include "Warrior.hpp"
#include "SuperWarrior.hpp"


class Base
{
  int life, gold;
  const int PLAYERID;
  std::vector<Unit> army;

public:
  Base(int playerID);
  ~Base();
  int getGold() const;
  int getLife() const;
  int getPlayerID() const;
  void spawn(int choice);
  void targeted(int damages);
  void goldPay(int pay);
};

#endif
