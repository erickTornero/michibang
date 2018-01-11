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

void cardSupport::ordenar(carta *cards, int siz){
	for(int i = 0; i< siz - 1; i++){
		int indChng = findTheLessFrom(i,cards,siz);
		swap(i,indChng,cards);
	}
}
int cardSupport::findTheLessFrom(int indx, carta *cards,int siz){
	int num = cards[indx].numCarta;
	int idxLess = indx;
	for(;indx<siz;++indx){
		if(cards[indx].numCarta < num){
			num = cards[indx].numCarta;
			idxLess = indx;
		}
	}
	return idxLess;
}
void cardSupport::swap(int indx1,int indx2, carta *cards){
	if(indx1!=indx2){
		carta tmp = cards[indx2];
		cards[indx2] = cards[indx1];
		cards[indx1] = tmp;
	}

}
