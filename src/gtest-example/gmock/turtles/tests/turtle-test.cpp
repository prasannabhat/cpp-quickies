#include "mock-turtle.hpp"
#include "painter.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::AtLeast; // #1

TEST(PainterTest, CanDrawSomething)
{
    MockTurtle turtle;             // #2
    EXPECT_CALL(turtle, PenDown()) // #3
        .Times(AtLeast(1));

    Painter painter(turtle); // #4

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10)); // #5
}