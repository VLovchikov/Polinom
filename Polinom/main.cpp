#pragma once

#include "Polinom.h"
#include <MonomList.h>

using namespace std;
const int m = 40;
char *t = new char[m];
int main()
{
	string t = "2x1y1z5+10x2y2z10-2x1y1z1";
	Polinom p(t);
	t = "10x0y0z1+5x2y0z1";
	Polinom pp(t);
	p * pp;
	string ss = p.ReverseConvert();
	cout << ss << endl;
	int tt = 0;
	cout << p.Calculate(2.09, 0, 9.81);
	system("pause");
	return 0;
}