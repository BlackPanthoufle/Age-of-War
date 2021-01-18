#ifndef WARRIOR
#define WARRIOR

#include "Unit.hpp"

class Warrior : public Unit
{
  bool evolution;
public:
  Warrior(int playerID);
  ~Warrior();
  bool superWarrior();
  std::string getVisual();
  void superWarriorEvolution();
  bool getEvolution() const;
};

#endif
