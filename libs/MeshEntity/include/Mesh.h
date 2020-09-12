//
// Created by Виктория Губанова on 11.09.2020.
//

#ifndef CURRENTLINES3D_MESH_H
#define CURRENTLINES3D_MESH_H

#include <vector>
#include <map>
#include <iostream>
#include <Cell.h>
#include <MeshType.h>

class Mesh {
private:
    std::map<unsigned int, Node*> nodes;
    std::vector<Cell*> cells;

    MeshType meshType;

public:
    Mesh();
    ~Mesh();

    unsigned int numberOfNodes();
    unsigned int numberOfCells();

    void addNode(Node& node);
    std::pair<bool, Node*> getNode(unsigned int nodeId);
    bool changeFieldOfNode(unsigned int nodeId, const Field& field);

};


#endif //CURRENTLINES3D_MESH_H
