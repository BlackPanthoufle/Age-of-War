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
  virtual ~Unit();
  virtual std::string getVisual();
  virtual bool getEvolution() const;
  virtual void superWarriorEvolution();
  void targeted(int damages);
  int getPlayerID() const;
  int getLife() const;
  int getPrice() const;
  int getDamages() const;
  bool getActionBool() const;
  void switchOnFAD();
  void switchOffFAD();
  void setLife(int lifeLevel);
};


#endif
