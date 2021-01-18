#ifndef TREBUCHET
#define TREBUCHET

#include "Unit.hpp"

class Trebuchet : public Unit
{
public:
  Trebuchet(int playerID);
  ~Trebuchet();
  std::string getVisual();
};

#endif
