#ifndef ARCHER
#define ARCHER

#include "Unit.hpp"

class Archer : public Unit {
public:
  Archer(int playerID);
  ~Archer();
  bool fstAction(std::vector<Unit*> ground);
  bool sndAction(std::vector<Unit*> ground);
  bool thdAction(std::vector<Unit*> ground);
};

#endif
