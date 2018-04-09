#include "Polinom.h"

Polinom::Polinom()
{
	MonomList();
	length = 0;
	polinom = NULL;
}

Polinom::Polinom(Polinom & pol)
{
	if (this->a.head() != NULL) delete[] this->polinom;
	this->a = pol.a;
	this->length = pol.length;
	this->polinom = new char[this->length];
	int i = 0;
	while (i != this->length)
	{
		this->polinom[i] = pol.polinom[i]; i++;
	}
}

Polinom::Polinom(char * r)
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
		while ((!(polinom[pos] == '-' || polinom[pos] == '+')) && pos != length)
		{
			buff[sizeMonom] = polinom[pos];
			sizeMonom++; pos++;
		}
		a.add(buff);
		delete buff;
	}
	a.sort();
	a.check();
}

Polinom::Polinom(string str)
{
	length = str.length();
	polinom = new char[length];
	for (int i = 0; i < length; i++)
	{
		polinom[i] = str[i];
	}
	int pos = 0;
	while (pos != length)
	{
		char *buff;
		buff = new char[length];
		int sizeMonom = 0;
		buff[sizeMonom] = polinom[pos];
		sizeMonom++; pos++;
		while ((!(polinom[pos] == '-' || polinom[pos] == '+')) && pos != length)
		{
			buff[sizeMonom] = polinom[pos];
			sizeMonom++; pos++;
		}
		a.add(buff);
		delete buff;
	}
	a.sort();
	a.check();
}

Polinom::Polinom(Monom * mon)
{
	this->a.h = mon;
}

Polinom::~Polinom()
{
}

void Polinom::print()
{
	if (this->a.head() == NULL) return;
	a.print();
}

