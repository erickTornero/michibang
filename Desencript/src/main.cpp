#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//Helps to handle the char and the frequency in a vector
struct vectorFrequency{
	char letter;
	int frequency;
};
string str = "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\nXof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe\nql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg\nfnxfexdqn oqp ge ofe.\nZgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\nXof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf\nqx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef\nfstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro\ngxofe. - Mgon Rdepdrw.\n(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";
string freqLang = "TEOAISRHNUCMDLGWFPYKJBVQX";
char str2[]="Hello World";
string decryptMessage(string &encrypted, string freqLang);
vector<vectorFrequency> getVectorFrequency(const string &encrypted);
int setVectorWithChar(char caract, vector<vectorFrequency> &vec);
vector<vectorFrequency> orderMaxToMinFreq(const vector<vectorFrequency>&vec);
int main()
{
	string resp = decryptMessage(str,freqLang);
	cout<<resp;
	return 0;
}
/*
 * decryptMessage
 * brief: returns the message decrypted
 */
string decryptMessage(string &encrypted, string freqLang){
	unsigned int messageSize = encrypted.length();
	//Get the vector of frequency not ordered.
	vector<vectorFrequency> vecFreq = getVectorFrequency(encrypted);
	//Get the vector of frequency ordered
	vector<vectorFrequency> vecOrdered = orderMaxToMinFreq(vecFreq);

	for(unsigned int i = 0; i < messageSize; i++){
		bool wasUpper = false;
		char car = encrypted[i];
		//Save the status if it's upper case
		wasUpper=isupper(car);
		if(wasUpper){
			car = tolower(car);
		}
		unsigned int index = 0;
		for(index = 0; index< vecOrdered.size(); index++){
			if(vecOrdered[index].letter == car){
				//compare the vector ordered with freqLang
				if(wasUpper){
					encrypted[i]=freqLang[index];
				}else{
					encrypted[i]=tolower(freqLang[index]);
				}
				break;
			}
		}

	}
	return encrypted;
}
/*
 * getVectorFrequency:
 * brief: encrypted-> message encrypted
 * How it works: Returns a vector of frequency but not ordered.
 * For each caracter of the encrypted text puts in a vector the letter and the frequency
 * for that purpose "setVectorWithChar" support it.
 * Note: vectorFrequency: is an struct that helps to save frequency and caracter in a vector.
 */
vector<vectorFrequency> getVectorFrequency(const string &encrypted)
{
	unsigned int lengthMessage = encrypted.length();
	vector<vectorFrequency> vecFrequency;
	for(unsigned int i = 0; i < lengthMessage; i++){
		//If conditional to take only alphabetic letters in upper case or in lower case
		if((encrypted[i]>char(96)&&encrypted[i]<char(123))||(encrypted[i]>char(64)&&encrypted[i]<91)){
			//acumms in the vecFrequency the current char.
			setVectorWithChar(encrypted[i],vecFrequency);
		}
	}
	return vecFrequency;
}
/*
 * setVectorWithChar:
 * Add the char in a vector of vectorFrequency Struct
 * if the char exists in the vector, the frequency increases by 1
 * else push at the end of the vector the new char and start its frequency in 1
 */
int setVectorWithChar(char caract, vector<vectorFrequency> &vec){
	unsigned int lengthVec = vec.size();
	//In case the char is upper case
	char car = tolower(caract);
	unsigned int j=0;
	//run all vector asking if the char exists
	for(j = 0; j < lengthVec; j++){
		if(vec[j].letter == car)
		{
			//if the char exists increase the frequency of the char by 1
			vec[j].frequency++;
			return 0;
		}
	}
	//Apply when the vector is empty or when the char doesn't exists.
	vectorFrequency arg;
	arg.frequency = 1;
	arg.letter = car;
	vec.push_back(arg);
	return 1;
}
/*
 * orderMaxToMinFreq:
 * Brief: Returns an ordered vector in accordance the frequency from more to less frequency
 * from another vector.
 * How it works: Create a new empty vector.
 * 				-push the first value.
 * 				-insert the next value previous comparison the frequency value.
 */
vector<vectorFrequency> orderMaxToMinFreq(const vector<vectorFrequency>&vec){
	vector<vectorFrequency> tmpVc;
	unsigned int sizeOfVec = vec.size();
	//puts the first char in the first place of the vector ordered
	tmpVc.push_back(vec[0]);
	for(unsigned int k = 1; k< sizeOfVec; k++){
		unsigned int index = 0;
		for(unsigned int pp = 0; pp < tmpVc.size(); pp++){
			if(vec[k].frequency>tmpVc[pp].frequency){
				//get the index where the current value of frequency is bigger
				//so it will displace to the right the rest of the vector.
				index =pp;
				break;
			}
			//in case the current frequency is the lowest
			index = pp+1;
		}
		//displace and insert the value of the vector in the ordered vector
		tmpVc.insert(tmpVc.begin()+index,vec[k]);
	}
	return tmpVc;
}

