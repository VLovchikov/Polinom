#pragma once
#include <iostream>
#include "MonomList.h"

class Polinom
{
	MonomList a;
	char *polinom;
	int length;
public:
	Polinom();
	Polinom(char *r)
	{
		length = strlen(r);
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
		a.print();
	}
	Polinom operator=(Polinom &b)
	{
		this->a = b.a;
		delete this->polinom;
		this->length = b.length;
		this->polinom = new char[b.length];
		int pos = 0;
		while (pos != b.length)
		{
			this->polinom[pos] = b.polinom[pos];
			pos++;
		}
		return *this;
	}
	Polinom operator+ (Polinom &b)
	{
		Monom *th = this->a.head();
		Monom *mon = b.a.head();
		while (th)
		{
			int count = 0;
			while (mon)
			{
				if (th->verstka == mon->verstka)
				{
					th->k += mon->k;
				}
				else
				{
					Monom *tt = new Monom;
					tt->k = mon->k;
					tt->verstka = mon->verstka;
					tt->next = th->next;
					th->next = tt;
					count++;
				}
				mon = mon->next;
			}
			count++;
			int i = 0;
			while (i != count)
			{
				th = th->next; i++;
			}
		}
		this->a.check();
		this->a.sort();
		return *this;
	}
	Polinom operator -(Polinom &pol)
	{
		Monom *th = this->a.head();
		Monom *mon = pol.a.head();
		while (th)
		{
			int count = 0;
			while (mon)
			{
				if (th->verstka == mon->verstka)
				{
					th->k -= mon->k;
				}
				else
				{
					Monom *tt = new Monom;
					tt->k = mon->k;
					tt->verstka = mon->verstka;
					tt->next = th->next;
					th->next = tt;
					count++;
				}
				mon = mon->next;
			}
			count++;
			int i = 0;
			while (i != count)
			{
				th = th->next; i++;
			}
		}
		this->a.check();
		this->a.sort();
		return *this;
	}
	Polinom operator *(Polinom &pol)
	{
		Monom *th = this->a.head();
		Monom *mon = pol.a.head();
		
		Polinom p = *this;
		p.a.clean();
		p.print();
		Monom *pp = p.a.head();
		while (th)
		{
			mon = pol.a.head();
			while (mon)
			{
				cout << "th=  " << th->verstka  << "  " << th->k << endl;;
				cout << "mon= " << mon->verstka << "  " << mon->k << endl;
				pp->k = th->k*mon->k;
				pp->verstka = th->verstka + mon->verstka;
				if ((mon->next&&th->next) == NULL) return *this;
				if (pp->next == NULL)
				{
					pp->next = new  Monom;
					pp = pp->next;
				}
				else
				{
					pp = pp->next;
				}
				mon = mon->next;
			}
			th = th->next;
		}
		return p;
	}
	~Polinom();
};

