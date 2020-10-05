//
// Created by Виктория Губанова on 11.09.2020.
//

#include "Mesh.h"

Mesh::Mesh() : meshType(MeshType::D2) {}

Mesh::~Mesh() {
    this->nodes.clear();
    this->cells.clear();
    this->planesBasket.clear();
}

unsigned int Mesh::numberOfNodes() {
    return this->nodes.size();
}

unsigned int Mesh::numberOfCells() {
    return this->cells.size();
}

void Mesh::loadNode(Node &node) {
    auto [iter, success] = this->nodes.try_emplace(node.getId(), &node);

    // В случае добавления узла с координатой Z переключаем тип сетки на 3D
    if (this->meshType == MeshType::D2 && iter->second->getPoint().getZ() != 0) {
        this->meshType =MeshType::D3;
    }

    if ( !success ) {
        std::cout << "[MESH ERROR]: trying to add nodes with same id" << std::endl;
    }
}

bool Mesh::changeFieldOfNode(unsigned int nodeId, const Field &field) {
    auto [success, node] = this->getNode(nodeId);

    if (success) {
        node->getField().setCoords(field.getX(), field.getY(), field.getZ());
        return true;
    } else {
        std::cout << "[MESH ERROR]: node with id " << nodeId << " not found" << std::endl;
    }
    return false;
}

std::pair<bool, Node*> Mesh::getNode(unsigned int nodeId) {
    auto iter = this->nodes.find(nodeId);
    if (iter != this->nodes.end()) {
        return std::pair<bool, Node*> (true, iter->second);
    } else {
        return std::pair<bool, Node*> (false, nullptr);
    }
}

void Mesh::addToPlanesBasket(const Plane &plane) {
    bool wasFoundedSuitsPlanes = false;
    for ( auto planesVector : this->planesBasket ) {
        for ( int i = 0; i < planesVector.size(); ++i ) {
            if ( planesVector.at(i).areSuitsPlane(plane) ) {
                planesVector.push_back(plane);
                wasFoundedSuitsPlanes = true;
                break;
            }
        }
    }
    if ( !wasFoundedSuitsPlanes ) {
        std::vector<Plane> newPlanesVec;
        newPlanesVec.push_back(plane);
        this->planesBasket.push_back(newPlanesVec);
    }
}

void Mesh::loadPlane(unsigned int id1, unsigned int id2, unsigned int id3, unsigned int id4) {
    auto [success1, n1] = this->getNode(id1);
    auto [success2, n2] = this->getNode(id2);
    auto [success3, n3] = this->getNode(id3);
    auto [success4, n4] = this->getNode(id4);

    auto *plane = new Plane(*n1, *n2, *n3, *n4);
    this->addToPlanesBasket(*plane);
}

unsigned int Mesh::sizeOfPlaneBasket() {
    return this->planesBasket.size();
}
