#include "../header/Playground.hpp"


Playground::Playground(): turns(0), MAXTURNS(100), player1(1), player2(2), ground(12), oneWins(false), twoWins(false) {}


Playground::~Playground()
{
  for (auto i = 0 ; i < 12 ; i++)
  {
    if (ground[i] != nullptr) delete ground[i];
  }
}


int Playground::getTurns() const { return turns; }


int Playground::getPlayer1Life() const { return player1.getLife(); }


int Playground::getPlayer2Life() const { return player2.getLife(); }


/*
* Checks if a player won the game
* Default way to win is to lower the life of the other player to 0
* Or if the maximum number of turns is exceeded and a player's life is superior to the other
* There is no possibility to tie the game
*/
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
    else if (getPlayer1Life() > getPlayer2Life())
    {
      oneWins = true;
      return true;
    }
    else return false;
  }
  else return false;
}


void Playground::winningScreen()
{
  system("clear");

  if (oneWins)
  {
    std::cout << R"(
 ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄      ▄▄▄▄          ▄     ▄ ▄▄▄ ▄▄    ▄ ▄▄▄▄▄▄▄
 █       █   █   █      █  █ █  █       █   ▄  █    █    █        █ █ ▄ █ █   █  █  █ █       █
 █    ▄  █   █   █  ▄   █  █▄█  █    ▄▄▄█  █ █ █     █   █        █ ██ ██ █   █   █▄█ █  ▄▄▄▄▄█
 █   █▄█ █   █   █ █▄█  █       █   █▄▄▄█   █▄▄█▄    █   █        █       █   █       █ █▄▄▄▄▄
 █    ▄▄▄█   █▄▄▄█      █▄     ▄█    ▄▄▄█    ▄▄  █   █   █        █       █   █  ▄    █▄▄▄▄▄  █
 █   █   █       █  ▄   █ █   █ █   █▄▄▄█   █  █ █   █   █        █   ▄   █   █ █ █   █▄▄▄▄▄█ █
 █▄▄▄█   █▄▄▄▄▄▄▄█▄█ █▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄█  █▄█   █▄▄▄█        █▄▄█ █▄▄█▄▄▄█▄█  █▄▄█▄▄▄▄▄▄▄█

    )" << '\n';
  }
  else if (twoWins)
  {
    std::cout << R"(
 ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄      ▄▄▄▄▄▄▄          ▄     ▄ ▄▄▄ ▄▄    ▄ ▄▄▄▄▄▄▄
 █       █   █   █      █  █ █  █       █   ▄  █    █       █        █ █ ▄ █ █   █  █  █ █       █
 █    ▄  █   █   █  ▄   █  █▄█  █    ▄▄▄█  █ █ █    █▄▄▄▄   █        █ ██ ██ █   █   █▄█ █  ▄▄▄▄▄█
 █   █▄█ █   █   █ █▄█  █       █   █▄▄▄█   █▄▄█▄    ▄▄▄▄█  █        █       █   █       █ █▄▄▄▄▄
 █    ▄▄▄█   █▄▄▄█      █▄     ▄█    ▄▄▄█    ▄▄  █  █ ▄▄▄▄▄▄█        █       █   █  ▄    █▄▄▄▄▄  █
 █   █   █       █  ▄   █ █   █ █   █▄▄▄█   █  █ █  █ █▄▄▄▄▄         █   ▄   █   █ █ █   █▄▄▄▄▄█ █
 █▄▄▄█   █▄▄▄▄▄▄▄█▄█ █▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄█  █▄█  █▄▄▄▄▄▄▄█        █▄▄█ █▄▄█▄▄▄█▄█  █▄▄█▄▄▄▄▄▄▄█

    )" << '\n';
  }

  std::cout << "                                    PRESS ANY KEY TO EXIT" << '\n';
  std::cin.ignore();
  std::cin.get();
}


void Playground::pauseScreen()
{
  int choice;
  bool exit = false;
  do
  {
    system("clear");
    std::cout << "                                                PAUSE MENU" << '\n';
    std::cout << R"(
                                              /| ________________
                                        O|===|* >________________>
                                              \|
    )" << "\n\n\n";
    std::cout << "                                                1) Resume 2) Save\n";
    std::cin >> choice;

    switch (choice)
    {
      case 1:
      {
        exit = true;
        break;
      }
      case 2:
      {
        saveScreen();
        break;
      }
    }
  }
  while(!exit);
}


