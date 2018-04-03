#include <Polinom.h>
#include "gtest/gtest.h"

TEST(Polinom, can_create_polinom_with_NULL_head)
{
	ASSERT_NO_THROW(Polinom p);
}