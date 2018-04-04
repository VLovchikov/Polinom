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