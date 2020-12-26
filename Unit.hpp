#ifndef UNIT
#define UNIT

#include <vector>

class Unit
{
  int life, price, damage;
  const int PLAYERID;
  std::vector<int> range;
  bool fstActionDone;

public:
  Unit(int l, int p, int dmg, int playerID, std::vector<int> rng);
  ~Unit();
  virtual bool fstAction(std::vector<Unit*> ground)/* = 0*/;
  virtual bool sndAction(std::vector<Unit*> ground);
  virtual bool thdAction(std::vector<Unit*> ground)/* = 0*/;
  void targeted(int damages);
  std::vector<int> getRange() const { return range; }
  int getPlayerID() const { return PLAYERID; }
  int getDamages() const { return damage; }
};

#endif
