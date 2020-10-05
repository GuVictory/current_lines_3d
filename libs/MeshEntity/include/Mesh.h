//
// Created by Виктория Губанова on 11.09.2020.
//

#ifndef CURRENTLINES3D_MESH_H
#define CURRENTLINES3D_MESH_H

#include <vector>
#include <map>
#include <list>
#include <iostream>
#include <Cell.h>
#include <MeshType.h>

class Mesh {
private:
    std::map<unsigned int, Node*> nodes;
    std::vector<Cell*> cells;
    std::list<std::vector<Plane>> planesBasket;

    MeshType meshType;

    void addToPlanesBasket(const Plane& plane);
public:
    Mesh();
    ~Mesh();

    unsigned int numberOfNodes();
    unsigned int numberOfCells();
    unsigned int sizeOfPlaneBasket();

    void loadNode(Node& node);
    std::pair<bool, Node*> getNode(unsigned int nodeId);
    bool changeFieldOfNode(unsigned int nodeId, const Field& field);

    void loadPlane(unsigned int id1, unsigned int id2, unsigned int id3, unsigned int id4);
};


#endif //CURRENTLINES3D_MESH_H
