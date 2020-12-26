#include "Warrior.hpp"

Warrior::Warrior(int playerID): Unit(10, 10, 4, playerID, {1}) {}


Warrior::~Warrior() {}


bool Warrior::fstAction(std::vector<Unit*> ground)
{
  std::vector<int> rng = getRange();
  unsigned int index = 0;

  while (ground[index] != this && index < ground.size())
  {
    index++;
  }

  for (unsigned int i = 0 ; i < rng.size() ; i++)
  {
    switch (getPlayerID())
    {
      case 1:
        if (ground[index + rng[i]] != NULL)
        {
          ground[index + rng[i]]->targeted(getDamages());
          return true;
        }
        break;
      case 2:
        if (ground[index - rng[i]] != NULL)
        {
          ground[index - rng[i]]->targeted(getDamages());
          return true;
        }
        break;
      default: break;
    }
  }

  return false;
}


bool Warrior::sndAction(std::vector<Unit*> ground)
{
  std::vector<int> rng = getRange();
  unsigned int index = 0;

  while (ground[index] != this && index < ground.size())
  {
    index++;
  }

  if (ground[index + 1] != NULL)
  {
    Unit* temp;
    temp = ground[index + 1];
    ground[index + 1] = ground[index];
    ground[index] = temp;
    return true;
  }

  return false;
}


bool Warrior::thdAction(std::vector<Unit*> ground) {return true;}
