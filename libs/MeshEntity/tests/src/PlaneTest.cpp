//
// Created by Виктория Губанова on 04.09.2020.
//

#include <gtest/gtest.h>
#include <Plane.h>

#include <iostream>

TEST(PlaneTest, foundPlaneTypeYZ)
{
    auto* n1 = new Node(0.0, 1.2, 2);
    auto* n2 = new Node(0.0, 2, 1);
    auto* n3 = new Node(0.0, 2, 2);
    auto* n4 = new Node(0.0, 1.2, 1);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::YZ) << "PlaneType YZ isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeXY)
{
    auto* n1 = new Node(2.0, 2, 0);
    auto* n2 = new Node(1.0, 2, 0);
    auto* n3 = new Node(1.0, 1.2, 0);
    auto* n4 = new Node(2.0, 1.2, 0);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::XY) << "PlaneType XY isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeXZ)
{
    auto* n1 = new Node(1.2, 2, 2);
    auto* n2 = new Node(2.0, 2, 1);
    auto* n3 = new Node(2.0, 2, 2);
    auto* n4 = new Node(1.2, 2, 1);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::XZ) << "PlaneType XZ isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeERR)
{
    auto* n1 = new Node(1.2, 2, 2);
    auto* n2 = new Node(2.0, 2.2, 1);
    auto* n3 = new Node(2.0, 2, 1);
    auto* n4 = new Node(1.2, 12.9, 2);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::ERR) << "PlaneType ERR isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeSAME_POINTS)
{
    auto* n1 = new Node(1.2, 2, 2);
    auto* n2 = new Node(1.2, 2, 2);
    auto* n3 = new Node(2.0, 2, 1);
    auto* n4 = new Node(1.2, 2, 1);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::SAME_POINTS) << "PlaneType SAME_POINTS isn\'t correct";
}

TEST(PlaneTest, suitsPlanesTest1)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 0.0, 0.0);
    auto* n3 = new Node(1.0, 0.0, 1.0);
    auto* n4 = new Node(0.0, 0.0, 1.0);

    auto* n5 = new Node(0.0, 0.0, 0.0);
    auto* n6 = new Node(0.0, 1.0, 0.0);
    auto* n7 = new Node(1.0, 1.0, 0.0);
    auto* n8 = new Node(1.0, 0.0, 0.0);

    auto* p1 = new Plane(*n1, *n2, *n3, *n4);
    auto* p2 = new Plane(*n5, *n6, *n7, *n8);
    EXPECT_TRUE(p1->areSuitsPlane(*p2)) << "areSuitsPlane1 not working";
}


TEST(PlaneTest, suitsPlanesTest2)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 0.0, 0.0);
    auto* n3 = new Node(1.0, 0.0, 1.0);
    auto* n4 = new Node(0.0, 0.0, 1.0);

    auto* n5 = new Node(0.0, 0.0, 1.0);
    auto* n6 = new Node(0.0, 1.0, 1.0);
    auto* n7 = new Node(1.0, 1.0, 1.0);
    auto* n8 = new Node(1.0, 0.0, 1.0);

    auto* p1 = new Plane(*n1, *n2, *n3, *n4);
    auto* p2 = new Plane(*n5, *n6, *n7, *n8);
    EXPECT_TRUE(p1->areSuitsPlane(*p2)) << "areSuitsPlane2 not working";
}

TEST(PlaneTest, suitsPlanesTest3)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 0.0, 0.0);
    auto* n3 = new Node(1.0, 0.0, 1.0);
    auto* n4 = new Node(0.0, 0.0, 1.0);

    auto* n5 = new Node(1.0, 0.0, 1.0);
    auto* n6 = new Node(1.0, 1.0, 1.0);
    auto* n7 = new Node(1.0, 0.0, 0.0);
    auto* n8 = new Node(1.0, 1.0, 0.0);

    auto* p1 = new Plane(*n1, *n2, *n3, *n4);
    auto* p2 = new Plane(*n5, *n6, *n7, *n8);
    EXPECT_TRUE(p1->areSuitsPlane(*p2)) << "areSuitsPlane3 not working";
}

