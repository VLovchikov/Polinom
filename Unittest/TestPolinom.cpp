#include "Polinom.h"
#include "Polinom.cpp"
#include "MonomList.h"
#include "gtest/gtest.h"

TEST(Polinom, can_create_polinom_with_NULL_head)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_create_polinom)
{
	const int m = 40;
	char *t = new char[m];
	t = "1x1y1z1+12x8y7z9";
	ASSERT_NO_THROW(Polinom p(t));
}

TEST(Polinom, can_work_copy_construct)
{
	const int m = 40;
	char *t = new char[m];
	t = "1x1y1z1+12x8y7z9";
	Polinom p(t);
	ASSERT_NO_THROW(Polinom pp(p));
}

TEST(Polinom, can_work_copy_construct_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "1x1y1z1+12x8y7z9";
	Polinom p(t);
	p.print();
	cout << endl;
	Polinom pp(p);
	ASSERT_NO_THROW(pp.print());
	
}

TEST(Polinom, can_create_polinom_with_first_neg_koef)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y1z1+12x8y7z9";
	ASSERT_NO_THROW(Polinom p(t));
}

TEST(Polinom, can_calculate_polinom)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	ASSERT_NO_THROW(double c=a.Calculate(2, 1, 3));
}

TEST(Polinom, can_calculate_polinom_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	a.print();
	int x = 2;
	int y = 1;
	int z = 3;
	double c = a.Calculate(x, y, z);
	EXPECT_EQ(c, 18);
	cout << "x=" << x << "   y=" << y << "   z=" << z << endl;
	cout <<"Answer: "<< c << endl;
}

TEST(Polinom, can_plus_Polinom)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	t = "9x1y2z3+22x5y3z1";
	Polinom aa(t);
	ASSERT_NO_THROW(a + aa);
}

TEST(Polinom, can_plus_Polinom_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	a.print();
	cout << endl;
	t = "9x1y2z1+22x5y3z1";
	Polinom aa(t);
	aa.print();
	cout << endl;
	cout << endl;
	ASSERT_NO_THROW(a + aa);
	aa.print();
}

TEST(Polinom, can_subtract_Polinom)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	t = "9x1y2z3+22x5y3z1";
	Polinom aa(t);
	ASSERT_NO_THROW(a - aa);
}

TEST(Polinom, can_subtract_Polinom_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	a.print();
	cout << endl;
	t = "9x1y2z1+22x5y3z1";
	Polinom aa(t);
	aa.print();
	cout << endl;
	cout << endl;
	ASSERT_NO_THROW(a - aa);
	a.print();
}

TEST(Polinom, can_myltiply_Polinom)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	t = "9x1y2z3+22x5y3z1";
	Polinom aa(t);
	ASSERT_NO_THROW(a * aa);
}

TEST(Polinom, can_myltiply_Polinom_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	a.print();
	cout << endl;
	t = "9x1y2z3+22x5y3z1";
	Polinom aa(t);
	aa.print();
	cout << endl;
	cout << endl;
	ASSERT_NO_THROW(a * aa);
	a.print();
}

TEST(Polinom, can_eq_Polinom)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	t = "9x1y2z3+22x5y3z1";
	Polinom aa(t);
	ASSERT_NO_THROW(a = aa);
}

TEST(Polinom, can_eq_Polinom_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	t = "9x1y2z3+22x5y3z1";
	Polinom aa(t);
	ASSERT_NO_THROW(a = aa);
	a.print();
	cout << endl;
	aa.print();
}


TEST(Polinom, can_reverse_convert_to_string)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	ASSERT_NO_THROW(a.ReverseConvert());
}

TEST(Polinom, can_reverse_convert_to_string_correctly)
{
	const int m = 40;
	char *t = new char[m];
	t = "-1x1y2z1+2x2y3z1";
	Polinom a(t);
	a.print();
	string str;
	ASSERT_NO_THROW(str=a.ReverseConvert());
	cout << str << endl;
}