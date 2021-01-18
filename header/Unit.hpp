#ifndef UNIT
#define UNIT

#include <vector>
#include <iostream>

class Unit
{
  int life;
  const int price, damage;
  const int PLAYERID;
  bool fstActionDone;

public:
  Unit(int l, int p, int dmg, int playerID);
  ~Unit();
  virtual std::string getVisual();
  virtual bool getEvolution() const { return false; }
  virtual void superWarriorEvolution() {;}
  void targeted(int damages);
  int getPlayerID() const { return PLAYERID; }
  int getLife() const { return life; }
  int getDamages() const { return damage; }
  bool getActionBool() const { return fstActionDone; }
  void switchOnFAD();
  void switchOffFAD();
};

#endif
