#pragma once
#include <iostream>
#include "MonomList.h"
#include <string>


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
		
	};
	void print()
	{
		if (this->a.head() == NULL) return;
		a.print();
	}
	Polinom operator=(Polinom &b)
	{
		if (this->a.h == b.a.h) return *this;
		this->a = b.a;
		delete [] this->polinom;
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
			if (th->next == NULL)
			{
				this->a.check();
				this->a.sort();
				return *this;
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
			if (th->next == NULL)
			{
				this->a.check();
				this->a.sort();
				return *this;
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
		*this = p;
		return *this;
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
			total +=pow(x,grx) * pow(y,gry) * pow(z,grz)*t->k;
			t = t->next;
		}
		return total;
	}
	string ReverseConvert()
	{
		Monom *t = a.head();
		string str = "";
		while (t)
		{
			string k="";
			if (t->k > 0)k = k + "+";
			k = k + to_string(t->k);
			int grz=t->verstka/400;
			int gry=(t->verstka-grz*400)/20;
			int grx=t->verstka-grz*400-gry*20;
			k = k + "x";
			k = k + to_string(grx);
			k = k + "y";
			k = k + to_string(gry);
			k = k + "z";
			k = k + to_string(grz);
			str = str + k;
			t = t->next;
		}
		return str;
	}
};

