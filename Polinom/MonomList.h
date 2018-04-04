#pragma once
#include <iostream>

using namespace std;

struct Monom
{
	int verstka;
	int k;
	Monom *next;
};
class MonomList
{
public:
	Monom *h;
	MonomList() { h = NULL; };
	bool isEmpty() { return h == NULL; }
	void add(char *t)
	{
		int kk = 0;
		int vv = 0;
		int length = strlen(t);
		int pos = 0;
		char *a;
		a = new char[length];
		for (int i = 0; i < length; i++)
		{
			a[i] = t[i];
		}
		while (pos != length)
		{
			if (a[pos] == '+')
			{
				string str;
				pos++;
				while (a[pos] != 'x')
				{
					str = str + a[pos];
					pos++;
				}
				kk = atoi(str.c_str());
			}
			if (a[pos] == '-')
			{
				string str = "";
				pos++;
				while (!(a[pos] == 'x' || a[pos] == 'y' || a[pos] == 'z'))
				{
					str = str + a[pos];
					pos++;
				}
				kk = atoi(str.c_str());
				kk *= -1;
			}
			if (a[pos] >= '0' && a[pos] <= '9')
			{
				string str;
				while (!(a[pos] == 'x' || a[pos] == 'y' || a[pos] == 'z'))
				{
					str = str + a[pos];
					pos++;
				}
				kk = atoi(str.c_str());
			}
			if (a[pos] == 'x')
			{
				pos++;
				string str;
				int k = 0;
				while (!(a[pos] == 'y' || a[pos] == 'z' || pos == length))
				{
					str = str + a[pos];
					pos++;
				}
				k = atoi(str.c_str());
				vv += k;
			}
			if (a[pos] == 'y')
			{
				pos++;
				string str = "";
				int k;
				while (!(a[pos] == 'x' || a[pos] == 'z' || pos == length))
				{
					str = str + a[pos];
					pos++;
				}
				k = atoi(str.c_str());
				vv += k * 20;
			}
			if (a[pos] == 'z')
			{
				pos++;
				string str = "";
				int k;
				while (!(a[pos] == 'y' || a[pos] == 'x' || pos == length))
				{
					str = str + a[pos];
					pos++;
				}
				k = atoi(str.c_str());
				vv += k * 400;
			}
		}
		if (h == NULL)
		{
			h = new Monom;
			h->k = kk;
			h->verstka = vv;
			h->next = NULL;
		}
		else
		{
			Monom *t = h;
			while (t->next != NULL)
			{
				t = t->next;
			}
			t->next = new Monom;
			t = t->next;
			t->k = kk;
			t->verstka = vv;
			t->next = NULL;
		}
	}
	void sort()
	{
		Monom *t = h;
		while (t)
		{
			Monom *p = t->next;
			while (p)
			{
				if (t->verstka > p->verstka)
				{
					int kk, vv;
					vv = t->verstka;
					t->verstka = p->verstka;
					p->verstka = vv;
					kk = t->k;
					t->k = p->k;
					p->k = kk;
				}
				p = p->next;
			}
			t = t->next;
		}
	}
	void check()
	{
		if (h->k == 0 && h->next != NULL)
		{
			Monom *t = h;
			h = h->next;
			delete t;
		}
		if (h->next != NULL&&h->next->next != NULL)
		{
			Monom *ex = h;
			Monom *n = ex->next;
			while (n->next != NULL)
			{
				if (n->k == 0)
				{
					Monom *r = n;
					n = n->next;
					ex->next = n;
					delete r;
				}
				else
				{
					n = n->next;
					ex = ex->next;
				}
			}
			if (n->next == NULL&&n->k == 0)
			{
				delete n;
				ex->next = NULL;
			}
		}
	}
	void print()
	{
		Monom *t = h;
		if (t == NULL) return;
		while (t)
		{
			cout << "verstka= " << t->verstka << "  " << "koef= " << t->k << endl;
			t = t->next;
		}
	}
	~MonomList()
	{
	}
	Monom *head()
	{
		return h;
	}
	MonomList operator=(MonomList &mon)
	{
		if (this->h == mon.h) return *this;
		if (this->h == NULL&&mon.h != NULL)
		{
			h = new Monom;
			h->next = NULL;
		}
		if (mon.h == NULL)
		{
			this->clean();
			return *this;
		}
		this->clean();
		Monom *th = this->h;
		Monom *m = mon.h;
		while (m)
		{
			this->copy(th, m);
			if (m->next == NULL)
			{
				th->next = NULL;
				return *this;
			}
			if (th->next == NULL)
			{
				th->next = new Monom;
			}
			m = m->next;
			th = th->next;
			th->k = 0;
			th->verstka = 0;
			th->next = NULL;
		}
		return *this;
	}
	void clean()
	{
		Monom *t = h;
		if (t == NULL) return;
		while (t)
		{
			t->k = 0;
			t->verstka = 0;
			if (t->next == NULL) return;
			t = t->next;
		}
	}
	void copy(Monom *th, Monom *mon)
	{
		th->k = mon->k;
		th->verstka = mon->verstka;
	}
};