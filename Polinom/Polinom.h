#pragma once
#include <iostream>
#include "MonomList.h"

using namespace std;

class Polinom
{
	MonomList a;
	char *polinom;
	int length;
public:
	Polinom()
	{
		MonomList();
		length = 0;
		polinom = NULL;
	}
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
	Polinom(Monom *mon)
	{
		this->a.h = mon;
	}
	~Polinom()
	{
		delete [] polinom;
		Monom *t = this->a.h;
		while (t)
		{
			Monom *tt = t;
			t = t->next;
			delete tt;
		}
		delete t;
	};
	void print()
	{
		if (this->length == 0) return;
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
		Monom *mn;
		Monom *pp = new Monom;
		pp->next = NULL;
		Polinom p(pp);
		while (th)
		{
			mn = pol.a.head();
			while (mn)
			{
				pp->k = th->k*mn->k;
				pp->verstka = th->verstka + mn->verstka;
				mn = mn->next;
				if (mn == NULL&&th->next== NULL)
				{
					pp->next = NULL;
					p.a.check();
					p.a.sort();
					return *this=p;
				}
				else
				{
					pp->next = new Monom;
					pp = pp->next;
				}
			}
			th =th->next;
		}
		pp->next = NULL;
		p.print();
		p.a.check();
		p.a.sort();
		return p;
	}
	double Calculate(int xx, int yy, int zz)
	{
		double  total = 0;
		Monom *t = this->a.head();
		int x = xx;
		int y = yy;
		int z = zz;
		while (t)
		{
			int grz=0;
			int gry=0;
			int grx=0;
			grz = t->verstka / 400;
			gry = (t->verstka - 400 * grz) / 20;
			grx = t->verstka - (400 * grz + 20 * gry);
			total +=pow(x,grz) * pow(y,gry) * pow(z,grz)*t->k;
			cout << "total= " << total <<"  t->koef=  "<<t->k<<"  grz=" << grz << "  gry= " << gry << "  grx= " <<grx << endl;
			t = t->next;
		}
		return total;
	}
};

