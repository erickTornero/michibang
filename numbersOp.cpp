#include "numbersOp.hpp"
numbersOp::numbersOp(vector<queueValue1>&q){
	fillQueue(q);
}
int numbersOp::generateNumbers3(vector<queueValue1> &queue, vector<int> &sorted)
{
	int index = 0;
	int resp = 0;
	do{
		if(resp == 0){
			cout<<"exechere"<<endl;
		}
		resp = tryToPutNextNumber(queue,sorted,index);
	}while(resp != 2);
	clearBusy(queue);
	for(unsigned int dd = 0; dd<sorted.size();dd++){
		cout<<sorted[dd];
	}
}
/*
 * Etiqueta como desocupado los N últimos caracteres
 * v: The queue with all flags of busy
 * howManyN:
 * vec: All numbers to delete
 */
void numbersOp::freeLast(vector<queueValue1> &v,const vector<int> vec){
	for(unsigned int p = 0; p<vec.size();p++){
		unsigned int pp = v.size() - vec.size();
		if(p == 0){
			v[vec[0]-1].isBusy[pp] = 1;
			pp++;
			//because I was using it
			v[vec[0]-1].usedInCurrent = 0;
			for(;pp < v.size();pp++){
				v[vec[p]-1].isBusy[pp] = 0;
			}
		}
		else{
			pp++;
			for(;pp < v.size();pp++){
				v[vec[p]-1].isBusy[pp] = 0;
			}
		}
	}
	cout<<"queue[7]=";cout<<v[6].isBusy[6]<<endl;
	cout<<"queue[8]=";cout<<v[7].isBusy[6]<<endl;
}
/*
 * Intenta colocar el siguiente número dado un índice, si no lo logra
 * quiere decir que todos los valores ya se intentaron
 * así que correr un digito a la derecha.
 * No importa si ya se lleno, la funcion intentara colocar el siguiente caracter.
 */
int numbersOp::tryToPutNextNumber(vector<queueValue1> &v, vector<int> &vSorted, int &ind){
	/*for(int y=0;y<9;y++){
		cout<<vSorted[y];
	}
	cout<<"--";*/
	int theLast = 0;
	cout<<endl;
	for(unsigned int j=0;j <v.size();j++){
		if(v[j].usedInCurrent == 0 && v[j].isBusy[ind] == 0){
			cout<<"Current Index: "<<ind;
			vSorted[ind] = v[j].value;
			v[j].usedInCurrent = 1;
			cout<<"::Value::"<<vSorted[ind]<<endl;
			//v[j].isBusy[ind] = 1;
			cout<<"witin ";
			if(ind == v.size()-1){
				cout<<"thelast: "<<theLast<<endl;
				theLast = 2;
				break;
			}
			ind ++;
			return 1;
		}
	}
	--ind;
	cout<<"*out of*-index=";
	cout<<ind<<endl;
	vector<int> toRest;
	toRest.resize(vSorted.size()-ind);
	int tmpIdx = ind;
	for(unsigned i = 0; i< toRest.size(); i++){
		toRest[i] = vSorted[ind+i];
		cout<<toRest[i]<<"-";
	}
	cout<<endl;
	freeLast(v,toRest);
	return theLast;
}
int numbersOp::fillQueue(vector<queueValue1> &qu){
	qu.resize(9);
	for(unsigned int i=0; i<qu.size();i++){
		qu[i].value = i+1;
	}
	cout<<"passhere"<<endl;
}
int numbersOp::clearBusy(vector<queueValue1> &qu){
	for(unsigned t = 0; t<qu.size(); t++){
		qu[t].usedInCurrent = 0;
	}
}
