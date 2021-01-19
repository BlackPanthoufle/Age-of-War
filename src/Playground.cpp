#include "../header/Playground.hpp"


Playground::Playground(): turns(0), MAXTURNS(100), player1(1), player2(2), ground(12), oneWins(false), twoWins(false) {}


Playground::~Playground() {}


int Playground::getTurns() const { return turns; }


int Playground::getPlayer1Life() const { return player1.getLife(); }


int Playground::getPlayer2Life() const { return player2.getLife(); }


bool Playground::win()
{
  if (getPlayer1Life() <= 0)
  {
    twoWins = true;
    return true;
  }
  else if (getPlayer2Life() <= 0)
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
    else
    {
      oneWins = true;
      return true;
    }
  }
  else { return false; }
}

void Playground::play(){
  system("clear");
  std::cout << R"(
   █████╗  ██████╗ ███████╗     ██████╗ ███████╗    ██╗    ██╗ █████╗ ██████╗
  ██╔══██╗██╔════╝ ██╔════╝    ██╔═══██╗██╔════╝    ██║    ██║██╔══██╗██╔══██╗
  ███████║██║  ███╗█████╗      ██║   ██║█████╗      ██║ █╗ ██║███████║██████╔╝
  ██╔══██║██║   ██║██╔══╝      ██║   ██║██╔══╝      ██║███╗██║██╔══██║██╔══██╗
  ██║  ██║╚██████╔╝███████╗    ╚██████╔╝██║         ╚███╔███╔╝██║  ██║██║  ██║
  ╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝ ╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝
  )" << '\n';

  int gamemode;
  std::cout << "1) PvP\n2) PvAI\n3) EXIT" << '\n';
  std::cin >> gamemode;

  switch (gamemode)
  {
    case 1:
    {
      std::cout << "PVP mode on" << std::endl;
      PVPGame();
      break;
    }
    case 2:
    {
      std::cout << "PVAI mode on" << std::endl;
      AIGame();
      break;
    }
    case 3:
    {
      std::cout << "Bye !" << std::endl;
      break;
    }
    default:
    {
      std::cout << "Bye !" << std::endl;
      break;
    }
  }
}


void Playground::display()
{
  //system("clear");
  std::cout << "ROUND " << turns << '\n';
  std::cout << "\n\n     " << player1.getLife() << "                                                                " << player2.getLife() << '\n';
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
  if (choice != 4)
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
}