TEST(PlaneTest, suitsPlanesTest4)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 0.0, 0.0);
    auto* n3 = new Node(1.0, 0.0, 1.0);
    auto* n4 = new Node(0.0, 0.0, 1.0);

    auto* n5 = new Node(0.0, 0.0, 0.0);
    auto* n6 = new Node(0.0, 0.0, 1.0);
    auto* n7 = new Node(0.0, 1.0, 0.0);
    auto* n8 = new Node(0.0, 1.0, 1.0);

    auto* p1 = new Plane(*n1, *n2, *n3, *n4);
    auto* p2 = new Plane(*n5, *n6, *n7, *n8);
    EXPECT_TRUE(p1->areSuitsPlane(*p2)) << "areSuitsPlane4 not working";
}

TEST(PlaneTest, suitsPlanesTest5)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 0.0, 0.0);
    auto* n3 = new Node(1.0, 0.0, 1.0);
    auto* n4 = new Node(0.0, 0.0, 1.0);

    auto* n5 = new Node(0.0, 1.0, 0.0);
    auto* n6 = new Node(0.0, 1.0, 1.0);
    auto* n7 = new Node(1.0, 1.0, 0.0);
    auto* n8 = new Node(1.0, 1.0, 1.0);

    auto* p1 = new Plane(*n1, *n2, *n3, *n4);
    auto* p2 = new Plane(*n5, *n6, *n7, *n8);
    EXPECT_FALSE(p1->areSuitsPlane(*p2)) << "areSuitsPlane5 not working";
}

TEST(PlaneTest, getPlaneIntersectionsYZ)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(0.0, 0.0, 2.0);
    auto* n3 = new Node(0.0, 2.0, 2.0);
    auto* n4 = new Node(0.0, 2.0, 0.0);

    auto* p = new Plane(*n1, *n2, *n3, *n4);

    auto* point = new Point(0.0, 1.0, 1.0);
    auto* expected = new PlaneIntersections(
            *new Point(),
            *new Point(),
            *new Point(0.0, 0.0, 1.0),
            *new Point(0.0, 2.0, 1.0),
            *new Point(0.0, 1.0, 0.0),
            *new Point(0.0, 1.0, 2.0));
    auto* result = p->getPlaneIntersections(*point).second;

    EXPECT_EQ(*expected, *result) << "getPlaneIntersectionsYZ isn\'t correct";
}

TEST(PlaneTest, getPlaneIntersectionsXY)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(0.0, 2.0, 0.0);
    auto* n3 = new Node(2.0, 2.0, 0.0);
    auto* n4 = new Node(2.0, 0.0, 0.0);

    auto* p = new Plane(*n1, *n2, *n3, *n4);

    auto* point = new Point(1.0, 1.0, 0.0);

    auto* expected = new PlaneIntersections(
            *new Point(0.0, 1.0, 0.0),
            *new Point(2.0, 1.0, 0.0),
            *new Point(1.0, 0.0, 0.0),
            *new Point(1.0, 2.0, 0.0),
            *new Point(),
            *new Point());
    auto* result = p->getPlaneIntersections(*point).second;

    EXPECT_EQ(*expected, *result) << "getPlaneIntersectionsXY isn\'t correct";
}

TEST(PlaneTest, getPlaneIntersectionsXZ)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(2.0, 0.0, 0.0);
    auto* n3 = new Node(2.0, 0.0, 2.0);
    auto* n4 = new Node(0.0, 0.0, 2.0);

    auto* p = new Plane(*n1, *n2, *n3, *n4);

    auto* point = new Point(1.0, 0.0, 1.0);

    auto* expected = new PlaneIntersections(
            *new Point(0.0, 0.0, 1.0),
            *new Point(2.0, 0.0, 1.0),
            *new Point(),
            *new Point(),
            *new Point(1.0, 0.0, 0.0),
            *new Point(1.0, 0.0, 2.0));
    auto* result = p->getPlaneIntersections(*point).second;

    EXPECT_EQ(*expected, *result) << "getPlaneIntersectionsXZ isn\'t correct";
}