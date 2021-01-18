#include "../header/Playground.hpp"


Playground::Playground(): turns(0), MAXTURNS(100), player1(1), player2(2), ground(12), oneWins(false), twoWins(false) {}


Playground::~Playground() {}


int Playground::getTurns() const { return turns; }


int Playground::getPlayer1Life() const { return player1.getLife(); }


int Playground::getPlayer2Life() const { return player2.getLife(); }


bool Playground::win()
{
  if (getPlayer1Life() == 0)
  {
    twoWins = true;
    return true;
  }
  else if (getPlayer2Life() == 0)
  {
    oneWins = true;
    return true;
  }
  else if (turns >= MAXTURNS)
  {
    if (getPlayer1Life() < getPlayer2Life())
    {
      twoWins = true;
      return true;
    }
    else //if(getPlayer1Life() >= getPlayer2Life())
    {
      oneWins = true;
      return true;
    }
    //else { return false; }
  }
  else { return false; }
}

void Playground::play(){

  std::cout << R"(
   █████╗  ██████╗ ███████╗     ██████╗ ███████╗    ██╗    ██╗ █████╗ ██████╗
  ██╔══██╗██╔════╝ ██╔════╝    ██╔═══██╗██╔════╝    ██║    ██║██╔══██╗██╔══██╗
  ███████║██║  ███╗█████╗      ██║   ██║█████╗      ██║ █╗ ██║███████║██████╔╝
  ██╔══██║██║   ██║██╔══╝      ██║   ██║██╔══╝      ██║███╗██║██╔══██║██╔══██╗
  ██║  ██║╚██████╔╝███████╗    ╚██████╔╝██║         ╚███╔███╔╝██║  ██║██║  ██║
  ╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝ ╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝
  )" << '\n';

  /*
  int gamemode;
  std::cout << "1) PVP\n2) PVC\n3) EXIT" << '\n';
  std::cin >> gamemode;

  switch (gamemode) {
    case 0:
      std::cout << "PVP mode on" << std::endl;
      break;
    case 1:
      std::cout << "PVC mode on" << std::endl;
      break;
    case 2:
      std::cout << "Bye !" << std::endl;
      break;
    default:
      std::cout << "Bye !" << std::endl;
      break;
  }
  */
  int choice;

  while(!win() && turns < MAXTURNS)
  {
    turns += 1;
    player1.goldPay(8);
    player2.goldPay(8);

    for(auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
        firstAction(i);
        if (secondAction(i)) thirdAction(i + 1);
        else thirdAction(i);
      }
    }

    for(auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
        firstAction(i);
        if (secondAction(i)) thirdAction(i - 1);
        else thirdAction(i);
      }
    }

    display();
    std::cout << "1) Warrior 2) Archer 3) Trebuchet" << '\n';
    std::cin >> choice;
    spawnUnit(1, choice);

    display();

    std::cout << "1) Warrior 2) Archer 3) Trebuchet" << '\n';
    std::cin >> choice;
    spawnUnit(2, choice);
    display();
  }
}


void Playground::display()
{
  std::cout << R"(
  _   |~  _                                                         _   |~  _
 [_]--'--[_]                                                       [_]--'--[_]
 |'|""`""|'|                                                       |'|""`""|'|
 | | /^\ | |                                                       | | /^\ | |
 |_|_|I|_|_|                                                       |_|_|I|_|_|)" << "\n\n\n\n    ";


  for(auto i = 0 ; i < 12 ; i++)
  {
    if (ground[i] != nullptr) std::cout << ground[i]->getVisual();
    else std::cout << "_____ ";
  }

  std::cout << "\n\n  ";

  for(auto i = 0 ; i < 12 ; i++)
  {
    if (ground[i] != nullptr) std::cout << std::setw(6) << ground[i]->getLife();
    else std::cout << "      ";
  }

  std::cout << "\n\n  Gold : " << player1.getGold() << "                                                         Gold : " << player2.getGold() << '\n';
}