void Playground::firstAction (int index)
{
  int direction;

  if (ground[index]->getPlayerID() == 1) direction = 1;
  else if (ground[index]->getPlayerID() == 2) direction = -1;


  if ((ground[index]->getVisual() == "__W__ ") || (ground[index]->getVisual() == "__S__ "))
  {
    if (ground[index + direction] != nullptr && ground[index + direction]->getPlayerID() != ground[index]->getPlayerID())
    {
      ground[index + direction]->targeted(ground[index]->getDamages());
      ground[index]->switchOnFAD();
      if (ground[index + direction]->getLife() <= 0)
      {
        delete ground[index + direction];
        ground[index + direction] = nullptr;
        if (!ground[index]->getEvolution()) ground[index]->superWarriorEvolution();
      }
    }
    else if ((((index + direction) == 0) || ((index + direction) == 11)) && (ground[index + direction] == nullptr))
    {
      if (ground[index]->getPlayerID() == 1) player2.targeted(ground[index]->getDamages());
      else if (ground[index]->getPlayerID() == 2) player1.targeted(ground[index]->getDamages());
      ground[index]->switchOnFAD();
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

        if (ground[index + range]->getLife() <= 0)
        {
          delete ground[index + range];
          ground[index + range] = nullptr;
        }

        ground[index]->switchOnFAD();
      }
      else if ((((index + range) == 0) || ((index + range) == 11)) && (ground[index + range] == nullptr))
      {
        if (ground[index]->getPlayerID() == 1) player2.targeted(ground[index]->getDamages());
        else if (ground[index]->getPlayerID() == 2) player1.targeted(ground[index]->getDamages());

        ground[index]->switchOnFAD();
      }

      range = range + direction;
      i++;
    }
  }
  else if (ground[index]->getVisual() == "__T__ ")
  {
    int i = 0, range = 2 * direction;

    while (!ground[index]->getActionBool() && i < 3 && ((index + range + direction) < 12) && ((index + range + direction) >= 0))
    {
      if (ground[index + range] != nullptr && ground[index + range]->getPlayerID() != ground[index]->getPlayerID())
      {
        ground[index + range]->targeted(ground[index]->getDamages());

        if (ground[index + range]->getLife() <= 0)
        {
          delete ground[index + range];
          ground[index + range] = nullptr;
        }

        if ((((index + range) == 0) || ((index + range) == 11)))
        {
          if (ground[index]->getPlayerID() == 1) player2.targeted(ground[index]->getDamages());
          else if (ground[index]->getPlayerID() == 2) player1.targeted(ground[index]->getDamages());
        }
        else if (ground[index + range + direction] != nullptr && ground[index + range + direction]->getPlayerID() != ground[index]->getPlayerID())
        {
          ground[index + range + direction]->targeted(ground[index]->getDamages());
          if (ground[index + range + direction]->getLife() <= 0)
          {
            delete ground[index + range + direction];
            ground[index + range + direction] = nullptr;
          }
        }

        ground[index]->switchOnFAD();
      }
      else if ((((index + range) == 0) || ((index + range) == 11)) && (ground[index + range] == nullptr))
      {
        if (ground[index]->getPlayerID() == 1) player2.targeted(ground[index]->getDamages());
        else if (ground[index]->getPlayerID() == 2) player1.targeted(ground[index]->getDamages());

        ground[index]->switchOnFAD();
      }

      std::cout << index + range << '\n';

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

  if ((ground[index]->getVisual() == "__W__ ") || (ground[index]->getVisual() == "__A__ ") || (ground[index]->getVisual() == "__S__ "))
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
  if((ground[index]->getVisual() == "__W__ ") || (ground[index]->getVisual() == "__A__ ") || (ground[index]->getVisual() == "__S__ "))
  {
    if ((!ground[index]->getActionBool()) || (ground[index]->getVisual() == "__S__ "))
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


void Playground::PVPGame()
{
  int choice;
  bool canBuy = false;

  while(!win() && turns < MAXTURNS)
  {
    turns += 1;
    player1.goldPay(8);
    player2.goldPay(8);

    display();

    for(auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        if (secondAction(i))
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i + 1);
        }
        else
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i);
        }
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    for(auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        if (secondAction(i))
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i - 1);
        }
        else
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i);
        }
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    if ((player1.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        std::cout << "Player 1, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip" << '\n';
        std::cin >> choice;

        switch (choice) {
          case 1:
          {
            if (player1.getGold() >= 10)
            {
              player1.buyUnit(10);
              canBuy = true;
            }
            break;
          }
          case 2:
          {
            if (player1.getGold() >= 12)
            {
              player1.buyUnit(12);
              canBuy = true;
            }
            break;
          }
          case 3:
          {
            if (player1.getGold() >= 20)
            {
              player1.buyUnit(20);
              canBuy = true;
            }
            break;
          }
          case 4:
          {
            canBuy = true;
            break;
          }
        }
      }
      spawnUnit(1, choice);
      display();
    }

    canBuy = false;

    if ((player2.getGold() >= 10) && (ground[11] == nullptr))
    {
      while (!canBuy)
      {
        std::cout << "Player 2, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip" << '\n';
        std::cin >> choice;

        switch (choice) {
          case 1:
          {
            if (player2.getGold() >= 10)
            {
              player2.buyUnit(10);
              canBuy = true;
            }
            break;
          }
          case 2:
          {
            if (player2.getGold() >= 12)
            {
              player2.buyUnit(12);
              canBuy = true;
            }
            break;
          }
          case 3:
          {
            if (player2.getGold() >= 20)
            {
              player2.buyUnit(20);
              canBuy = true;
            }
            break;
          }
          case 4:
          {
            canBuy = true;
            break;
          }
        }
      }
      spawnUnit(2, choice);
      display();
    }

    canBuy = false;
  }
}


void Playground::AIGame()
{
  int choice;
  bool canBuy = false;

  while(!win() && turns < MAXTURNS)
  {
    turns += 1;
    player1.goldPay(8);
    player2.goldPay(8);

    display();

    for(auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        if (secondAction(i))
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i + 1);
        }
        else
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i);
        }
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    for(auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        if (secondAction(i))
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i - 1);
        }
        else
        {
          display();
          std::this_thread::sleep_for (std::chrono::milliseconds(100));
          thirdAction(i);
        }
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    if ((player1.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        std::cout << "Player 1, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip" << '\n';
        std::cin >> choice;

        switch (choice) {
          case 1:
          {
            if (player1.getGold() >= 10)
            {
              player1.buyUnit(10);
              canBuy = true;
            }
            break;
          }
          case 2:
          {
            if (player1.getGold() >= 12)
            {
              player1.buyUnit(12);
              canBuy = true;
            }
            break;
          }
          case 3:
          {
            if (player1.getGold() >= 20)
            {
              player1.buyUnit(20);
              canBuy = true;
            }
            break;
          }
          case 4:
          {
            canBuy = true;
            break;
          }
        }
      }
      spawnUnit(1, choice);
      display();
    }

    canBuy = false;
    /*
    if ((player2.getGold() >= 10) && (ground[11] == nullptr))
    {
      if (player2.getGold() >= 20)
      {
        player2.buyUnit(20);
        spawnUnit(2, 3);
      }
      else if (player2.getGold() >= 12)
      {
        player2.buyUnit(12);
        spawnUnit(2, 2);
      }
      else if (player2.getGold() >= 10)
      {
        player2.buyUnit(12);
        spawnUnit(2, 2);
      }

      display();
    }
    */
  }
}
