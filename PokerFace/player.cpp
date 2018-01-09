#include "player.hpp"

int player::asignarCartas(std::string subAr){
	carta car = cardSupport::decodeCard(subAr);
	cartas[numCarta] = car;
	numCarta++;
	if(numCarta == 5){
		numCarta = 0;
		return 1;
	}
	else{
		return 0;
	}
}
