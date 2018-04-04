#pragma once

#include "Polinom.h"
#include <MonomList.h>

using namespace std;
const int m = 40;
char *t = new char[m];
int main()
{
	t = "1x1y1z1";
	MonomList l;
	l.add(t);
	MonomList ll;
	ll = l;
	ll.print();
	system("pause");
	return 0;
}