#include "../header/Warrior.hpp"


Warrior::Warrior(int playerID): Unit(10, 10, 4, playerID, {1}) {}


Warrior::~Warrior() {}


bool Warrior::fstAction(std::vector<Unit*> ground)
{
  std::vector<int> rng = getRange();
  unsigned int index = 0;

  while (ground[index] != this && index < ground.size()) { index++; }

  switch (getPlayerID())
  {
    case 1:
      if (ground[index + 1] != NULL && ground[index + 1]->getPlayerID() == 2)
      {
        ground[index + 1]->targeted(getDamages());
        switchFAD();
        return true;
      }
      break;
    case 2:
      if (ground[index - 1] != NULL && ground[index + 1]->getPlayerID() == 1)
      {
        ground[index - 1]->targeted(getDamages());
        switchFAD();
        return true;
      }
      break;
    default: break;
  }

  return false;
}


bool Warrior::sndAction(std::vector<Unit*> ground)
{
  unsigned int index = 0;

  while (ground[index] != this && index < ground.size()) { index++; }

  switch (getPlayerID()) {
    case 1:
      if (ground[index + 1] == NULL)
      {
        Unit* temp;
        temp = ground[index + 1];
        ground[index + 1] = ground[index];
        ground[index] = temp;
        return true;
      }
      break;
    case 2:
      if (ground[index - 1] == NULL)
      {
        Unit* temp;
        temp = ground[index - 1];
        ground[index - 1] = ground[index];
        ground[index] = temp;
        return true;
      }
      break;
    default : break;
  }

  return false;
}


bool Warrior::thdAction(std::vector<Unit*> ground)
{
  if (getActionBool())
  {
    std::vector<int> rng = getRange();
    unsigned int index = 0;

    while (ground[index] != this && index < ground.size()) { index++; }

    switch (getPlayerID())
    {
      case 1:
      if (ground[index + 1] != NULL)
      {
        ground[index + 1]->targeted(getDamages());
        switchFAD();
        return true;
      }
      break;
      case 2:
      if (ground[index - 1] != NULL)
      {
        ground[index - 1]->targeted(getDamages());
        switchFAD();
        return true;
      }
      break;
      default: break;
    }
    return false;
  }
  else return false;
}
