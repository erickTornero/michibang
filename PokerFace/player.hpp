#ifndef _PLAYER
#define _PLAYER

#include "cardSupport.hpp"
class player{
public:
	carta cartas[5];
	int asignarCartas(std::string subAr);
private:
	int numCarta = 0;
};
#endif
