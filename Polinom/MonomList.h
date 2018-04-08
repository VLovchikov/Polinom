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
	void add(char *t);
	void sort();
	void check();
	void print();
	~MonomList();
	Monom *head();
	MonomList operator=(MonomList &mon);
	void clean();
	void copy(Monom *th, Monom *mon);
};