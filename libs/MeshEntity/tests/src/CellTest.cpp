#include <gtest/gtest.h>
#include <Cell.h>

#include <iostream>

TEST(CellTest, getFrontPlaneTest)
{
    auto* p = new Plane(*new Node(0.0, 0.0, 0.0),
                        *new Node(1.0, 0.0, 0.0),
                        *new Node(0.0, 0.0, 1.0),
                        *new Node(1.0, 0.0, 1.0));

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_EQ(*p, cell->getFrontPlane()) << "Front cell field isn\'t correct";
}

TEST(CellTest, getBackPlaneTest)
{
    auto* p = new Plane(*new Node(0.0, 1.0, 0.0),
                        *new Node(1.0, 1.0, 1.0),
                        *new Node(0.0, 1.0, 1.0),
                        *new Node(1.0, 1.0, 0.0));

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_EQ(*p, cell->getBackPlane()) << "Back cell field isn\'t correct";
}

TEST(CellTest, getRightPlaneTest)
{
    auto* p = new Plane(*new Node(1.0, 0.0, 0.0),
                        *new Node(1.0, 0.0, 1.0),
                        *new Node(1.0, 1.0, 1.0),
                        *new Node(1.0, 1.0, 0.0));

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_EQ(*p, cell->getRightPlane()) << "Right cell field isn\'t correct";
}

TEST(CellTest, getLeftPlaneTest)
{
    auto* p = new Plane(*new Node(0.0, 0.0, 1.0),
                        *new Node(0.0, 1.0, 1.0),
                        *new Node(0.0, 0.0, 0.0),
                        *new Node(0.0, 1.0, 0.0));

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_EQ(*p, cell->getLeftPlane()) << "Left cell field isn\'t correct";
}

TEST(CellTest, getTopPlaneTest)
{
    auto* p = new Plane(*new Node(0.0, 0.0, 1.0),
                        *new Node(1.0, 0.0, 1.0),
                        *new Node(1.0, 1.0, 1.0),
                        *new Node(0.0, 1.0, 1.0));

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_EQ(*p, cell->getTopPlane()) << "Top cell field isn\'t correct";
}

TEST(CellTest, getBottomPlaneTest)
{
    auto* p = new Plane(*new Node(0.0, 0.0, 0.0),
                        *new Node(0.0, 1.0, 0.0),
                        *new Node(1.0, 1.0, 0.0),
                        *new Node(1.0, 0.0, 0.0));

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_EQ(*p, cell->getBottomPlane()) << "Bottom cell field isn\'t correct";
}