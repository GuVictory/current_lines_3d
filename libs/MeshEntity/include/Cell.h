//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_CELL_H
#define CURRENTLINES3D_CELL_H

#include <Node.h>
#include <vector>

class Cell {

private:
    unsigned int id;
    std::vector<Node*> nodes;

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

    bool operator==(const Cell& cell);
};


#endif //CURRENTLINES3D_CELL_H
