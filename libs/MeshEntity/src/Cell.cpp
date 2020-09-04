//
// Created by Виктория Губанова on 03.09.2020.
//

#include "Cell.h"

Cell::Cell() : id(0) {
    this->nodes = std::vector<Node*>(8);
}

Cell::Cell(Node &n1, Node &n2, Node &n3, Node &n4, Node &n5, Node &n6, Node &n7, Node &n8, unsigned int id) : id(id) {
    this->nodes = std::vector<Node*>(8);
    this->nodes.push_back(&n1);
    this->nodes.push_back(&n2);
    this->nodes.push_back(&n3);
    this->nodes.push_back(&n4);
    this->nodes.push_back(&n5);
    this->nodes.push_back(&n6);
    this->nodes.push_back(&n7);
    this->nodes.push_back(&n8);
}

Cell::~Cell() {
    this->nodes.clear();
}

bool Cell::operator==(const Cell &cell) {
    for(int i = 0; i < 8; ++i) {
        if (this->nodes.at(i) != cell.nodes.at(i)) {
            return false;
        }
    }
    return this->id == cell.id;
}

