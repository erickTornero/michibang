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
};



#endif
