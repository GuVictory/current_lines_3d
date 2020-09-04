//
// Created by Виктория Губанова on 01.09.2020.
//

#include <gtest/gtest.h>
#include <Point.h>

#include <iostream>

void setCoords(double newX, double newY, double newZ = 0);

//our first unit test
TEST(IntegerInputsSuite, simpleSetCoords)
{
    auto* p1 = new Point(1, 1, 1);
    auto* p2 = new Point(2, 1, 0);

    p1->setCoords(2, 1);
    EXPECT_EQ(*p1, *p2) << "Points have different coords";
}