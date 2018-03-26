#pragma once
#include <iostream>
#include "MonomList.h"

class Polinom
{
	MonomList a;
	char *polinom;
public:
	Polinom(char *r)
	{
		int length = strlen(r);
		polinom = new char[length];
		for (int i = 0; i < length; i++)
		{
			polinom[i] = r[i];
		}
		int pos = 0;
		const int max = 20;
		char *k = new char[max];
		for (int z = 0; z < max; z++)
		{
			k[z] = ' ';
		}
		if (polinom[0] == '-')
		{
			k[0] = '-';
			pos++;
			while (polinom[pos] != '-' || polinom[pos] != '+')
			{
				k[pos] = polinom[pos];
				pos++;
			}
			a.add(k);
			for (int z = 0; z < max; z++)
			{
				k[z] = ' ';
			}
		}

	}
	~Polinom();
};

