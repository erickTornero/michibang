#ifndef _PLAYER
#define _PLAYER

#include "cardSupport.hpp"
class player{
public:
	int cartaMaxima;
	carta cartas[5];
	int asignarCartas(std::string subAr);
	int explorarMano();
private:
	//Para asignar cartas
	int numCarta = 0;
	//Cuantas cartas iguales se tienen
	int numCartasIguales;

	int find_HIGHCARD();
	int find_ONEPAIR();
	int find_TWOPAIRS();
	int find_THREEofaKIND();
	int find_STRAIGHT();
	int find_FULLHOUSE();
	int find_FOURofaKIND();
	int find_STRAIGHTFLUSH();
	int find_ROYALFLUSH();



};
#endif
