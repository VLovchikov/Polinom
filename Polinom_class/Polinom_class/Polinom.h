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
		while (pos != length)
		{
			char *buff;
			buff = new char[length];
			int sizeMonom = 0;
			buff[sizeMonom] = polinom[pos];
			sizeMonom++; pos++;
			while ((!(polinom[pos] == '-' || polinom[pos] == '+'))&&pos!=length)
			{
				buff[sizeMonom] = polinom[pos];
				sizeMonom++; pos++;
			}
			a.add(buff);
			delete buff;
		}
	}
	void print()
	{
		Monom *t = a.head();
		while (t)
		{
			cout << "Verstka: " << t->verstka << "koef:  " << t->k << endl;
			t = t->next;
		}
	}
	Polinom operator=(Polinom &b)
	{
		this->a = b.a;
		this->polinom = b.polinom;
		return *this;
	}
	Polinom operator+ (Polinom &b)
	{
		Monom *f = this->a.head();
		Monom *t = b.a.head();
		while (t)
		{
			while (f)
			{
				if (t->verstka == f->verstka)
				{
					t->verstka += f->verstka;
				}
				f = f->next;
			}
			t = t->next;
		}

		this->a.check();
		return *this;
	}
	~Polinom();
};

