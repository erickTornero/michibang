#include <vector>
#include <iostream>
using namespace std;
struct queueValue1{
public:
	int isBusy[9];// = {0,0,0,0,0,0,0,0,0};
	int usedInCurrent;
	int value;
	queueValue1(){
		usedInCurrent = 0;
		for(uint d= 0; d<9;d++){
			isBusy[d] = 0;
		}
	}
};
class numbersOp{
public:
	numbersOp(vector<queueValue1>&q);
	int generateNumbers3(vector<queueValue1> &v, vector<int> &sorted);
private:
	void freeLast(vector<queueValue1> &v, const vector<int> vec);
	int tryToPutNextNumber(vector<queueValue1> &v, vector<int> &vSorted,int &ind);
	int fillQueue(vector<queueValue1> &qu);
	int clearBusy(vector<queueValue1> &qu);
};
