//#include "../stdafx.h"
#include "gtest/gtest.h"
#include "Calculator.h"
#include "Token.h"
#include "Token_stream.h"
testing::UnitTest;
TEST(CalculatorTest, Zhopa1) {
	Token_stream tss;
	Token t = tss.get();
	t = 2 - 1;
	Calculator its;
	double res = its.expression(t);
	EXPECT_EQ(1, res);
  EXPECT_TRUE(true);
}
int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}