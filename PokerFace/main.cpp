
#include <fstream>
#include <iostream>
#include "player.hpp"
std::string getNextStringOfCard(std::string line, int &currentCol);
int main()
{
	std::string line;
	std::ifstream myfile("pocker.txt");
	player player1;
	player player2;
	if(myfile.is_open()){
		while(getline(myfile,line)){
			std::cout<<line<<'\n';
			int cc=0;
			while(!player1.asignarCartas(getNextStringOfCard(line,cc))){

			}
			while(!player2.asignarCartas(getNextStringOfCard(line,cc))){

			}
			//std::cout<<getNextStringOfCard(line,cc);

		}

		myfile.close();
	}
	for(int i=0;i<5;i++){
		std::cout<<player1.cartas[i].numCarta<<"\t";
		std::cout<<(char)player1.cartas[i].paloDeCarta<<std::endl;
	}
	for(int i=0;i<5;i++){
		std::cout<<player2.cartas[i].numCarta<<"\t";
		std::cout<<(char)player2.cartas[i].paloDeCarta<<std::endl;
	}
	for(;;){

	}
}

std::string getNextStringOfCard(std::string line, int &currentCol){
	std::string str;
	for(; currentCol< line.length(); currentCol++){
		if(!isspace(line[currentCol])){
			str.push_back(line[currentCol]);
		}
		else{
			currentCol++;
			break;
		}
	}
	return str;
}
