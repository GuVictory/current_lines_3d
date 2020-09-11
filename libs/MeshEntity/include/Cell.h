//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_CELL_H
#define CURRENTLINES3D_CELL_H

#include <Plane.h>
#include <EdgeValues.h>
#include <CellFaces.h>

#include <vector>

class Cell {

private:
    unsigned int id;
    std::vector<Node*> nodes;

    EdgeValues getXEdgeValues();
    EdgeValues getYEdgeValues();
    EdgeValues getZEdgeValues();

    Plane& getSuitablePlane(CellFaces face, double coord);

public:
    Cell();
    Cell(Node& n1,
         Node& n2,
         Node& n3,
         Node& n4,
         Node& n5,
         Node& n6,
         Node& n7,
         Node& n8,
         unsigned int id = 0);
    ~Cell();

    Plane& getFrontPlane();
    Plane& getRightPlane();
    Plane& getBackPlane();
    Plane& getLeftPlane();
    Plane& getTopPlane();
    Plane& getBottomPlane();

    bool operator==(const Cell& cell);
};


#endif //CURRENTLINES3D_CELL_H
