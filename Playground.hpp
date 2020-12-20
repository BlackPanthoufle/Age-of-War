#ifndef PLAYGROUND
#define PLAYGROUND

#include <vector>
#include <iostream>
#include "Unit.hpp"
#include "Base.hpp"

class Playground
{
  int turns;
  const int MAXTURNS;
  Base player1, player2;
  std::vector<Unit*> units;
  bool oneWins, twoWins;

public:
  Playground();
  ~Playground();
  int getTurns() const;
  int getPlayer1Life() const;
  int getPlayer2Life() const;
  bool win();
  void play();
  void display();
};

#endif
