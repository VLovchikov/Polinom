#pragma once

#include "Polinom.h"
#include <MonomList.h>

using namespace std;
const int m = 40;
char *t = new char[m];
int main()
{
	t = "1x1y1z1+2x2y2z5+3x3y3z2";
	Polinom pol(t);
	t = "+4x1y1z2+5x1y1z1";
	Polinom pol2(t);
	pol.operator*(pol2);
	pol.print();
	int x = 1;
	int y = 2;
	int z = 1;
	double c=pol.Calculate(x, y, z);
	cout << c;
	system("pause");
	return 0;
}