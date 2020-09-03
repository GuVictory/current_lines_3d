//
// Created by Виктория Губанова on 01.09.2020.
//

#include <gtest/gtest.h>
#include <Node.h>

#include <iostream>

TEST(DifferentConstructorTest, simpleContructors)
{
    auto* n1 = new Node();
    auto* n2 = new Node(*(new Point()));
    EXPECT_EQ(*n1, *n2) << "Nodes have different points";
}