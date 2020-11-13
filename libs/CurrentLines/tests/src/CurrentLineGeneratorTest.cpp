//
// Created by Виктория Губанова on 01.09.2020.
//
#include <gtest/gtest.h>

#include "MeshLoader.h"
#include "MeshUnloading.h"
#include "Mesh.h"
#include "CurrentLineGenerator.h"


TEST(CurrentLineGenerator, localizationTest)
{
auto* meshLoader = new MeshLoader("nodes_small.dat",
                            "hexahedrons_small.dat");


auto* mesh = new Mesh();

std::vector<Node> nodes;
nodes = meshLoader->loadNodes();

std::vector<std::tuple<long, long, long, long, long, long, long, long, long>> cells;
cells = meshLoader->loadCells();

for(auto & node : nodes) {
    mesh->loadNode(node);
}

for(auto & cell : cells) {
    mesh->loadCell(std::get<0>(cell),
                   std::get<1>(cell),
                   std::get<2>(cell),
                   std::get<3>(cell),
                   std::get<4>(cell),
                   std::get<5>(cell),
                   std::get<6>(cell),
                   std::get<7>(cell),
                   std::get<8>(cell));
}

auto * clGen = new CurrentLineGenerator(*mesh, *new Point(0.01, 0.01, 0.01));

EXPECT_EQ(clGen->localization(), 6) << "CurrentLineGenerator localizationTest not working";
}

TEST(CurrentLineGenerator, localizationTest2)
{
    auto* meshLoader = new MeshLoader("nodes_small.dat",
                                      "hexahedrons_small.dat");


    auto* mesh = new Mesh();

    std::vector<Node> nodes;
    nodes = meshLoader->loadNodes();

    std::vector<std::tuple<long, long, long, long, long, long, long, long, long>> cells;
    cells = meshLoader->loadCells();

    for(auto & node : nodes) {
        mesh->loadNode(node);
    }

    for(auto & cell : cells) {
        mesh->loadCell(std::get<0>(cell),
                       std::get<1>(cell),
                       std::get<2>(cell),
                       std::get<3>(cell),
                       std::get<4>(cell),
                       std::get<5>(cell),
                       std::get<6>(cell),
                       std::get<7>(cell),
                       std::get<8>(cell));
    }

    auto * clGen = new CurrentLineGenerator(*mesh, *new Point(2.01, 0.01, 0.01));

    EXPECT_EQ(clGen->localization(), -1) << "CurrentLineGenerator localizationTest2 not working";
}

TEST(CurrentLineGenerator, currentLineGenerationTest)
{
    auto* meshLoader = new MeshLoader("nodes.dat",
                                      "hexahedrons.dat");


    auto* mesh = new Mesh();

    std::vector<Node> nodes;
    nodes = meshLoader->loadNodes();

    std::vector<std::tuple<long, long, long, long, long, long, long, long, long>> cells;
    cells = meshLoader->loadCells();

    for(auto & node : nodes) {
        mesh->loadNode(node);
    }

    for(auto & cell : cells) {
        mesh->loadCell(std::get<0>(cell),
                       std::get<1>(cell),
                       std::get<2>(cell),
                       std::get<3>(cell),
                       std::get<4>(cell),
                       std::get<5>(cell),
                       std::get<6>(cell),
                       std::get<7>(cell),
                       std::get<8>(cell));
    }

    auto * clGen = new CurrentLineGenerator(*mesh, *new Point(0.0, 0.0, 0.0));

    clGen->generateCurrentLine();

    auto* meshUnloader = new MeshUnloading("currentLine.dat");

    meshUnloader->unloadCurrentLine(clGen->getCurrentLine()->getCurentLineNodes());
}