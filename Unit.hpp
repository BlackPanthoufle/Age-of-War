#ifndef UNIT
#define UNIT

#include <vector>

class Unit
{
  int life, price, damage;
  const int PLAYER_ID;
  std::vector<bool> range;

public:
  Unit(int playerID);
  ~Unit();
  void forward();
  void attack(Unit target);
  void targeted(int damages);
};

#endif
