//
// Created by Виктория Губанова on 09.11.2020.
//

#include "../include/CurrentLine.h"

CurrentLine::CurrentLine(Node &node): step(0.001) {
    this->currentLine.push_back(node);
}

CurrentLine::CurrentLine(Node &node, double pstep): step(pstep) {
    this->currentLine.push_back(node);
}

CurrentLine::~CurrentLine() {
    currentLine.clear();
}

Node &CurrentLine::getNode() {
    return currentLine.at(this->getLength() - 1);
}

void CurrentLine::addNode() {

    double newX = this->getNode().getPoint().getX() +
                    this->step * this->getNode().getField().getNormalizeVectorField().getX();

    double newY = this->getNode().getPoint().getY() +
                    this->step * this->getNode().getField().getNormalizeVectorField().getY();

    double newZ = this->getNode().getPoint().getZ() +
                    this->step * this->getNode().getField().getNormalizeVectorField().getZ();

    currentLine.push_back(*new Node(newX, newY, newZ));
}

void CurrentLine::setFieldOfNewNode(double fieldX, double fieldY, double fieldZ) {
    this->getNode().setField(fieldX, fieldY, fieldZ);
}

int CurrentLine::getLength() {
    return currentLine.size();
}

