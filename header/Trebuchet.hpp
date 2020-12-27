#ifndef TREBUCHET
#define TREBUCHET

#include "Unit.hpp"

class Trebuchet : public Unit
{
public:
  Trebuchet(int playerID);
  ~Trebuchet();
  bool fstAction(std::vector<Unit*> ground);
  bool thdAction(std::vector<Unit*> ground);
};

#endif
