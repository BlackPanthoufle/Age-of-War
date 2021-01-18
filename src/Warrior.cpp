#include "../header/Warrior.hpp"


Warrior::Warrior(int playerID): Unit(10, 10, 4, playerID), evolution(false) {}


Warrior::~Warrior() {}


std::string Warrior::getVisual() { return "__W__ "; }


bool Warrior::getEvolution() const { return evolution; }

void Warrior::superWarriorEvolution() { evolution = true; }
