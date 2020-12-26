#include "Trebuchet.hpp"

Trebuchet::Trebuchet(int playerID):Unit(12, 20, 6, playerID, {2, 3}) {}

Trebuchet::~Trebuchet() {}

bool Trebuchet::fstAction(std::vector<Unit*> ground) {return true;}
bool Trebuchet::sndAction(std::vector<Unit*> ground) {return true;}
bool Trebuchet::thdAction(std::vector<Unit*> ground) {return true;}
