

#include "pch.h"
#include <iostream>
#include "Individu.h"
#include "PolynomeParMorceaux.h"

#define NB_INDIVIDUS 10
#define NB_ITERATIONS 100000

#define NB_MORCEAUX 5
#define ORDREMAX 4

void ChargerCSV(const char *nomFichier, std::vector<float> &_x, std::vector<float> &_y)
{
	FILE *fichier = fopen(nomFichier, "r");
	float x, y;
	while (fscanf(fichier, "%f;%f\n", &x, &y)==2)
	{
		_x.push_back(x);
		_y.push_back(y);
	}
	fclose(fichier);
}

void EcrireCSV(const char *nomFichier, std::vector<float> &_x, std::vector<float> &_y, PolynomeParMorceaux &f)
{
	FILE *fichier = fopen(nomFichier, "w");
	float x, y;
	for (int i = 0; i < _x.capacity(); i++)
	{
		x = _x[i];
		f.Evaluer(&x, &y);
		fprintf(fichier, "%f;%f;%f\n", _x[i], _y[i], y);
	}
	fclose(fichier);
}

void Noter(PolynomeParMorceaux &f, std::vector<float> &_x, std::vector<float> &_y)
{
	float note=0, x, y;

	for (int i = 0; i < _x.capacity(); i++)
	{
		x = _x[i];
		f.Evaluer(&x, &y);
		note += abs(_y[i] - y);
	}
	f.note = note;
}


int main()
{
	std::vector<float> xIn, yIn;
	ChargerCSV("Classeur1.csv", xIn, yIn);

	const int NB_PARAM = NB_MORCEAUX - 1 + NB_MORCEAUX * (ORDREMAX + 1);
	float bornesMax[NB_PARAM], bornesMin[NB_PARAM];
	for (int i = 0; i < NB_PARAM; i++)
	{
		bornesMax[i] = 10;
		bornesMin[i] = -10;
	}
	PolynomeParMorceaux *population[NB_INDIVIDUS];
	for (int i = 0; i < NB_INDIVIDUS; i++)
		population[i] = new PolynomeParMorceaux(4, 5, bornesMin, bornesMax);
	population[0]->Print();
	std::cout << std::endl;

	for (int it = 0; it < NB_ITERATIONS; it++)
	{
		for (int i = 0; i < NB_INDIVIDUS; i++)
			Noter(population[i]);

		std::sort(population, population + NB_INDIVIDUS, ComparateurPointeursDIndividu);

		if (it % 10000 == 0)
		{
			std::cout << "\nGeneration " << it << " : meilleur score " << population[0]->note << "\n\t";
			population[0]->Print();
		}

		population[3]->CroisementMy(*population[0], *population[1]);
		population[4]->CroisementMy(*population[0], *population[1], 1);
		population[5]->Croisement2(*population[0], *population[1]);
		population[6]->Croisement2(*population[0], *population[1]);
		population[7]->Croisement2(*population[0], *population[2]);
		population[8]->CroisementMy(*population[1], *population[2], 1);
		for (int i = 9; i < NB_INDIVIDUS; i++)
			population[i]->Explorer();
	}

	EcrireCSV("out.CSV", xIn, yIn, *population[0]);
}

