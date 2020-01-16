#include "math.h"
#include <gtest/gtest.h>

TEST(MathTest, testAddition)
{
    Math math;

    int expectedResult = 100;
    int actualResult = math.add(70, 30);

    EXPECT_EQ(expectedResult, actualResult);
}
