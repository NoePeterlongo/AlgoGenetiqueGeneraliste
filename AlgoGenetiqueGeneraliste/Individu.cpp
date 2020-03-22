#include "pch.h"
#include "Individu.h"

#define boucleParam for(int i = 0; i < nbParametres; i++)

Individu::Individu(int _nbParametres, float *_bornesMin, float *_bornesMax)
{
	bornesMin = _bornesMin;
	bornesMax = _bornesMax;
	nbParametres = _nbParametres;

	parametres = new float[nbParametres];
	Explorer();
}

Individu::~Individu()
{
	delete[] parametres;
}

void Individu::Explorer()
{
	boucleParam
		parametres[i] = bornesMin[i] + (bornesMax[i] - bornesMin[i])*(float)rand() / RAND_MAX;
}

void Individu::CroisementMy(Individu &parent1, Individu &parent2, float deviation)
{
	boucleParam
		parametres[i] = parent1.parametres[i] + parent2.parametres[i] + ((float)rand() / RAND_MAX - 0.5f)*deviation;
}

void Individu::Croisement2(Individu &parent1, Individu &parent2)
{
	boucleParam
	{
		float tirage = rand() / RAND_MAX;
		if (tirage > 0.5f)
			parametres[i] = parent1.parametres[i];
		else
			parametres[i] = parent2.parametres[i];
	}
}

void Individu::PetitesMutations(Individu &parent, float proportion, float amplitude)
{
	boucleParam
	{
		float tirage = rand() / RAND_MAX;
	if (tirage > proportion)
		parametres[i] = parent.parametres[i];
	else
		parametres[i] = parent.parametres[i] + amplitude * 2 * ((float)rand() / RAND_MAX - 0.5f);
	}
}

void Individu::Print()
{
	boucleParam
	{
		std::cout << parametres[i] << " ";
	}
}

//A vocation a etre surchargee
void Individu::Evaluer(float *_in, float *_out)
{
	float somme = 0;
	boucleParam
		somme += abs(parametres[i]);
	_out[0] = somme;
}

bool ComparateurPointeursDIndividu(Individu *individu1, Individu *individu2)
{
	return individu1->note < individu2->note;
}

//A surcharger
void Noter(Individu *individu)
{
	individu->Evaluer(NULL, &individu->note);
}