#ifndef WARRIOR
#define WARRIOR

#include "Unit.hpp"

class Warrior : public Unit
{
public:
  Warrior(int playerID);
  ~Warrior();
  bool superWarrior();
};

#endif
