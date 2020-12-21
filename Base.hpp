#ifndef BASE
#define BASE

#include <vector>
#include "Unit.hpp"

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
  void spawn(Unit newSoldier);
  void targeted(int damages);
  void goldPay(int pay);
};

#endif
