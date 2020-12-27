#ifndef WARRIOR
#define WARRIOR

#include "Unit.hpp"

class Warrior : public Unit
{
public:
  Warrior(int playerID);
  ~Warrior();
  bool superWarrior();
  bool fstAction(std::vector<Unit*> ground);
  bool sndAction(std::vector<Unit*> ground);
  bool thdAction(std::vector<Unit*> ground);
};

#endif
