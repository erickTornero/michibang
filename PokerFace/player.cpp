#include "player.hpp"

int player::asignarCartas(std::string subAr){
	carta car = cardSupport::decodeCard(subAr);
	cartas[numCarta] = car;
	numCarta++;
	if(numCarta == 5){
		cardSupport::ordenar(cartas,5);
		numCarta = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int player::explorarMano(){

}

int player::find_HIGHCARD(){

}
int player::find_ONEPAIR(){

}
int player::find_TWOPAIRS(){

}
int player::find_THREEofaKIND(){

}
int player::find_STRAIGHT(){

}
int player::find_FULLHOUSE(){

}
int player::find_FOURofaKIND(){
	int number = cartas[0].numCarta;
	for(unsigned int i=1;i<5;i++){
		if(number!=cartas[i].numCarta){
			return 0;
		}
	}
	cartaMaxima = cartas[0].numCarta;
	return 8;
}
int player::find_STRAIGHTFLUSH(){
//Verificar PALO:
	carta cardIt = cartas[0];
	for(unsigned int i=1;i<5;i++){
		if(cardIt.paloDeCarta!=cartas[i].paloDeCarta){
			return 0;
		}
		if(cartas[i]-cartas[i-1]!=1||cartas[i]-cartas[i-1]!=-13){
			return 0;
		}
		cardIt = cartas[i];
	}

}
int player::find_ROYALFLUSH(){
	if(cartas[0].numCarta ==1&&cartas[1].numCarta==10&&cartas[2].numCarta==11&&cartas[3].numCarta==12&&cartas[4].numCarta==13){
		for(unsigned int i=1;i<5;i++){
			if(cartas[0].paloDeCarta!=cartas[i].paloDeCarta){
				return 0;
			}
		}
		cartaMaxima = cartas[0].numCarta;
		return 10;
	}
	return 0;
}

