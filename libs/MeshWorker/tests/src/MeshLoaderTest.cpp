//
// Created by Виктория Губанова on 08.11.2020.
//

#include <gtest/gtest.h>
#include "MeshLoader.h"
#include <fstream>

TEST(MeshLoaderTest, loadNodesTest)
{
    auto* mesh = new MeshLoader("nodes.dat",
                                "hexahedrons.dat");

    std::vector<Node> result;

    result = mesh->loadNodes();

    EXPECT_EQ(result.size(), 95728) << "MeshLoader loadNodes not working";
}

TEST(MeshLoaderTest, loadNodesTest2)
{
    auto* mesh = new MeshLoader("nodes.dat",
                                "hexahedrons.dat");

    std::vector<Node> result;

    result = mesh->loadNodes();

    // 0 0.0 0.0 -0.9 0.0 0.0 1.0

    EXPECT_EQ(result[0].getId(), 0);
    EXPECT_EQ(result[0].getPoint().getX(), 0.0);
    EXPECT_EQ(result[0].getPoint().getY(), 0.0);
    EXPECT_EQ(result[0].getPoint().getZ(), -0.9);
    EXPECT_EQ(result[0].getField().getX(), 0.0);
    EXPECT_EQ(result[0].getField().getY(), 0.0);
    EXPECT_EQ(result[0].getField().getZ(), 1.0);
}

TEST(MeshLoaderTest, loadCellsTest)
{
    auto* mesh = new MeshLoader("nodes.dat",
                                "hexahedrons.dat");

    std::vector<Node> nodeResult;
    nodeResult = mesh->loadNodes();

    std::vector<Cell> result;

    result = mesh->loadCells(nodeResult);

    EXPECT_EQ(result.size(), 95728) << "MeshLoader loadCellsTest not working";
}

TEST(MeshLoaderTest, loadCellsTest2)
{
    auto* mesh = new MeshLoader("nodes.dat",
                                "hexahedrons.dat");

    std::vector<Node> nodeResult;
    nodeResult = mesh->loadNodes();

    std::vector<Cell> result;
    result = mesh->loadCells(nodeResult);

    // 0 88202 0 2793 91367 89555 1029 1911 90461

    Cell* testCell = new Cell(nodeResult[88202],
                              nodeResult[0],
                              nodeResult[2793],
                              nodeResult[91367],
                              nodeResult[89555],
                              nodeResult[1029],
                              nodeResult[1911],
                              nodeResult[90461],
                              0);

    EXPECT_EQ(result[0], *testCell) << "MeshLoader loadCellsTest2 not working";
}