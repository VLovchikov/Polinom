#include <Polinom.h>
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
	double c=a.Calculate(2, 1, 3);
	EXPECT_EQ(c, 18);
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
	aa.print();
}

