#ifndef PLAYGROUND
#define PLAYGROUND

#include <vector>
#include "Unit.hpp"

class Playground
{
  int turns;
  const int MAX_TURNS;
  std::vector<Unit*> units;

public:
  Playground();
  ~Playground();
};

#endif
