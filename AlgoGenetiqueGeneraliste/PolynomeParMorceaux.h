#pragma once
#include "Individu.h"
class PolynomeParMorceaux : public Individu
{
	int nbMorceaux, ordreMax;
public:
	PolynomeParMorceaux(int _ordreMax, int _nbMorceaux, float *_bornesMin, float *_bornesMax);
	~PolynomeParMorceaux();

	void Evaluer(float *_in, float *_out);
};

