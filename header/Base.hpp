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
  void setGold(int newAmount);
  int getLife() const;
  void setLife(int newAmount);
  int getPlayerID() const;
  void targeted(int damages);
  void goldPay(int pay);
  void buyUnit(int price);
};

#endif
