#include "pch.h"
#include "../Calculator/Calculator.h"

TEST(Plus_minus_tests, Positive_expession) {
  EXPECT_EQ(12-3, 9);
  EXPECT_EQ(100000-9999 , 90001);
  EXPECT_EQ(100-100, 0);
  EXPECT_EQ(100-(-10), 110);
  EXPECT_EQ(100 + (-10), 90);
  EXPECT_EQ(34.5-25.2, 9.3);
  EXPECT_TRUE(true);
}
TEST(Plus_minus_tests, Negative_expession) {
	EXPECT_EQ(-12-3, -15);
	EXPECT_EQ(-10+(-20), -30);
	EXPECT_EQ(-10+10, 0);
	EXPECT_EQ(-20-(-10), -10);   
	EXPECT_EQ(34.5 - 35, -0.5);
	EXPECT_TRUE(true);
}
TEST(Multy_division_tests, Positive_expession) {
	EXPECT_EQ(12*3, 36);
	EXPECT_EQ(-10*(-20), 200);
	EXPECT_EQ(10*0, 0);
	EXPECT_EQ(2*3*(-4)*(-5), 120);
	EXPECT_EQ(0.5 * 2.5, 1.25);
	EXPECT_TRUE(true);
}
TEST(Multy_division_tests, Negative_expession) {
	EXPECT_EQ(-12*3, -36);
	EXPECT_EQ(10*(-20), -200);
	EXPECT_EQ(-10*0, 0);
	EXPECT_EQ(-3*2*(-3)*(-2), -36);
	EXPECT_EQ(4 / 0.5, 8);
	EXPECT_GT(9.87 / 2.3, 4.29);
	EXPECT_TRUE(true);
}
TEST(Different_signs, Plus_minus_multy) {
	EXPECT_EQ(3*4+3, 15);
	EXPECT_EQ(10 * (-20)+2, -198);
	EXPECT_EQ(-10 * 0 +9, 9);
	EXPECT_EQ(-3 * 2 * (-3) * (-2)+7, -29);
	EXPECT_GT(9.87 / 2.3 + 23, 27.29);
	EXPECT_TRUE(true);
}
TEST(Different_signs, Plus_minus_division) {
	EXPECT_EQ(3.0 / 4, 0.75);
	EXPECT_EQ(10 / (-20) + 2, 2);
	EXPECT_EQ(-3.0 / 2 /(-3) + 7, 7.5);
	EXPECT_TRUE(true);
}
TEST(Different_signs, Expressions_with_brackets) {
	EXPECT_EQ((2-3)*3, -3);
	EXPECT_GT(10/(5.2-3.7), 6.6);
	EXPECT_EQ(-3/(2-3), 3);
	EXPECT_EQ((3-2*3-4)/2.8, -2.5);
	EXPECT_TRUE(true);
}


