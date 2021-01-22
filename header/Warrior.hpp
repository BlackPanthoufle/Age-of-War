#ifndef WARRIOR
#define WARRIOR

#include "Unit.hpp"

class Warrior : public Unit
{
  bool evolution;

public:
  Warrior(int playerID);
  Warrior(int playerID, int life, bool evolved);
  ~Warrior();
  bool superWarrior();
  std::string getVisual();
  void superWarriorEvolution();
  bool getEvolution() const;
};

#endif
