#include "Playground.hpp"

Playground::Playground(): turns(0), MAXTURNS(100), player1(1), player2(2), units(12) {}

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
  int gamemode;

  std::cout << R"(
   █████╗  ██████╗ ███████╗     ██████╗ ███████╗    ██╗    ██╗ █████╗ ██████╗
  ██╔══██╗██╔════╝ ██╔════╝    ██╔═══██╗██╔════╝    ██║    ██║██╔══██╗██╔══██╗
  ███████║██║  ███╗█████╗      ██║   ██║█████╗      ██║ █╗ ██║███████║██████╔╝
  ██╔══██║██║   ██║██╔══╝      ██║   ██║██╔══╝      ██║███╗██║██╔══██║██╔══██╗
  ██║  ██║╚██████╔╝███████╗    ╚██████╔╝██║         ╚███╔███╔╝██║  ██║██║  ██║
  ╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝ ╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝
  )" << '\n';

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

  while(!win())
  {
    display();
    turns += 1;
    player1.goldPay(8);
    player2.goldPay(8);
  }
}

void Playground::display()
{
  std::string empty = "____ ";
  int boxNumber = 1;

  // castles top
  std::cout <<
R"(|\/\/\/|                                                   |\/\/\/|
|  P1  |                                                   |  P2  |)" << '\n';

  for (int i = 0 ; i < 4 ; i++)
  {
    int j = 0;

    while (j < 67)
    {
      if (j == 0 || j == 7 || j == 59 || j == 66)
      {
        std::cout << "| ";
        j += 2;
      }
      else
      {
        if (i == 3 && units[boxNumber] == nullptr)
        {
          std::cout << empty;
          j += 5;
          boxNumber += 1;
        }
        else
        {
          std::cout << " ";
          j += 1;
        }
      }
    }
    std::cout << '\n';
  }
}
