//
// Created by Виктория Губанова on 03.09.2020.
//

#include <gtest/gtest.h>
#include <Line.hpp>
#include <cmath>

#include <iostream>

TEST(LineTest, simpleLineGeneration)
{
    auto* n1 = new Node();
    auto* n2 = new Node();

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line();

    EXPECT_EQ(*l1, *l2) << "Lines isn\'t the same";
}

TEST(LineTest, lineLen)
{
    auto* n1 = new Node(1.0, 3.0);
    auto* n2 = new Node(2.0, 5.0);

    auto* l = new Line(*n1, *n2);

    std::cout << *l;
    EXPECT_EQ(l->len(), sqrt(5)) << "Lines isn\'t the same";
}