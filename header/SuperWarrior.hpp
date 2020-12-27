#ifndef SUPERWARRIOR
#define SUPERWARRIOR

#include "Warrior.hpp"
#include <limits>

class SuperWarrior : public Warrior
{
public:
  SuperWarrior(int playerID);
  ~SuperWarrior();
  bool fstAction(std::vector<Unit*> ground);
  bool sndAction(std::vector<Unit*> ground);
  bool thdAction(std::vector<Unit*> ground);
};

#endif
