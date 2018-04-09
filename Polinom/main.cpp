#pragma once

#include "Polinom.h"
#include <MonomList.h>

using namespace std;
const int m = 40;
char *t = new char[m];
int main()
{
	t = "10x1y1z1+8x6y7z9-12x7y6z4";
	Polinom p(t);
	string t = "10x1y1z1+89x6y7z9+10x2y5z10";
	Polinom pp(t);
	p.print();
	pp.print();
	p - pp;
	p.print();
	system("pause");
	return 0;
}