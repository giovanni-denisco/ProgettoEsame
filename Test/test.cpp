
#include <gtest/gtest.h>
#include "../functions.h"


TEST(SampleTest, TrueIsTrue) {
    EXPECT_TRUE(true);
}

//Prova fattoriale di 0

TEST(FactorialTest, HandlesZeroInput) {
    EXPECT_EQ(1, Factorial(0));
}

//Prove fattoriale con alcuni numeri positivi

TEST(FactorialTest, PositiveNumber3) {
    EXPECT_EQ(6, Factorial(3));
}

TEST(FactorialTest, PositiveNumber5) {
    EXPECT_EQ(120, Factorial(5));
}

TEST(FactorialTest, PositiveNumber6) {
    EXPECT_EQ(720, Factorial(6));
}