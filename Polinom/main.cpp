#pragma once

#include "Polinom.h"
#include <MonomList.h>

using namespace std;
const int m = 40;
char *t = new char[m];
int main()
{
	t = "1x1y1z1-10x6y5z7+4x6y4z8";
	Polinom p(t);
	t = "1x1y1z1-1x3y2z7+4x4y1z2";
	Polinom pp(t);
	p.operator*(pp);
	p.print();
	system("pause");
	return 0;
}