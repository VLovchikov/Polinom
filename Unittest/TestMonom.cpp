#include "MonomList.h"
#include "MonomList.cpp"
#include "gtest/gtest.h"


TEST(MonomList, can_create_Monom_with_NULL_ptr)
{
	ASSERT_NO_THROW(MonomList a);
}

TEST(MonomList, can_create_Monom_with_zero_koef)
{
	MonomList a;
	a.add("0x1y2z3");
	EXPECT_EQ(a.h->k, 0);
}

TEST(MonomList, can_create_Monom_with_neg_koef)
{
	MonomList a;
	a.add("-1x1y2z3");
	EXPECT_EQ(a.h->k, -1);
}

TEST(MonomList, can_create_Monom_with_long_koef)
{
	MonomList a;
	a.add("-1009x1y2z3");
	EXPECT_EQ(a.h->k, -1009);
}

TEST(MonomList, can_create_verstka)
{
	MonomList a;
	a.add("-1009x1y2z3");
	EXPECT_EQ(a.h->verstka, 1241);
}

TEST(MonomList, can_create_one_more_monom)
{
	MonomList a;
	a.add("-1009x1y2z3");
	a.add("-10x1y3z3");
	EXPECT_EQ(a.h->verstka, 1241);
	EXPECT_EQ(a.h->k, -1009);
	EXPECT_EQ(a.h->next->verstka, 1261);
	EXPECT_EQ(a.h->next->k, -10);
}

TEST(MonomList, can_clean_Monom)
{
	MonomList a;
	a.add("-1009x1y2z3");
	a.add("-10x1y3z3");
	a.clean();
	Monom *t = a.h;
	while (t)
	{
		EXPECT_EQ(t->k , 0);
		t = t->next;
	}
}

TEST(MonomList, can_print_Monom)
{
	MonomList a;
	a.add("-1009x1y2z3");
	ASSERT_NO_THROW(a.print());
}

TEST(MonomList, can_eq_Monom_is_empty)
{
	MonomList a;
	a.add("-1009x1y2z3");
	MonomList b;
	ASSERT_NO_THROW(b = a);
}

TEST(MonomList, can_eq_Monom_if_is_empty_Monom)
{
	MonomList a;
	a.add("-1009x1y2z3");
	MonomList b;
	ASSERT_NO_THROW(a = b);
}

TEST(MonomList, can_eq_Monom_if_is_empty_Monom_correctly)
{
	MonomList a;
	a.add("-1009x1y2z3");
	MonomList b;
	ASSERT_NO_THROW(a = b);
	a.print();
}

TEST(MonomList, can_sort)
{
	MonomList a;
	a.add("-100x1y2z3");
	a.add("-109x1y2z2");
	a.add("19x1y2z1");
	ASSERT_NO_THROW(a.sort());
}

TEST(MonomList, true_sort)
{
	MonomList a;
	a.add("-100x1y2z3");
	a.add("-109x1y2z2");
	a.add("19x1y2z1");
	a.sort();
	ASSERT_NO_THROW(a.print());
}