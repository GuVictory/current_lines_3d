//
// Created by Виктория Губанова on 03.09.2020.
//

#include "Cell.h"
#include <cmath>

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

bool Cell::operator==(const Cell &cell) const {
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

    std::vector<std::pair<double, int>> deltaForNodes = std::vector<std::pair<double, int>>(8);

    if ( face == CellFaces::FRONT || face == CellFaces::BACK ) {
        for (int i = 0; i < 8; ++i) {
            deltaForNodes[i].first = abs(this->nodes.at(i)->getPoint().getY() - coord);
            deltaForNodes[i].second = i;
        }
    } else if ( face == CellFaces::LEFT || face == CellFaces::RIGHT ) {
        for (int i = 0; i < 8; ++i) {
            deltaForNodes[i].first = abs(this->nodes.at(i)->getPoint().getX() - coord);
            deltaForNodes[i].second = i;
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            for (int i = 0; i < 8; ++i) {
                deltaForNodes[i].first = abs(this->nodes.at(i)->getPoint().getZ() - coord);
                deltaForNodes[i].second = i;
            }
        }
    }

    std::sort(deltaForNodes.begin(), deltaForNodes.end());
    suitableNodes.push_back(this->nodes[deltaForNodes[0].second]);
    suitableNodes.push_back(this->nodes[deltaForNodes[1].second]);
    suitableNodes.push_back(this->nodes[deltaForNodes[2].second]);
    suitableNodes.push_back(this->nodes[deltaForNodes[3].second]);

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

bool Cell::containsPoint(const Point &point) {
    EdgeValues edgeValuesX = this->getXEdgeValues();
    if (point.getX() < edgeValuesX.min || point.getX() > edgeValuesX.max) {
        return false;
    }

    EdgeValues edgeValuesY = this->getYEdgeValues();
    if (point.getY() < edgeValuesY.min || point.getY() > edgeValuesY.max) {
        return false;
    }

    EdgeValues edgeValuesZ = this->getZEdgeValues();
    if (point.getZ() < edgeValuesZ.min || point.getZ() > edgeValuesZ.max) {
        return false;
    }

    // TODO: Добавить детальную локализацию точки

    std::vector<double> result;
    result.reserve(6);

    auto rightPlane = this->getRightPlane();
    double test = rightPlane.getPositionOfPoint(point);
    if (rightPlane.getPositionOfPoint(point) < 0) {
        //return false;
    }

    auto leftPlane = this->getLeftPlane();
    test = leftPlane.getPositionOfPoint(point);
    if (leftPlane.getPositionOfPoint(point) > 0) {
        //return false;
    }


    auto topPlane = this->getRightPlane();
    test = topPlane.getPositionOfPoint(point);
    if (topPlane.getPositionOfPoint(point) < 0) {
        //return false;
    }

    auto bottomPlane = this->getLeftPlane();
    test = bottomPlane.getPositionOfPoint(point);
    if (bottomPlane.getPositionOfPoint(point) > 0) {
        //return false;
    }

    auto frontPlane = this->getRightPlane();
    test = frontPlane.getPositionOfPoint(point);
    if (frontPlane.getPositionOfPoint(point) < 0) {
        //return false;
    }

    auto backPlane = this->getLeftPlane();
    test = backPlane.getPositionOfPoint(point);
    if (backPlane.getPositionOfPoint(point) > 0) {
        //return false;
    }

    return true;
}

Point &Cell::getIntersectionWithRightEdge(const Point &point) {
    Line scanLine = Line::getScanLineOX(point);

    auto* n1 = new Point(this->getXEdgeValues().max, this->getYEdgeValues().min, point.getZ());
    auto* n2 = new Point(this->getXEdgeValues().max, this->getYEdgeValues().max, point.getZ());

    auto* lineOnRightEdge = new Line(*n1, *n2);

    auto* result = new Point(scanLine.foundIntersectionPoint(*lineOnRightEdge).second);

    delete n1;
    delete n2;
    delete lineOnRightEdge;

    return *result;
}

Point &Cell::getIntersectionWithLeftEdge(const Point &point) {
    Line scanLine = Line::getScanLineOX(point);

    auto* n1 = new Point(this->getXEdgeValues().min, this->getYEdgeValues().min, point.getZ());
    auto* n2 = new Point(this->getXEdgeValues().min, this->getYEdgeValues().max, point.getZ());

    auto* lineOnRightEdge = new Line(*n1, *n2);

    auto* result = new Point(scanLine.foundIntersectionPoint(*lineOnRightEdge).second);

    delete n1;
    delete n2;
    delete lineOnRightEdge;

    return *result;
}

Point &Cell::getIntersectionWithFrontEdge(const Point &point) {
    Line scanLine = Line::getScanLineOY(point);

    auto* n1 = new Point(point.getX(), this->getYEdgeValues().min, this->getZEdgeValues().min);
    auto* n2 = new Point(point.getX(), this->getYEdgeValues().min, this->getZEdgeValues().max);

    auto* lineOnRightEdge = new Line(*n1, *n2);

    auto* result = new Point(scanLine.foundIntersectionPoint(*lineOnRightEdge).second);

    delete n1;
    delete n2;
    delete lineOnRightEdge;

    return *result;
}

Point &Cell::getIntersectionWithBackEdge(const Point &point) {
    Line scanLine = Line::getScanLineOY(point);

    auto* n1 = new Point(point.getX(), this->getYEdgeValues().max, this->getZEdgeValues().min);
    auto* n2 = new Point(point.getX(), this->getYEdgeValues().max, this->getZEdgeValues().max);

    auto* lineOnRightEdge = new Line(*n1, *n2);

    auto* result = new Point(scanLine.foundIntersectionPoint(*lineOnRightEdge).second);

    delete n1;
    delete n2;
    delete lineOnRightEdge;

    return *result;
}

Point &Cell::getIntersectionWithTopEdge(const Point &point) {
    Line scanLine = Line::getScanLineOZ(point);

    auto* n1 = new Point(this->getXEdgeValues().min, point.getY(), this->getZEdgeValues().max);
    auto* n2 = new Point(this->getXEdgeValues().max, point.getY(), this->getZEdgeValues().max);

    auto* lineOnRightEdge = new Line(*n1, *n2);

    auto* result = new Point(scanLine.foundIntersectionPoint(*lineOnRightEdge).second);

    delete n1;
    delete n2;
    delete lineOnRightEdge;

    return *result;
}

Point &Cell::getIntersectionWithBottomEdge(const Point &point) {
    Line scanLine = Line::getScanLineOZ(point);

    auto* n1 = new Point(this->getXEdgeValues().min, point.getY(), this->getZEdgeValues().min);
    auto* n2 = new Point(this->getXEdgeValues().max, point.getY(), this->getZEdgeValues().min);

    auto* lineOnRightEdge = new Line(*n1, *n2);

    auto* result = new Point(scanLine.foundIntersectionPoint(*lineOnRightEdge).second);

    delete n1;
    delete n2;
    delete lineOnRightEdge;

    return *result;
}

double Cell::getHeight() {
    auto* V1V4 = new Line(this->V1()->getPoint(), this->V4()->getPoint());
    return V1V4->len();
}

double Cell::getWidth() {
    auto* V1V2 = new Line(this->V1()->getPoint(), this->V2()->getPoint());
    return V1V2->len();
}

double Cell::getDepth() {
    auto* V1V5= new Line(this->V1()->getPoint(), this->V5()->getPoint());
    return V1V5->len();
}



