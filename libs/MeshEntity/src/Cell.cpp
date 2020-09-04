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

EdgeValues Cell::getXEdgeValues() {
    double minX = this->nodes.at(0)->getPoint().getX();
    double maxX = this->nodes.at(0)->getPoint().getX();
    for ( int i = 1; i < 8; ++i ) {
        if ( minX > this->nodes.at(i)->getPoint().getX() ) {
            minX = this->nodes.at(i)->getPoint().getX();
        }
        if ( maxX < this->nodes.at(i)->getPoint().getX() ) {
            maxX = this->nodes.at(i)->getPoint().getX();
        }
    }
    return EdgeValues(minX, maxX);
}

EdgeValues Cell::getYEdgeValues() {
    double minY = this->nodes.at(0)->getPoint().getY();
    double maxY = this->nodes.at(0)->getPoint().getY();
    for ( int i = 1; i < 8; ++i ) {
        if ( minY > this->nodes.at(i)->getPoint().getY() ) {
            minY = this->nodes.at(i)->getPoint().getY();
        }
        if ( maxY < this->nodes.at(i)->getPoint().getY() ) {
            maxY = this->nodes.at(i)->getPoint().getY();
        }
    }
    return EdgeValues(minY, maxY);
}

EdgeValues Cell::getZEdgeValues() {
    double minZ = this->nodes.at(0)->getPoint().getZ();
    double maxZ = this->nodes.at(0)->getPoint().getZ();
    for ( int i = 1; i < 8; ++i ) {
        if ( minZ > this->nodes.at(i)->getPoint().getZ() ) {
             minZ = this->nodes.at(i)->getPoint().getZ();
        }
        if ( maxZ < this->nodes.at(i)->getPoint().getZ() ) {
             maxZ = this->nodes.at(i)->getPoint().getZ();
        }
    }
    return EdgeValues(minZ, maxZ);
}

Plane &Cell::getFrontPlane() {
    EdgeValues edgeValues = getYEdgeValues();
    std::vector<Node*> frontNodes;
    for (int i = 0; i < 8; ++i) {
        if ( this->nodes.at(i)->getPoint().getY() == edgeValues.min ) {
            frontNodes.push_back(this->nodes.at(i));
        }
        if (frontNodes.size() == 4) {
            break;
        }
    }
    auto* plane = new Plane(*frontNodes.at(0), *frontNodes.at(1), *frontNodes.at(2), *frontNodes.at(3));
    return *plane;
}