Polinom Polinom::operator=(Polinom & b)
{
	if (this->a.h == b.a.h) return *this;
	this->a = b.a;
	delete[] this->polinom;
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

Polinom Polinom::operator+(Polinom & b)
{
	if (this->a.head() == NULL) return b;
	if (b.a.head() == NULL) return *this;
	Monom *th = this->a.head();
	Monom *mon = b.a.head();
	while (th&&mon)
	{
		if (mon->verstka == th->verstka)
		{
			th->k += mon->k;
		}
		if (mon->verstka < th->verstka&&th==this->a.head())
		{
			Monom *t = new Monom;
			t->k = mon->k;
			t->verstka = mon->verstka;
			t->next = th;
			a.h = t;
			th = this->a.head();
		}
		if (mon->verstka < th->verstka&&th != this->a.head())
		{
			Monom *t = this->a.head();
			while (t->next != th)
			{
				t = t->next;
			}
			Monom *m = new Monom;
			m->k = mon->k;
			m->verstka = mon->verstka;
			t->next = m;
			m->next = th;
		}
		if (mon->verstka > th->verstka)
		{
			while (th->next != NULL&&th->next->verstka < mon->verstka)
			{
				th = th->next;
			}
			if (th->next == NULL&&mon != NULL)
			{
				while (mon)
				{
					Monom *t = new Monom;
					t->k = mon->k;
					t->verstka = mon->verstka;
					th->next = t;
					th = th->next;
					th->next = NULL;
					mon = mon->next;
				}
				this->a.check();
				return *this;
			}
			if (th->next == NULL) return *this;
			if (th->next->verstka == mon->verstka)
			{
				th->next->k += mon->k;
			}
			else
			{
				Monom *m = new Monom;
				m->k = mon->k;
				m->verstka = mon->verstka;
				m->next = th->next;
				th->next = m;
			}
		}
		if (th->next==NULL&&mon!=NULL)
		{
			while (mon)
			{
				Monom *t = new Monom;
				t->k = mon->k;
				t->verstka = mon->verstka;
				th->next = t;
				th = th->next;
				th->next = NULL;
				mon = mon->next;
			}
			this->a.check();
			return *this;
		}
		th = th->next;
		mon = mon->next;
	}
	this->a.check();
	return *this;
}

Polinom Polinom::operator-(Polinom & b)
{
	if (this->a.head() == NULL)
	{
		Monom *bb = b.a.head();
		while (bb)
		{
			bb->k *= -1;
			bb = bb->next;
			return *this = b;
		}
	}
	if (b.a.head() == NULL) return *this;
	Monom *th = this->a.head();
	Monom *mon = b.a.head();
	while (th&&mon)
	{
		if (mon->verstka == th->verstka)
		{
			th->k -= mon->k;
		}
		if (mon->verstka < th->verstka&&th == this->a.head())
		{
			Monom *t = new Monom;
			t->k = mon->k;
			t->verstka = mon->verstka;
			t->next = th;
			a.h = t;
			th = this->a.head();
		}
		if (mon->verstka < th->verstka&&th != this->a.head())
		{
			Monom *t = this->a.head();
			while (t->next != th)
			{
				t = t->next;
			}
			Monom *m = new Monom;
			m->k = mon->k;
			m->verstka = mon->verstka;
			t->next = m;
			m->next = th;
		}
		if (mon->verstka > th->verstka)
		{
			while (th->next != NULL&&th->next->verstka < mon->verstka)
			{
				th = th->next;
			}
			if (th->next == NULL&&mon != NULL)
			{
				while (mon)
				{
					Monom *t = new Monom;
					t->k = mon->k;
					t->verstka = mon->verstka;
					th->next = t;
					th = th->next;
					th->next = NULL;
					mon = mon->next;
				}
				this->a.check();
				return *this;
			}
			if (th->next == NULL) return *this;
			if (th->next->verstka == mon->verstka)
			{
				th->next->k -= mon->k;
			}
			else
			{
				Monom *m = new Monom;
				m->k = mon->k;
				m->verstka = mon->verstka;
				m->next = th->next;
				th->next = m;
			}
		}
		if (th->next == NULL&&mon != NULL)
		{
			while (mon)
			{
				Monom *t = new Monom;
				t->k = mon->k;
				t->verstka = mon->verstka;
				th->next = t;
				th = th->next;
				th->next = NULL;
				mon = mon->next;
			}
			this->a.check();
			return *this;
		}
		th = th->next;
		mon = mon->next;
	}
	this->a.check();
	return *this;
}

Polinom Polinom::operator*(Polinom & pol)
{
	if (this->a.head() == NULL || pol.a.head() == NULL)
	{
		this->a.clean();
		return *this;
	}
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
			if (mn == NULL&&th->next == NULL)
			{
				pp->next = NULL;
				p.a.check();
				p.a.sort();
				return *this = p;
			}
			else
			{
				pp->next = new Monom;
				pp = pp->next;
			}
		}
		th = th->next;
	}
	pp->next = NULL;
	p.print();
	p.a.check();
	p.a.sort();
	*this = p;
	return *this;
}

double Polinom::Calculate(int xx, int yy, int zz)
{
	double  total = 0;
	Monom *t = this->a.head();
	int x = xx;
	int y = yy;
	int z = zz;
	while (t)
	{
		int grz = 0;
		int gry = 0;
		int grx = 0;
		grz = t->verstka / 400;
		gry = (t->verstka - 400 * grz) / 20;
		grx = t->verstka - (400 * grz + 20 * gry);
		total += pow(x, grx) * pow(y, gry) * pow(z, grz)*t->k;
		t = t->next;
	}
	return total;
}

string Polinom::ReverseConvert()
{
	Monom *t = a.head();
	string str = "";
	while (t)
	{
		string k = "";
		if (t->k > 0)k = k + "+";
		k = k + to_string(t->k);
		int grz = t->verstka / 400;
		int gry = (t->verstka - grz * 400) / 20;
		int grx = t->verstka - grz * 400 - gry * 20;
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
