//
// Created by Виктория Губанова on 11.09.2020.
//

#include "Mesh.h"

Mesh::Mesh() : meshType(MeshType::D2) {}

Mesh::~Mesh() {
    for ( auto [key, node] : this->nodes ) {
        delete node;
    }
    for ( auto cell : this->cells ) {
        delete cell;
    }
}

unsigned int Mesh::numberOfNodes() {
    return this->nodes.size();
}

unsigned int Mesh::numberOfCells() {
    return this->cells.size();
}

void Mesh::addNode(Node &node) {
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
