#include "pch.h"

Calculator calc;
Token t;

TEST(Plus_minus_tests, Positive_expession) {
    t.value = 5 + 5;
    EXPECT_EQ(calc.calculate(t), 9);
	EXPECT_TRUE(true);
}
TEST(Plus_minus_tests, Negative_expession) {
	t.value = -2 + 4;
	EXPECT_EQ(calc.calculate(t), 2);
	EXPECT_TRUE(true);
}
TEST(Multy_division_tests, Positive_expession) {
	t.value = 2/4;
	EXPECT_EQ(calc.calculate(t), 0.5);
	EXPECT_TRUE(true);
}
TEST(Multy_division_tests, Negative_expession) {
	t.value = -2 * 4;
	EXPECT_EQ(calc.calculate(t), -8);
	EXPECT_TRUE(true);
}
TEST(Different_signs, Plus_minus_multy) {
	t.value = -2 * 4 + 5;
	EXPECT_EQ(calc.calculate(t), -3);
	EXPECT_TRUE(true);
}
TEST(Different_signs, Plus_minus_division) {
	t.value = -2 / 4 - 3;
	EXPECT_EQ(calc.calculate(t), -3.5);
	EXPECT_TRUE(true);
}
TEST(Different_signs, Expressions_with_brackets) {
	t.value = (-2 + 4)*3;
	EXPECT_EQ(calc.calculate(t), 6);
	EXPECT_TRUE(true);
}
