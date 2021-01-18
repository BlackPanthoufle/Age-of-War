#include "../header/Trebuchet.hpp"


Trebuchet::Trebuchet(int playerID):Unit(12, 20, 6, playerID) {}


Trebuchet::~Trebuchet() {}


std::string Trebuchet::getVisual() { return "__T__ "; }
