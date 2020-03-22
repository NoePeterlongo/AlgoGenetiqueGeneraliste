#pragma once
class Individu
{
public:
	Individu(int _nbParametres, float *_bornesMin, float *_bornesMax);
	~Individu();

	void Evaluer(float *_in, float *_out);

	void CroisementMy(Individu &parent1, Individu &parent2, float deviation = 0);
	void Croisement2(Individu &parent1, Individu &parent2);
	void PetitesMutations(Individu &parent, float proportion, float amplitude);
	void Explorer();

	void Print();

	float note;
	int nbParametres;
	float *parametres;
	float *bornesMax, *bornesMin;
};


bool ComparateurPointeursDIndividu(Individu *individu1, Individu *individu2);

//A changer
void Noter(Individu *individu);
