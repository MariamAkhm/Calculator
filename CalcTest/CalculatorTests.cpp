#include "pch.h"

TEST(Plus_minus_tests, Positive_expession) {
	Calculator calc;
	Token_stream it;
	
	EXPECT_EQ(calc.calculate(str_stream), 9);
  EXPECT_TRUE(true);
}
TEST(Plus_minus_tests, Negative_expession) {

	EXPECT_TRUE(true);
}
TEST(Multy_division_tests, Positive_expession) {
	
	EXPECT_TRUE(true);
}
TEST(Multy_division_tests, Negative_expession) {
	
	EXPECT_TRUE(true);
}
TEST(Different_signs, Plus_minus_multy) {
	
	EXPECT_TRUE(true);
}
TEST(Different_signs, Plus_minus_division) {
	
	EXPECT_TRUE(true);
}
TEST(Different_signs, Expressions_with_brackets) {
	
	EXPECT_TRUE(true);
}


