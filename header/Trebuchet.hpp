#ifndef TREBUCHET
#define TREBUCHET


#include "Unit.hpp"


class Trebuchet : public Unit
{
public:
  Trebuchet(int playerID);
  Trebuchet(int playerID, int life);
  ~Trebuchet();
  std::string getVisual();
};


#endif
