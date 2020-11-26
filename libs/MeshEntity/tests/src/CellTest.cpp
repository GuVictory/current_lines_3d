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

    auto exp = cell->getBackPlane();

    EXPECT_EQ(*p, exp) << "Back cell field isn\'t correct";
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

    auto res = cell->getRightPlane();

    EXPECT_EQ(*p, res) << "Right cell field isn\'t correct";
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

    auto exp = cell->getLeftPlane();
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

TEST(CellTest, containsPointTrue)
{
    auto* p = new Point(0.5, 0.5, 0.5);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_TRUE(cell->containsPoint(*p)) << "Cell contains point not working!";
}

TEST(CellTest, containsPointTrue2)
{
    auto* p = new Point(1.0, 0.5, 0.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_TRUE(cell->containsPoint(*p)) << "Cell contains point not working!";
}

TEST(CellTest, containsPointFalse)
{
    auto* p = new Point(1.1, 0.5, 0.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(1.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 1.0),
                          *new Node(1.0, 0.0, 1.0),
                          *new Node(0.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 0.0),
                          *new Node(1.0, 1.0, 1.0),
                          *new Node(0.0, 1.0, 1.0));

    EXPECT_FALSE(cell->containsPoint(*p)) << "Cell contains point not working!";
}

TEST(CellTest, getIntersectionWithRightEdgeTest)
{
    auto* p = new Point(1.0, 1.0, 1.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(2.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 2.0),
                          *new Node(2.0, 0.0, 2.0),
                          *new Node(0.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 2.0),
                          *new Node(0.0, 2.0, 2.0));

    auto* expectedPoint = new Point(2.0, 1.0,1.0);
    EXPECT_EQ(*expectedPoint, cell->getIntersectionWithRightEdge(*p)) << "Cell getIntersectionWithRightEdgeTest not working!";
}

TEST(CellTest, getIntersectionWithLeftEdgeTest)
{
    auto* p = new Point(1.0, 1.0, 1.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(2.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 2.0),
                          *new Node(2.0, 0.0, 2.0),
                          *new Node(0.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 2.0),
                          *new Node(0.0, 2.0, 2.0));

    auto* expectedPoint = new Point(0.0, 1.0,1.0);
    EXPECT_EQ(*expectedPoint, cell->getIntersectionWithLeftEdge(*p)) << "Cell getIntersectionWithLeftEdgeTest not working!";
}

TEST(CellTest, getIntersectionWithTopEdgeTest)
{
    auto* p = new Point(1.0, 1.0, 1.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(2.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 2.0),
                          *new Node(2.0, 0.0, 2.0),
                          *new Node(0.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 2.0),
                          *new Node(0.0, 2.0, 2.0));

    auto* expectedPoint = new Point(1.0, 1.0,2.0);
    EXPECT_EQ(*expectedPoint, cell->getIntersectionWithTopEdge(*p)) << "Cell getIntersectionWithTopEdgeTest not working!";
}

TEST(CellTest, getIntersectionWithBottomEdgeTest)
{
    auto* p = new Point(1.0, 1.0, 1.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(2.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 2.0),
                          *new Node(2.0, 0.0, 2.0),
                          *new Node(0.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 2.0),
                          *new Node(0.0, 2.0, 2.0));

    auto* expectedPoint = new Point(1.0, 1.0,0.0);
    EXPECT_EQ(*expectedPoint, cell->getIntersectionWithBottomEdge(*p)) << "Cell getIntersectionWithBottomEdgeTest not working!";
}

TEST(CellTest, getIntersectionWithFrontEdgeTest)
{
    auto* p = new Point(1.0, 1.0, 1.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(2.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 2.0),
                          *new Node(2.0, 0.0, 2.0),
                          *new Node(0.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 2.0),
                          *new Node(0.0, 2.0, 2.0));

    auto* expectedPoint = new Point(1.0, 0.0,1.0);
    EXPECT_EQ(*expectedPoint, cell->getIntersectionWithFrontEdge(*p)) << "Cell getIntersectionWithFrontEdgeTest not working!";
}

TEST(CellTest, getIntersectionWithBackEdgeTest)
{
    auto* p = new Point(1.0, 1.0, 1.0);

    auto* cell = new Cell(*new Node(0.0, 0.0, 0.0),
                          *new Node(2.0, 0.0, 0.0),
                          *new Node(0.0, 0.0, 2.0),
                          *new Node(2.0, 0.0, 2.0),
                          *new Node(0.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 0.0),
                          *new Node(2.0, 2.0, 2.0),
                          *new Node(0.0, 2.0, 2.0));

    auto* expectedPoint = new Point(1.0, 2.0,1.0);
    EXPECT_EQ(*expectedPoint, cell->getIntersectionWithBackEdge(*p)) << "Cell getIntersectionWithBackEdgeTest not working!";
}