#ifndef _CARD_SUPPORT
#define _CARD_SUPPORT

#include <string>
class cardSupport{
public:
	enum PALO
	{
		TREBOL = 'C',
		ESPADA = 'S',
		CORAZON = 'H',
		DIAMANTE = 'D'
	};

	enum NUMBER{
		DOS = '2',
		TRES = '3',
		CUATRO = '4',
		CINCO = '5',
		SEIS = '6',
		SIETE = '7',
		OCHO = '8',
		NUEVE = '9',
		DIEZ = '1',
		JACK = 'J',
		QUEEN = 'Q',
		KING = 'K'
	};
	struct carta{
		PALO paloDeCarta;
		int numCarta;
	};


private:
	carta decodeCard(std::string str);
	std::string encodeCard(carta card);
};



#endif
