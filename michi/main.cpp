#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <string>
#include "numbersOp.hpp"
using namespace std;

vector<char> mch;
vector<int> testGame;
int checkIfWin(char car, const vector<char>mich);
int putChar(char car,int index, vector<char>&mic);
int searchTriad(int n,const vector<int>vectOf);
char emulateAGame(const vector<int> &move,vector<int> &respuesta, vector<char> & michi, int &atIndex);
void listAllTicTacToeGames(string fileName);
void clearMichi(vector<char> &michx);
vector<queueValue1> qqq;
vector<int> sort;
numbersOp ob(qqq);
int main(){
	mch.resize(9);
	sort.resize(9);
	listAllTicTacToeGames("myFile.txt");
}
void listAllTicTacToeGames(string fileName) {
	ofstream myfile;
	myfile.open(fileName);
	int i = 0;
	long N = 0;
	int jumpIndex = 0;
	vector<int> jugada;
	cout << "start";
	while (i != 3)
	{
		N++;
		i = ob.generateNumbers3(qqq, sort);
		clearMichi(mch);
		char winer = emulateAGame(sort, jugada, mch, jumpIndex);
		if (jumpIndex < mch.size() - 1) {
			ob.jumpR(qqq, jumpIndex, sort);
		}
		unsigned int rr;
		if (i != 3) {
			myfile << N << "\t";
			for (unsigned int dd = 0; dd<mch.size(); dd++) {
				myfile << jugada[dd];
				rr = dd;
			}
			myfile << "\t" << winer;
			myfile << "\n";
		}

	}
	myfile << "fin" << "\n";
	myfile.close();
}
/*
 * CheckIfWin:
 * brief: Check if the current char wins in the actual michi.
 * returns 1: if the car wins the michi
 * else returns 0.
 */
int checkIfWin(char car,const vector<char>mich){
	vector<int> vect;
	for(unsigned int i = 0;i < mich.size(); i++){
		if(mich[i] == car){
			vect.push_back(i+1);
		}
	}
	int thereismatch = 0;
	for(unsigned int i=0; i<vect.size();i++){
		if(vect[i] == 1||vect[i]==5||vect[i]==9){
			//Search in table of wins.
			thereismatch = searchTriad(vect[i],vect);
			if(thereismatch){
				break;
			}
		}
	}
	return thereismatch;
}
int putChar(char car,int index, vector<char>&mic){
	mic[index] = car;
	return 0;
}
/*
 * searchTriad:
 * brief:			returns 1 if there's a triad that can be a match.
 * 					in case that there's not such triad return 0.
 *
 * How it Works:	Start to search a triad from a number, in this
 * 					case (1,5, or 9), this numbers cover all posible wins.
 * 					if we get that number then try to search a number
 * 					of posible match. For example
 * 					if we get 9, then we search 3 and 6 or 7 and 8
 */
int searchTriad(int n,const vector<int>vectOf){
	switch(n){
	case 5:
		for(unsigned int i = 0;i < vectOf.size();i ++){
			if(vectOf[i] == 1){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 9){
						return 1;
					}
				}
			}
			else if(vectOf[i] == 2){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 8){
						return 1;
					}
				}
			}
			else if(vectOf[i] == 3){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 7){
						return 1;
					}
				}
			}
			else if(vectOf[i] == 4){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 6){
						return 1;
					}
				}
			}
		}
		break;
	case 1:
		for(unsigned int i = 0;i < vectOf.size();i ++){
			if(vectOf[i] == 2){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 3){
						return 1;
					}
				}
			}
			else if(vectOf[i] == 4){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 7){
						return 1;
					}
				}
			}
		}
		break;
	case 9:
		for(unsigned int i = 0;i < vectOf.size();i ++){
			if(vectOf[i] == 3){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 6){
						return 1;
					}
				}
			}
			else if(vectOf[i] == 7){
				for(unsigned int k = i;k < vectOf.size(); k ++){
					if(vectOf[k] == 8){
						return 1;
					}
				}
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

/*
 * Fills the michi from the movements of the game gave in a vector of Ints.
 */
char emulateAGame(const vector<int> &move,vector<int> &respuesta, vector<char> & michi, int &atIndex){
	respuesta = move;
	for(unsigned int i = 0; i < move.size();i ++){
		char car;
		if(i%2 == 0){
			car = 'X';
		}
		else{
			car = '0';
		}
		putChar(car,respuesta[i] -1,michi);
		/*Just do it when you're sure that there are more than 3 movements of the
		 * same character.
		 */
		int someOneWins = 0;
		if(i >= 4){
			someOneWins = checkIfWin(car,michi);
			if(someOneWins == 1){
				atIndex = i;
				if(i < respuesta.size() - 1){
					//Puts 0 the movements that won't be do
					for(unsigned int k = i+1;k < respuesta.size();k ++){
						respuesta[k] = 0;
					}
				}
				return car;
			}
		}
	}
	//When no-one wins the game
	return 'E';
}

void clearMichi(vector<char> &michx){
	for(unsigned int jj = 0; jj<michx.size();jj++){
		michx[jj] = 'N';
	}
}
