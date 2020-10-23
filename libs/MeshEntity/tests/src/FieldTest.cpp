//
// Created by Виктория Губанова on 01.09.2020.
//

#include <gtest/gtest.h>
#include <Node.h>

#include <iostream>

TEST(FieldTest, simpleFieldGeneration)
{
    auto* n1 = new Node();
    auto* n2 = new Node(*(new Point()));

    auto f1 = n1->getField();
    auto f2 = n2->getField();

    EXPECT_EQ(f1.getVectorField(), f2.getVectorField()) << "Fields of nodes isn\'t the same";
}

TEST(FieldTest, getFieldSize)
{
    auto* n = new Node(4.0, 0.0, 3.0);
    auto f = n->getField();
    EXPECT_EQ(f.getSizeOfVectorField(), 5.0) << "Field size isn\'t correct";
}

TEST(FieldTest, getVectorFieldTest)
{
    auto* n = new Node(1.0, 2.0, 3.0);
    auto* f = new Field(n->getPoint());
    EXPECT_EQ(f->getVectorField(), *new Point(1.0, 2.0, 3.0)) << "Field vector isn\'t correct";
}

TEST(FieldTest, getNormalizeVectorFieldTest)
{
    auto* n = new Node(3.0, 4.0, 0.0);
    auto* f = new Field(n->getPoint());
    EXPECT_EQ(f->getNormalizeVectorField(), *new Point(3.0 / 5.0, 4.0 / 5.0, 0))
                << "Field normalize vector isn\'t correct";
}