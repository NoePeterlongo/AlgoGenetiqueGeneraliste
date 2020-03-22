#include "pch.h"
#include "PolynomeParMorceaux.h"

//

PolynomeParMorceaux::PolynomeParMorceaux(int _ordreMax, int _nbMorceaux, float *_bornesMin, float *_bornesMax):
	Individu((_ordreMax+1)*_nbMorceaux + _nbMorceaux-1, _bornesMin, _bornesMax)
{
	nbMorceaux = _nbMorceaux;
	ordreMax = _ordreMax;
}


PolynomeParMorceaux::~PolynomeParMorceaux()
{
}

void PolynomeParMorceaux::Evaluer(float *_in, float *_out)
{
	int numMorceau = 0;
	while (_in[0] > parametres[numMorceau] && numMorceau < nbMorceaux)
		numMorceau++;
	int indiceDepart = nbMorceaux + numMorceau * (ordreMax + 1);

	_out[0] = 0;
	for (int i = 0; i <= ordreMax; i++)
	{
		_out[0] += parametres[indiceDepart + i] * pow(_in[0], i);
	}
}