void Playground::spawnUnit(int playerID, int choice)
{
  Warrior* warrior = new Warrior(playerID);
  Archer* archer = new Archer(playerID);
  Trebuchet* trebuchet = new Trebuchet(playerID);
  int spawnSpot;

  if (playerID == 1) spawnSpot = 0;
  else if (playerID == 2) spawnSpot = 11;

  switch (choice)
  {
    case 1:
    {
      ground[spawnSpot] = warrior;
      break;
    }
    case 2:
    {
      ground[spawnSpot] = archer;
      break;
    }
    case 3:
    {
      ground[spawnSpot] = trebuchet;
      break;
    }
  }
}


void Playground::firstAction (int index)
{
  int direction;

  if (ground[index]->getPlayerID() == 1) direction = 1;
  else if (ground[index]->getPlayerID() == 2) direction = -1;


  if (ground[index]->getVisual() == "__W__ ")
  {
    if (ground[index + direction] != nullptr && ground[index + direction]->getPlayerID() != ground[index]->getPlayerID())
    {
      ground[index + direction]->targeted(ground[index]->getDamages());
      ground[index]->switchOnFAD();
      if (ground[index + direction]->getLife() <= 0)
      {
        delete ground[index + direction];
        if (!ground[index]->getEvolution()) ground[index]->superWarriorEvolution();
      }
    }
  }
  else if (ground[index]->getVisual() == "__A__ ")
  {
    int i = 0, range = direction;

    while (!ground[index]->getActionBool() && i < 3)
    {
      if (ground[index + range] != nullptr && ground[index + range]->getPlayerID() != ground[index]->getPlayerID())
      {
        ground[index + range]->targeted(ground[index]->getDamages());
        if (ground[index + range]->getLife() <= 0) delete ground[index + range];
        ground[index]->switchOnFAD();
      }

      range = range + direction;
      i++;
    }
  }
  else if (ground[index]->getVisual() == "__T__ ")
  {
    int i = 0, range = 2 * direction;

    while (!ground[index]->getActionBool() && i < 3)
    {
      if (ground[index + range] != nullptr && ground[index + range]->getPlayerID() != ground[index]->getPlayerID())
      {
        ground[index + range]->targeted(ground[index]->getDamages());
        if (ground[index + range]->getLife() <= 0) delete ground[index + range];

        if (ground[index + range + direction] != nullptr && ground[index + range + direction]->getPlayerID() != ground[index]->getPlayerID())
        {
          ground[index + range + direction]->targeted(ground[index]->getDamages());
          if (ground[index + range + direction]->getLife() <= 0) delete ground[index + range + direction];
        }
        ground[index]->switchOnFAD();
      }

      range = range + direction;
      i++;
    }
  }
}


bool Playground::secondAction (int index)
{
  int direction, limit;

  if (ground[index]->getPlayerID() == 1)
  {
    direction = 1;
    limit = 11;
  }
  else if (ground[index]->getPlayerID() == 2)
  {
    direction = -1;
    limit = 0;
  }

  if (ground[index]->getVisual() == "__W__ " || ground[index]->getVisual() == "__A__ ")
  {
    if (direction > 0)
    {
      if (ground[index + direction] == nullptr && ((index + direction) < limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;

        return true;
      }
    }
    else
    {
      if (ground[index + direction] == nullptr && ((index + direction) > limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;

        return true;
      }
    }
  }
  return false;
}


void Playground::thirdAction (int index)
{
  if(ground[index]->getVisual() == "__W__ " || ground[index]->getVisual() == "__A__ ")
  {
    if (!ground[index]->getActionBool())
    {
      firstAction(index);
    }

    ground[index]->switchOffFAD();
  }

  else if (ground[index]->getVisual() == "__T__ ")
  {
    int direction, limit;

    if (ground[index]->getPlayerID() == 1)
    {
      direction = 1;
      limit = 11;
    }
    else if (ground[index]->getPlayerID() == 2)
    {
      direction = -1;
      limit = 0;
    }

    if (direction > 0)
    {
      if (ground[index + direction] == nullptr && ((index + direction) < limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;
        ground[index + 1]->switchOffFAD();
      }
    }
    else
    {
      if (ground[index + direction] == nullptr && ((index + direction) > limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;
        ground[index - 1]->switchOffFAD();
      }
    }
  }

}
