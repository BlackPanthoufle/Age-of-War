#include "../header/Warrior.hpp"


Warrior::Warrior(int playerID): Unit(10, 10, 4, playerID), evolution(false) {}


Warrior::Warrior(int playerID, int life, bool evolved): Unit(life, 10, 4, playerID), evolution(evolved) {}


Warrior::~Warrior() {}


std::string Warrior::getVisual()
{
  if (!evolution) return "__W__ ";
  else return "__S__ ";
}


bool Warrior::getEvolution() const { return evolution; }

void Warrior::superWarriorEvolution() { evolution = true; }
