#include "../header/Archer.hpp"


Archer::Archer(int playerID): Unit(8, 12, 3, playerID, {2,3,4}) {}


Archer::~Archer() {}


bool Archer::fstAction(std::vector<Unit*> ground)
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
        if (ground[index + rng[i]] != NULL && ground[index + rng[i]]->getPlayerID() == 2)
        {
          ground[index + rng[i]]->targeted(getDamages());
          return true;
        }
        break;
      case 2:
        if (ground[index - rng[i]] != NULL && ground[index + rng[i]]->getPlayerID() == 1)
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


bool Archer::sndAction(std::vector<Unit*> ground)
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
