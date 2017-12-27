#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include "numbersOp.hpp"
using namespace std;

vector<char> mch;
vector<int> testGame;
int checkIfWin(char car, const vector<char>mich);
int putChar(char car,int index, vector<char>&mic);
int searchTriad(int n,const vector<int>vectOf);
char emulateAGame(vector<int> &move, vector<char> & michi);
int generateNumbers(const vector<int> &toSort);
int generateNumbers2(const vector<int> &toSort);
vector<queueValue1> qqq;
vector<int> sort;
int main(){

	mch.resize(9);/*
	michi[0] = 'X';michi[1] = '0';michi[2] = '0';
	michi[3] = 'X';michi[4] = '0';michi[5] = '0';
	michi[6] = '0';michi[7] = '0';michi[8] = '0';
	cout<<checkIfWin('X',michi);*/

	/*testGame.resize(9);
	testGame[0]=1;testGame[1]=2;testGame[2]=3;testGame[3]=4;testGame[4]=5;
	testGame[5]=7;testGame[6]=6;testGame[7]=8;testGame[8]=9;
	for(unsigned j=0; j< testGame.size(); j++){
			cout<<testGame[j];
	}
	cout<<endl;
	cout<<emulateAGame(testGame,mch)<<endl;
	for(unsigned j=0; j< testGame.size(); j++){
		cout<<testGame[j];
	}
	cout<<endl;
	for(unsigned j=0; j< mch.size(); j++){
		cout<<mch[j];
	}*/
	std::vector<std::string> example;
	example.push_back("this");
	example.push_back("is");
	example.push_back("a");
	example.push_back("test");

	std::ofstream output_file("./example.txt");
	std::ostream_iterator<std::string> output_iterator(output_file, "\n");
	std::copy(example.begin(), example.end(), output_iterator);

	vector<int> numbers;
	numbers.resize(9);
	numbers[0]=1;numbers[1]=2;numbers[2]=3;numbers[3]=4;numbers[4]=5;
	numbers[5]=6;numbers[6]=7;numbers[7]=8;numbers[8]=9;
	//generateNumbers2(numbers);
	sort.resize(9);
	numbersOp ob(qqq);
	ob.generateNumbers3(qqq,sort);
	cout<<endl<<"*******end of first*******"<<endl;
	ob.generateNumbers3(qqq,sort);
	cout<<endl<<"*******end of Second*******"<<endl;
	ob.generateNumbers3(qqq,sort);
	cout<<endl<<"*******end of Second*******"<<endl;
	ob.generateNumbers3(qqq,sort);
	cout<<endl<<"*******end of Second*******"<<endl;
	ob.generateNumbers3(qqq,sort);
	cout<<"fin"<<endl;
}
/*
 * CheckIfWin:
 * brief: Check if the current car wins in the actual michi.
 * returns 1: if the car wins the michi
 * else returns 0.
 */
int checkIfWin(char car,const vector<char>mich){
	vector<int> vect;
	for(unsigned int i = 0;i < mich.size(); i++){
		if(mich[i] == car){
			vect.push_back(i+1);
			//cout<<i+1;
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
}/*
int generateNumbers(const vector<int> &toSort){
	vector<int> sorted;
	vector<int> toSortTemp;
	sorted.resize(9);
	/*for(unsigned igeneral = 0 ; igeneral< 9; i++){

	}
	for(unsigned i1 = 0; i1< 9; i1 ++){
		toSortTemp = toSort;
		sorted[0] = toSort[i1];
		toSortTemp.erase(toSortTemp.begin()+i1);
		for(unsigned int i2 = 0;i2 < toSortTemp.size(); i2++){
			vector<int> temp2 = toSortTemp;
			sorted[1] = temp2[i2];
			temp2.erase(temp2.begin()+i2);
			for(unsigned int i3 = 0; i3 < temp2.size(); i3 ++){
				vector<int> temp3 = temp2;
				sorted[2] = temp3[i3];
				temp3.erase(temp3.begin()+i3);
				//for(unsigned int i4 = 0; i4< temp3.size(); i4 ++){
					//vector<int> temp4 = temp3;
					//sorted[2] = temp4[i3];
					//temp4.erase(temp4.begin()+i3);
					for(unsigned int dd = 0; dd<sorted.size();dd++){
						cout<<sorted[dd];
					}
					cout<<endl;
				//}
			}

		}
	}
	return 0;
}
int generateNumbers2(const vector<int> &toSort){
	vector<queueValue1> queue;
	queue.resize(9);
	vector<int> sorted;
	sorted.resize(9);
	for(unsigned int i=0; i<queue.size();i++){
		queue[i].value = i+1;
	}
	queue[0].isBusy[0] = 1;
	queue[1].isBusy[1] = 1;
	int index = 0;
	while(index < 9){
		for(unsigned int j=0;j<queue.size();j++){
			if(queue[j].usedInCurrent == 0){
				sorted[index] = queue[j].value;
				queue[j].usedInCurrent = 1;
				index ++;
			}
		}
	}
	for(unsigned int dd = 0; dd<sorted.size();dd++){
		cout<<sorted[dd];
	}

}*/
/*
 * Fills the michi from the movements of the game gave in a vector of Ints.
 */
char emulateAGame(vector<int> &move, vector<char> & michi){
	for(unsigned int i = 0; i < move.size();i ++){
		char car;
		if(i%2 == 0){
			car = 'X';
		}
		else{
			car = '0';
		}
		putChar(car,move[i] -1,michi);
		/*Just do it when you're sure that there are more than 3 movements of the
		 * same character.
		 */
		int someOneWins = 0;
		if(i >= 4){
			someOneWins = checkIfWin(car,michi);
			if(someOneWins == 1){
				if(i < move.size() - 1){
					//Puts 0 the movements that won't be do
					for(unsigned int k = i+1;k < move.size();k ++){
						move[k] = 0;
					}
				}
				return car;
			}
		}
	}
	//When no-one wins the game
	return 'E';
}

