//
// Created by Виктория Губанова on 03.09.2020.
//

#include "Cell.h"

Cell::Cell() : id(0) {
    this->nodes = std::vector<Node*>(8);
}

Cell::Cell(Node &n1, Node &n2, Node &n3, Node &n4, Node &n5, Node &n6, Node &n7, Node &n8, unsigned int id) : id(id) {
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

Plane &Cell::getSuitablePlane(CellFaces face, double coord) {
    std::vector<Node*> suitableNodes;
    if ( face == CellFaces::FRONT || face == CellFaces::BACK ) {
        for (int i = 0; i < 8; ++i) {
            if ( this->nodes.at(i)->getPoint().getY() == coord ) {
                suitableNodes.push_back(this->nodes.at(i));
            }
            if (suitableNodes.size() == 4) {
                break;
            }
        }
    } else if ( face == CellFaces::LEFT || face == CellFaces::RIGHT ) {
        for (int i = 0; i < 8; ++i) {
            if ( this->nodes.at(i)->getPoint().getX() == coord ) {
                suitableNodes.push_back(this->nodes.at(i));
            }
            if (suitableNodes.size() == 4) {
                break;
            }
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            if ( this->nodes.at(i)->getPoint().getZ() == coord ) {
                suitableNodes.push_back(this->nodes.at(i));
            }
            if (suitableNodes.size() == 4) {
                break;
            }
        }
    }

    auto* plane = new Plane(*suitableNodes.at(0),
                            *suitableNodes.at(1),
                            *suitableNodes.at(2),
                            *suitableNodes.at(3));
    return *plane;
}

Plane &Cell::getFrontPlane() {
    EdgeValues edgeValues = getYEdgeValues();
    return this->getSuitablePlane(CellFaces::FRONT, edgeValues.min);
}

Plane &Cell::getBackPlane() {
    EdgeValues edgeValues = getYEdgeValues();
    return this->getSuitablePlane(CellFaces::BACK, edgeValues.max);
}

Plane &Cell::getLeftPlane() {
    EdgeValues edgeValues = getXEdgeValues();
    return this->getSuitablePlane(CellFaces::LEFT, edgeValues.min);
}

Plane &Cell::getRightPlane() {
    EdgeValues edgeValues = getXEdgeValues();
    return this->getSuitablePlane(CellFaces::RIGHT, edgeValues.max);
}

Plane &Cell::getBottomPlane() {
    EdgeValues edgeValues = getZEdgeValues();
    return this->getSuitablePlane(CellFaces::BOTTOM, edgeValues.min);
}

Plane &Cell::getTopPlane() {
    EdgeValues edgeValues = getZEdgeValues();
    return this->getSuitablePlane(CellFaces::TOP, edgeValues.max);
}



