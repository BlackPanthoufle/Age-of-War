#include "Trebuchet.hpp"


Trebuchet::Trebuchet(int playerID):Unit(12, 20, 6, playerID, {2, 3}) {}


Trebuchet::~Trebuchet() {}


bool Trebuchet::fstAction(std::vector<Unit*> ground)
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
        if ((ground[index + rng[i]] != NULL || ground[index + rng[i] + 1] != NULL) && (ground[index + rng[i]]->getPlayerID() == 2 || ground[index + rng[i] + 1]->getPlayerID() == 2))
        {
          ground[index + rng[i]]->targeted(getDamages());
          ground[index + rng[i] + 1]->targeted(getDamages());
          switchFAD();
          return true;
        }
        break;
      case 2:
        if ((ground[index - rng[i]] != NULL || ground[index - rng[i] - 1] != NULL) && (ground[index - rng[i]]->getPlayerID() == 1 || ground[index - rng[i] - 1]->getPlayerID() == 1))
        {
          ground[index - rng[i]]->targeted(getDamages());
          ground[index - rng[i] - 1]->targeted(getDamages());
          switchFAD();
          return true;
        }
        break;
      default: break;
    }
  }

  return false;
}


bool Trebuchet::thdAction(std::vector<Unit*> ground)
{
  if (getActionBool())
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
  else return false;
}
