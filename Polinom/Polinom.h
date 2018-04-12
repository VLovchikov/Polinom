#pragma once
#include <iostream>
#include "MonomList.h"
#include <string>


using namespace std;

class Polinom
{
	MonomList a;
	
public:
	Polinom();
	Polinom(Polinom &pol);
	Polinom(char *r);
	Polinom(string str);
	Polinom(Monom *mon);
	~Polinom();
	void print();
	Polinom operator=(Polinom &b);
	Polinom operator+ (Polinom &b);
	Polinom operator -(Polinom &pol);
	Polinom operator *(Polinom &pol);
	double Calculate(double xx, double yy, double zz);
	string ReverseConvert();
};

