#ifndef _CARD_SUPPORT
#define _CARD_SUPPORT

#include <string>
enum PALO
{
	TREBOL = 'C',
	ESPADA = 'S',
	CORAZON = 'H',
	DIAMANTE = 'D'
};
struct carta{
	PALO paloDeCarta;
	int numCarta;
};
class cardSupport{
public:

	static carta decodeCard(std::string str);
	static std::string encodeCard(carta card);
	static void ordenar(carta *cards,int siz);
private:
	//Secondary functions
	static void swap(int indx1,int indx2, carta *cards);
	static int findTheLessFrom(int indx, carta *cards,int siz);
};



#endif
