#include "cardSupport.hpp"

carta cardSupport::decodeCard(std::string str){

	carta carModel;
	char c = str[0];
	int number;
	if(c > char(49)&& c < char(58)){
		number = c - 48;
	}
	else{
		switch(c){
		case 'A':number = 1;break;
		case 'T':number = 10;break;
		case 'J':number = 11;break;
		case 'Q':number = 12;break;
		case 'K':number = 13;break;
		default:break;
		}
	}
	carModel.numCarta = number;
	carModel.paloDeCarta = (PALO)str[1];
	return carModel;
}
