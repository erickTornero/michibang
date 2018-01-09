
#include <fstream>
#include <iostream>
#include "cardSupport.hpp"
std::string getNextStringOfCard(std::string line, int &currentCol);
int main()
{
	std::string line;
	std::ifstream myfile("pocker.txt");
	if(myfile.is_open()){
		while(getline(myfile,line)){
			std::cout<<line<<'\n';
			int cc=0;
			std::cout<<getNextStringOfCard(line,cc);
			std::cout<<getNextStringOfCard(line,cc);

			std::cout<<getNextStringOfCard(line,cc);
			std::cout<<getNextStringOfCard(line,cc);

			std::cout<<getNextStringOfCard(line,cc);
			std::cout<<getNextStringOfCard(line,cc);

			std::cout<<getNextStringOfCard(line,cc);
			std::cout<<getNextStringOfCard(line,cc);

			std::cout<<getNextStringOfCard(line,cc);
			std::cout<<getNextStringOfCard(line,cc);

			std::cout<<getNextStringOfCard(line,cc);
			std::cout<<getNextStringOfCard(line,cc);
		}

		myfile.close();
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
