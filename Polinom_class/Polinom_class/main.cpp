#pragma once

#include "Polinom.h"
#include <MonomList.h>

using namespace std;
const int m = 40;
char *t = new char[m];
int main()
{
	t = "14x3y6z2-43x4y6z6+54x7y12z9";
	Polinom pol(t);
	t = "4x3y6z2-4x4y6z6+54x9y12z9";
	Polinom pol2(t);
	pol = pol2;
	pol.print();
	system("pause");
	return 0;
}