void Playground::saveScreen()
{
  system("clear");

  std::string response;

  do
  {
    std::cout << "                        DO YOU WANT TO SAVE THIS GAME ? [y/n] ";
    std::cin >> response;
  }
  while(response != "y" && response != "Y" && response != "n" && response != "N");

  if (response == "y" || response == "Y")
  {
    std::string name, location;
    bool overwrite = false;
    std::ofstream saveFile;

    do
    {
      std::cout << "                        ENTER THE NAME OF THE FILE: ";
      std::cin >> name;

      location = "../Saved games/" + name + ".txt";
      std::ifstream doublesCheck;

      doublesCheck.open(location);

      if (doublesCheck)
      {
        std::string choice;

        std::cout << "\n                        FILE ALREADY EXISTS !" << std::endl;
        std::cout << "                        DO YOU WANT TO OVERWRITE ? [y/n]  ";
        std::cin >> choice;

        if (choice == "y" || choice == "Y" ) { overwrite = true; }
      }
      else overwrite = true;
    }
    while (!overwrite);

    saveFile.open(location);

    //Saves if the game was against computer or between two players
    saveFile << computergame << '\n';

    //Saving the current round
    saveFile << turns << "\n\n";

    //Saving the status of first player
    saveFile << player1.getPlayerID() << '\n' << player1.getLife() << '\n' << player1.getGold() << "\n\n";

    //Saving the status of second player
    saveFile << player2.getPlayerID() << '\n' << player2.getLife() << '\n' << player2.getGold() << "\n\n";

    //Saving the units on the playground
    for (auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr) saveFile << ground[i]->getVisual() << "  " << ground[i]->getPlayerID() << "  " << ground[i]->getLife() << '\n';
      else saveFile << "_____\n";
    }

    saveFile.close();
    std::cout << "FILE SAVED SUCCESSFULLY" << '\n';
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
  }
}


void Playground::play()
{
  int gamemode;
  bool close = false;

  do
  {
    system("clear");
    std::cout << R"(
                    █████╗  ██████╗ ███████╗     ██████╗ ███████╗    ██╗    ██╗ █████╗ ██████╗
                    ██╔══██╗██╔════╝ ██╔════╝    ██╔═══██╗██╔════╝    ██║    ██║██╔══██╗██╔══██╗
                    ███████║██║  ███╗█████╗      ██║   ██║█████╗      ██║ █╗ ██║███████║██████╔╝
                    ██╔══██║██║   ██║██╔══╝      ██║   ██║██╔══╝      ██║███╗██║██╔══██║██╔══██╗
                    ██║  ██║╚██████╔╝███████╗    ╚██████╔╝██║         ╚███╔███╔╝██║  ██║██║  ██║
                    ╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝ ╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝
    )" << "\n\n";


    std::cout << "1) PLAYER VS PLAYER\n2) PLAYER VS COMPUTER\n3) LOAD SAVE\n4) EXIT" << '\n';
    std::cin >> gamemode;
    system("clear");

    switch (gamemode)
    {
      case 1:
      {
        computergame = false;
        PVPGame(false);
        break;
      }
      case 2:
      {
        computergame = true;
        computerGame(false);
        break;
      }
      case 3:
      {
        std::string load = "../Saved games/", selection;
        std::ifstream loadFile;

        std::cout << "                        ENTER THE NAME OF THE FILE: ";
        std::cin >> selection;
        load += selection + ".txt";
        loadFile.open(load);

        while(!loadFile)
        {
          loadFile.clear();
          load =  "../Saved games/";
          std::cout << '\n' << selection << " does not exist\n";
          std::cout << "                        ENTER THE NAME OF THE FILE: ";
          std::cin >> selection;
          load += selection + ".txt";
          loadFile.open(load);
        }

        int linecount = 0, groundcount = 0;
        std::string line;

        while (std::getline(loadFile, line))
        {
          //Loading the game mode
          if (linecount == 0)
          {
            computergame = '0' - line[0];
          }
          //Loading the current number of round
          else if (linecount == 1)
          {
            turns = std::stoi(line);
          }
          //Loading player 1 informations
          else if (linecount == 4)
          {
            player1.setLife(std::stoi(line));
          }
          else if (linecount == 5)
          {
            player1.setGold(std::stoi(line));
          }
          //Loading player 2 informations
          else if (linecount == 8)
          {
            player2.setLife(std::stoi(line));
          }
          else if (linecount == 9)
          {
            player2.setGold(std::stoi(line));
          }
          //Loading ground
          else if (linecount > 10 && linecount < 23)
          {
            std::string visual = line.substr(0, 5);

            if (visual != "_____")
            {
              int id = line[8] - '0', life = std::stoi(line.substr(11));

              if (visual == "__W__")
              {
                ground[groundcount] = new Warrior(id, life, false);
              }
              else if (visual == "__S__")
              {
                ground[groundcount] = new Warrior(id, life, true);
              }
              else if (visual == "__A__")
              {
                ground[groundcount] = new Archer(id, life);
              }
              else if (visual == "__T__")
              {
                ground[groundcount] = new Trebuchet(id, life);
              }
            }
            else ground[groundcount] = nullptr;

            groundcount++;
          }

          linecount++;
        }

        loadFile.close();

        if (computergame) computerGame(true);
        else PVPGame(true);

        break;
      }
      case 4:
      {
        std::cout << "BYE !" << std::endl;
        close = true;
        break;
      }
    }
  }
  while(!close);
}


