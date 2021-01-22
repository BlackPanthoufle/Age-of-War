#ifndef PLAYGROUND
#define PLAYGROUND

#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include "Unit.hpp"
#include "Warrior.hpp"
#include "Archer.hpp"
#include "Trebuchet.hpp"
#include "Base.hpp"

class Playground
{
  int turns;
  const int MAXTURNS;
  Base player1, player2;
  std::vector<Unit*> ground;
  bool AIgame, oneWins, twoWins;

public:
  Playground();
  ~Playground();
  int getTurns() const;
  int getPlayer1Life() const;
  int getPlayer2Life() const;
  bool win();
  void winningScreen();
  void pauseScreen();
  void saveScreen();
  void play();
  void display();
  void spawnUnit(int playerID, int choice);
  void firstAction(int index);
  bool secondAction(int index);
  void thirdAction(int index);
  void AIGame(bool load);
  void PVPGame(bool load);
};

#endif
