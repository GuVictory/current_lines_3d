//
// Created by Виктория Губанова on 01.09.2020.
//

#include <gtest/gtest.h>
#include <Node.hpp>

#include <iostream>

TEST(FieldTest, simpleFieldGeneration)
{
    auto* n1 = new Node();
    auto* n2 = new Node(*(new Point()));

    auto f1 = n1->getField();
    auto f2 = n2->getField();

    EXPECT_EQ(f1.getVectorField(), f2.getVectorField()) << "Fields of nodes isn\'t the same";
}

TEST(FieldTest, simpleFieldSize)
{
    auto* n = new Node(4.0, 0.0, 3.0);
    auto f = n->getField();
    EXPECT_EQ(f.getSizeOfVectorField(), 5.0) << "Field size isn\'t correct";
}