void Playground::display()
{
  system("clear");
  std::cout << "ROUND " << turns << '\n';
  std::cout << "\n\n                  " << player1.getLife() << "                                                                " << player2.getLife() << '\n';
  std::cout << R"(
                _   |~  _                                                         _   |>  _
               [_]--'--[_]                                                       [_]--'--[_]
               |'|""'""|'|                                                       |'|""`""|'|
               | | /^\ | |                                                       | | /^\ | |
               |_|_|I|_|_|                                                       |_|_|H|_|_|)" << "\n\n\n\n                   ";

  for(auto i = 0 ; i < 12 ; i++)
  {
    if (ground[i] != nullptr)
    {
      if (ground[i]->getPlayerID() == 1)
      {
        std::cout << "\033[96m" << ground[i]->getVisual() << "\033[0m";
      }
      else
      {
        std::cout << "\033[93m" << ground[i]->getVisual() << "\033[0m";
      }
    }
    else std::cout << "_____ ";
  }

  std::cout << "\n\n                ";

  for(auto i = 0 ; i < 12 ; i++)
  {
    if (ground[i] != nullptr)
    {
      if (ground[i]->getLife() >= 8) std::cout << "\033[92m" << std::setw(6) << ground[i]->getLife() << "\033[0m";
      else if (ground[i]->getLife() >= 4) std::cout << "\033[33m" << std::setw(6) << ground[i]->getLife() << "\033[0m";
      else if (ground[i]->getLife() < 4) std::cout << "\033[91m" << std::setw(6) << ground[i]->getLife() << "\033[0m";
    }
    else std::cout << "      ";
  }

  std::cout << "\n\n                GOLD : " << player1.getGold() << "                                                         GOLD : " << player2.getGold() << "\n\n\n";
}


void Playground::spawnUnit(int playerID, int choice)
{
  if (choice != 4)
  {
    int spawnSpot;

    Warrior* warrior = new Warrior(playerID);
    Archer* archer = new Archer(playerID);
    Trebuchet* trebuchet = new Trebuchet(playerID);

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
    //If another unit is in front of warrior or super-warrior
    if (ground[index + direction] != nullptr && ground[index + direction]->getPlayerID() != ground[index]->getPlayerID())
    {
      ground[index + direction]->targeted(ground[index]->getDamages());
      ground[index]->switchOnFAD();

      //If the other unit is killed
      if (ground[index + direction]->getLife() <= 0)
      {
        if (direction == 1) player1.goldPay(ground[index + direction]->getPrice() / 2);
        else player2.goldPay(ground[index + direction]->getPrice() / 2);

        delete ground[index + direction];
        ground[index + direction] = nullptr;

        //Checks if the warrior can be evolved
        if (!ground[index]->getEvolution()) ground[index]->superWarriorEvolution();
      }
    }
    //If the warrior or super-warrior is in front the enemy castle and there is no unit in front of it, it attacks the castle
    else if ((((index + direction) == 0) || ((index + direction) == 11)) && (ground[index + direction] == nullptr))
    {
      if (ground[index]->getPlayerID() == 1) player2.targeted(ground[index]->getDamages());
      else if (ground[index]->getPlayerID() == 2) player1.targeted(ground[index]->getDamages());
      ground[index]->switchOnFAD();
    }
  }
  else if (ground[index]->getVisual() == "__A__ ")
  {
    int rangeMax = 4 * direction, range = direction;

    while (!ground[index]->getActionBool() && abs(range) <= abs(rangeMax))
    {
      //If another unit is in range the archer
      if (ground[index + range] != nullptr && ground[index + range]->getPlayerID() != ground[index]->getPlayerID())
      {
        ground[index + range]->targeted(ground[index]->getDamages());
        ground[index]->switchOnFAD();

        //If the enemy is killed
        if (ground[index + range]->getLife() <= 0)
        {
          if (direction == 1) player1.goldPay(ground[index + range]->getPrice() / 2);
          else player2.goldPay(ground[index + range]->getPrice() / 2);

          delete ground[index + range];
          ground[index + range] = nullptr;
        }

      }
      //If the enemy castle in range and there is no unit in front of it, it attacks the castle
      else if ((((index + range) == 0) || ((index + range) == 11)) && (ground[index + range] == nullptr))
      {
        if (ground[index]->getPlayerID() == 1) player2.targeted(ground[index]->getDamages());
        else if (ground[index]->getPlayerID() == 2) player1.targeted(ground[index]->getDamages());

        ground[index]->switchOnFAD();
      }

      range = range + direction;
    }
  }
  else if (ground[index]->getVisual() == "__T__ ")
  {
    int rangeMax = 4 * direction, range = 2 * direction;

    while (!ground[index]->getActionBool() && abs(rangeMax) > abs(range))
    {
      //If another unit is in range the trebuchet
      if ((ground[index + range] != nullptr) && (ground[index]->getPlayerID() != ground[index + range]->getPlayerID()))
      {
        ground[index + range]->targeted(ground[index]->getDamages());
        ground[index]->switchOnFAD();

        //If the enemy is killed
        if (ground[index + range]->getLife() <= 0)
        {
          if (direction == 1) player1.goldPay(ground[index + range]->getPrice() / 2);
          else player2.goldPay(ground[index + range]->getPrice() / 2);

          delete ground[index + range];
          ground[index + range] = nullptr;
        }

        //Checks if there is second unit right after
        if (ground[index + range + direction] != nullptr && ((index + range + direction) >= 0) && ((index + range + direction) < 12))
        {
          ground[index + range + direction]->targeted(ground[index]->getDamages());

          if (ground[index + range + direction]->getLife() <= 0)
          {
            if (direction == 1) player1.goldPay(ground[index + range + direction]->getPrice() / 2);
            else player2.goldPay(ground[index + range + direction]->getPrice() / 2);

            delete ground[index + range + direction];
            ground[index + range + direction] = nullptr;
          }
        }
      }
      //If there is no unit
      else if (ground[index + range] == nullptr)
      {
        //If the enemy castle is in range
        if (((index + range) == 0) && ground[index]->getPlayerID() == 2)
        {
          player1.targeted(ground[index]->getDamages());
          ground[index]->switchOnFAD();
        }
        else if (((index + range) == 11) && ground[index]->getPlayerID() == 1)
        {
          player2.targeted(ground[index]->getDamages());
          ground[index]->switchOnFAD();
        }
        else if ((abs(range + direction) >= abs(rangeMax)) && (ground[index + range + direction] != nullptr) && (ground[index]->getPlayerID() != ground[index + range + direction]->getPlayerID()))
        {
          ground[index + range + direction]->targeted(ground[index]->getDamages());
          ground[index]->switchOnFAD();
        }
      }

      range = range + direction;
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


  /*
  * Only the warriors, super-warriors and archers have a second action
  * They try to move forward
  */
  if ((ground[index]->getVisual() == "__W__ ") || (ground[index]->getVisual() == "__A__ ") || (ground[index]->getVisual() == "__S__ "))
  {
    if (direction > 0)
    {
      if ((ground[index + direction] == nullptr) && ((index + direction) < limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;

        return true;
      }
    }
    else
    {
      if ((ground[index + direction] == nullptr) && ((index + direction) > limit))
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
  //Archers, warriors and super-warriors try to attack
  if((ground[index]->getVisual() == "__W__ ") || (ground[index]->getVisual() == "__A__ ") || (ground[index]->getVisual() == "__S__ "))
  {
    if ((!ground[index]->getActionBool()) || (ground[index]->getVisual() == "__S__ "))
    {
      firstAction(index);
    }

    //Reset the boolean value to tell if the first action was done
    //The call of firstAction() turns it on if the unit can attack
    ground[index]->switchOffFAD();
  }
  //Trebuchets try to move forward
  else if ((ground[index]->getVisual() == "__T__ ") && (!ground[index]->getActionBool()))
  {
    int direction, limit;

    if (ground[index]->getPlayerID() == 1)
    {
      direction = 1;
      limit = 11;

      if ((ground[index + direction] == nullptr) && ((index + direction) < limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;
      }
    }
    else if (ground[index]->getPlayerID() == 2)
    {
      direction = -1;
      limit = 0;

      if ((ground[index + direction] == nullptr) && ((index + direction) > limit))
      {
        ground[index + direction] = ground[index];
        ground[index] = nullptr;
      }
    }

  }
  else ground[index]->switchOffFAD();
}


void Playground::PVPGame(bool load)
{
  int choice;
  bool canBuy = false;

  //If this is a loaded game, we start from the point where players buy units
  if (load)
  {
    display();

    //If player 1 can buy a unit
    if ((player1.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        display();
        std::cout << "Player 1, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip 5) Pause" << '\n';
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
          case 5:
          {
            pauseScreen();
            break;
          }
        }
      }
      spawnUnit(1, choice);
      display();
    }

    canBuy = false;

    //If player 2 can buy a unit
    if ((player2.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        display();
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
  }

  while(!win() && turns < MAXTURNS)
  {
    turns += 1;
    player1.goldPay(10);
    player2.goldPay(10);

    display();

    // First actions, Player 1
    for (auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    // First actions, Player 2
    for (auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    // Second and third actions, Player 1
    for(auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
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

    // Second and third actions, Player 2
    for(auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
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

    display();

    if ((player1.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        display();
        std::cout << "Player 1, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip 5) Pause" << '\n';
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
          case 5:
          {
            pauseScreen();
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
        display();
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

  winningScreen();
}


void Playground::computerGame(bool load)
{
  int choice;
  bool canBuy = false;

  //If this is a loaded game
  if (load)
  {
    display();

    if ((player1.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        display();
        std::cout << "Player 1, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip 5) Pause" << '\n';
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
          case 5:
          {
            pauseScreen();
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
      if (player2.getGold() >= 20)
      {
        player2.buyUnit(20);
        spawnUnit(2, 3);
      }
      else if (player2.getGold() >= 12 && player2.getGold() < 20)
      {
        player2.buyUnit(12);
        spawnUnit(2, 2);
      }
      else if (player2.getGold() >= 10 && player2.getGold() < 12)
      {
        player2.buyUnit(10);
        spawnUnit(2, 1);
      }

      display();
    }
  }

  while(!win() && turns < MAXTURNS)
  {
    turns += 1;
    player1.goldPay(10);
    player2.goldPay(10);

    display();

    // First actions, Player 1
    for (auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    // First actions, Computer
    for (auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
        firstAction(i);
        display();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
      }
    }

    // Second and third actions, Player 1
    for(auto i = 11 ; i >= 0 ; i--)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 1)
      {
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

    // Second and third actions, Computer
    for(auto i = 0 ; i < 12 ; i++)
    {
      if (ground[i] != nullptr && ground[i]->getPlayerID() == 2)
      {
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

    display();

    if ((player1.getGold() >= 10) && (ground[0] == nullptr))
    {
      while (!canBuy)
      {
        display();
        std::cout << "Player 1, buy a unit:\n1) Warrior (10g) 2) Archer (12g) 3) Trebuchet (20g) 4) Skip 5) Pause" << '\n';
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
          case 5:
          {
            pauseScreen();
            break;
          }
        }
      }
      spawnUnit(1, choice);
      display();
    }

    canBuy = false;

    //Computer tries to buy the most expensive unit it can
    if ((player2.getGold() >= 10) && (ground[11] == nullptr))
    {
      if (player2.getGold() >= 20)
      {
        player2.buyUnit(20);
        spawnUnit(2, 3);
      }
      else if (player2.getGold() >= 12 && player2.getGold() < 20)
      {
        player2.buyUnit(12);
        spawnUnit(2, 2);
      }
      else if (player2.getGold() >= 10 && player2.getGold() < 12)
      {
        player2.buyUnit(10);
        spawnUnit(2, 1);
      }

      display();
    }
  }

  winningScreen();
}
