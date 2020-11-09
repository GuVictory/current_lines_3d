//
// Created by Виктория Губанова on 11.09.2020.
//

#include "Mesh.h"

Mesh::Mesh() : meshType(MeshType::D2) {}

Mesh::~Mesh() {
    this->nodes.clear();
    this->cells.clear();
}

unsigned int Mesh::numberOfNodes() const {
    return this->nodes.size();
}

unsigned int Mesh::numberOfCells() const {
    return this->cells.size();
}

void Mesh::loadNode(Node &node) {
    auto [iter, success] = this->nodes.try_emplace(node.getId(), &node);

    // В случае добавления узла с координатой Z переключаем тип сетки на 3D
    if (this->meshType == MeshType::D2 && iter->second->getPoint().getZ() != 0) {
        this->meshType = MeshType::D3;
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

bool
Mesh::loadCell(int cellId, int nodeId1, int nodeId2, int nodeId3, int nodeId4, int nodeId5, int nodeId6, int nodeId7, int nodeId8) {

    std::pair<bool, Node*> node1 = this->getNode(nodeId1);
    std::pair<bool, Node*> node2 = this->getNode(nodeId2);
    std::pair<bool, Node*> node3 = this->getNode(nodeId3);
    std::pair<bool, Node*> node4 = this->getNode(nodeId4);
    std::pair<bool, Node*> node5 = this->getNode(nodeId5);
    std::pair<bool, Node*> node6 = this->getNode(nodeId6);
    std::pair<bool, Node*> node7 = this->getNode(nodeId7);
    std::pair<bool, Node*> node8 = this->getNode(nodeId8);

    if (!node1.first || !node2.first ||
        !node3.first || !node4.first ||
        !node5.first || !node6.first ||
        !node7.first || !node8.first) {
        return false;
    }

    Cell* newCell = new Cell(*node1.second,
                             *node2.second,
                             *node3.second,
                             *node4.second,
                             *node5.second,
                             *node6.second,
                             *node7.second,
                             *node8.second,
                             cellId);

    this->cells.push_back(*newCell);

    return false;
}
