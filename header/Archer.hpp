#ifndef ARCHER
#define ARCHER


#include "Unit.hpp"


class Archer : public Unit
{
public:
  Archer(int playerID);
  Archer(int playerID, int life);
  ~Archer();
  std::string getVisual();
};


#endif
