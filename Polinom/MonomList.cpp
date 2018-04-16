#include "MonomList.h"

void MonomList::add(char * t)
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

void MonomList::sort()
{
	if (h == NULL) return;
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

void MonomList::check()
{
	if (h == NULL) return;
	if (h->k == 0 && h->next != NULL)
	{
		Monom *t = h;
		h = h->next;
		delete t;
	}
	if (h->next!=NULL&&h->next->k == 0)
	{
		if (h->next->next != NULL)
		{
			Monom *t = h->next;
			h->next = h->next->next;
			delete t;
		}
		else
		{
			Monom *t = h->next;
			h->next = NULL;
			delete t;
		}
	}
	if (h->next != NULL&&h->next->next != NULL)
	{
		Monom *tt = h;
		while (tt->next != NULL)
		{
			if (tt->next->k == 0)
			{
				Monom *r = tt->next;
				if (tt->next->next == NULL)
				{
					tt->next = NULL;
				}
				else
				{
					tt->next = tt->next->next;
				}
				delete r;
			}
			else
			{
				tt = tt->next;
			}
		}
	}
}

void MonomList::print()
{
	Monom *t = h;
	if (t == NULL) return;
	while (t)
	{
		cout << "verstka= " << t->verstka << "  " << "koef= " << t->k << endl;
		t = t->next;
	}
}

MonomList::~MonomList()
{
}

Monom * MonomList::head()
{
	return h;
}

MonomList MonomList::operator=(MonomList & mon)
{
	if (this->h == mon.h) return *this;
	if (this->h == NULL&&mon.h != NULL)
	{
		this->h = new Monom;
		this->h->next = NULL;
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
		if (th->next == NULL&&m->next != NULL)
		{
			th->next = new Monom;
			th->next->next = NULL;
		}
		if (m->next == NULL&&th->next != NULL)
		{
			Monom *t = th->next;
			while (t)
			{
				Monom *tt = t;
				t = t->next;
				delete tt;
			}
			th->next = NULL;
			return *this;
		}
		if (th->next == NULL&&m->next == NULL) return *this;
		m = m->next;
		th = th->next;
		th->k = 0;
		th->verstka = 0;
	}
	return *this;
}

void MonomList::clean()
{
	Monom *t = h;
	if (t == NULL) return;
	while (t)
	{
		t->k = 0;
		t->verstka = 0;
		t = t->next;
	}
}

void MonomList::copy(Monom * th, Monom * mon)
{
	th->k = mon->k;
	th->verstka = mon->verstka;
}
