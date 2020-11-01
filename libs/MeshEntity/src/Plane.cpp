//
// Created by Виктория Губанова on 03.09.2020.
//

#include "Plane.h"
#include <iostream>
#include <Line.h>
#include <cmath>

Plane::Plane(Node &n1, Node &n2, Node &n3, Node &n4) {
    this->nodes.push_back(&n1);
    this->nodes.push_back(&n2);
    this->nodes.push_back(&n3);
    this->nodes.push_back(&n4);
    this->planeType = PlaneType::ERR;
    setPlaneType();
    mainNodesSort();
}

Plane::~Plane() {
    nodes.clear();
}

// Метод, который устанавливает тип плоскости
void Plane::setPlaneType() {
    if ( !this->checkIsCorrectPlane() ) {
        this->planeType = PlaneType::SAME_POINTS;

    } else if ( this->nodes.at(0)->getPoint().getX() == this->nodes.at(1)->getPoint().getX() &&
         this->nodes.at(1)->getPoint().getX() == this->nodes.at(2)->getPoint().getX() &&
         this->nodes.at(2)->getPoint().getX() == this->nodes.at(3)->getPoint().getX() ) {

        this->planeType = PlaneType::YZ;

    } else if ( this->nodes.at(0)->getPoint().getZ() == this->nodes.at(1)->getPoint().getZ() &&
                this->nodes.at(1)->getPoint().getZ() == this->nodes.at(2)->getPoint().getZ() &&
                this->nodes.at(2)->getPoint().getZ() == this->nodes.at(3)->getPoint().getZ() ) {

        this->planeType = PlaneType::XY;
    } else if ( this->nodes.at(0)->getPoint().getY() == this->nodes.at(1)->getPoint().getY() &&
                this->nodes.at(1)->getPoint().getY() == this->nodes.at(2)->getPoint().getY() &&
                this->nodes.at(2)->getPoint().getY() == this->nodes.at(3)->getPoint().getY() ) {

        this->planeType = PlaneType::XZ;
    } else {
        this->planeType = PlaneType::ERR;
    }
}

void Plane::mainNodesSort() {
    switch (this->planeType) {
        case PlaneType::YZ:
            sortYZ();
            break;
        case PlaneType::XY:
            sortXY();
            break;
        case PlaneType::XZ:
            sortXZ();
            break;
        case PlaneType::SAME_POINTS:
            break;
    }
}

void Plane::sortYZ() {
    while(true) {
        // Проверим условие отсортированности
        // TODO: Вышло громоздко, так что, вероятно, надо пофиксить
        if ( checkYZ() &&
                this->nodes.at(0)->getPoint().getY() < this->nodes.at(1)->getPoint().getY() &&
                this->nodes.at(1)->getPoint().getZ() > this->nodes.at(2)->getPoint().getZ() &&
                this->nodes.at(2)->getPoint().getY() > this->nodes.at(3)->getPoint().getY() &&
                this->nodes.at(3)->getPoint().getZ() < this->nodes.at(0)->getPoint().getZ() ) {
            return;
        }

        if ( checkYZ() ) {

            if (this->nodes.at(0)->getPoint().getY() > this->nodes.at(1)->getPoint().getY()) {
                std::swap(this->nodes.at(0), this->nodes.at(1));
            }
            if ( this->nodes.at(1)->getPoint().getZ() < this->nodes.at(2)->getPoint().getZ() ) {
                std::swap(this->nodes.at(1), this->nodes.at(2));
            }
            if ( this->nodes.at(2)->getPoint().getY() < this->nodes.at(3)->getPoint().getY() ) {
                std::swap(this->nodes.at(2), this->nodes.at(3));
            }
            if ( this->nodes.at(3)->getPoint().getZ() > this->nodes.at(0)->getPoint().getZ() ) {
                std::swap(this->nodes.at(3), this->nodes.at(0));
            }

        } else {
            if ( this->nodes.at(0)->getPoint().getZ() != this->nodes.at(1)->getPoint().getZ() ) {
                std::swap(this->nodes.at(1),this->nodes.at(2));
            }
            if ( this->nodes.at(0)->getPoint().getY() != this->nodes.at(3)->getPoint().getY() ) {
                std::swap(this->nodes.at(3),this->nodes.at(1));
            }
        }


    }
}

bool Plane::checkYZ() {
    return this->nodes.at(0)->getPoint().getZ() == this->nodes.at(1)->getPoint().getZ() &&
           this->nodes.at(2)->getPoint().getZ() == this->nodes.at(3)->getPoint().getZ() &&
           this->nodes.at(0)->getPoint().getY() == this->nodes.at(3)->getPoint().getY() &&
           this->nodes.at(1)->getPoint().getY() == this->nodes.at(2)->getPoint().getY();
}

void Plane::sortXY() {
    while (true) {
        if ( checkXY() &&
             this->nodes.at(0)->getPoint().getX() < this->nodes.at(1)->getPoint().getX() &&
             this->nodes.at(1)->getPoint().getY() > this->nodes.at(2)->getPoint().getY() &&
             this->nodes.at(2)->getPoint().getX() > this->nodes.at(3)->getPoint().getX() &&
             this->nodes.at(3)->getPoint().getY() < this->nodes.at(0)->getPoint().getY() ) {
            return;
        }

        if ( checkXY() ) {

            if ( this->nodes.at(0)->getPoint().getX() > this->nodes.at(1)->getPoint().getX() ) {
                std::swap(this->nodes.at(0), this->nodes.at(1));
            }
            if ( this->nodes.at(1)->getPoint().getY() < this->nodes.at(2)->getPoint().getY() ) {
                std::swap(this->nodes.at(1), this->nodes.at(2));
            }
            if ( this->nodes.at(2)->getPoint().getX() < this->nodes.at(3)->getPoint().getX() ) {
                std::swap(this->nodes.at(2), this->nodes.at(3));
            }
            if ( this->nodes.at(3)->getPoint().getY() > this->nodes.at(0)->getPoint().getY() ) {
                std::swap(this->nodes.at(3), this->nodes.at(0));
            }

        } else {
            if ( this->nodes.at(0)->getPoint().getY() != this->nodes.at(1)->getPoint().getY() ) {
                std::swap(this->nodes.at(1),this->nodes.at(2));
            }
            if ( this->nodes.at(0)->getPoint().getX() != this->nodes.at(3)->getPoint().getX() ) {
                std::swap(this->nodes.at(3),this->nodes.at(1));
            }
        }
    }
}

bool Plane::checkXY() {
    return this->nodes.at(0)->getPoint().getY() == this->nodes.at(1)->getPoint().getY() &&
           this->nodes.at(2)->getPoint().getY() == this->nodes.at(3)->getPoint().getY() &&
           this->nodes.at(0)->getPoint().getX() == this->nodes.at(3)->getPoint().getX() &&
           this->nodes.at(1)->getPoint().getX() == this->nodes.at(2)->getPoint().getX();
}

void Plane::sortXZ() {
    while (true) {
        if ( checkXZ() &&
             this->nodes.at(0)->getPoint().getX() < this->nodes.at(1)->getPoint().getX() &&
             this->nodes.at(1)->getPoint().getZ() > this->nodes.at(2)->getPoint().getZ() &&
             this->nodes.at(2)->getPoint().getX() > this->nodes.at(3)->getPoint().getX() &&
             this->nodes.at(3)->getPoint().getZ() < this->nodes.at(0)->getPoint().getZ() ) {
            return;
        }

        if ( checkXZ() ) {

            if ( this->nodes.at(0)->getPoint().getX() > this->nodes.at(1)->getPoint().getX() ) {
                std::swap(this->nodes.at(0), this->nodes.at(1));
            }
            if ( this->nodes.at(1)->getPoint().getZ() < this->nodes.at(2)->getPoint().getZ() ) {
                std::swap(this->nodes.at(1), this->nodes.at(2));
            }
            if ( this->nodes.at(2)->getPoint().getX() < this->nodes.at(3)->getPoint().getX() ) {
                std::swap(this->nodes.at(2), this->nodes.at(3));
            }
            if ( this->nodes.at(3)->getPoint().getZ() > this->nodes.at(0)->getPoint().getZ() ) {
                std::swap(this->nodes.at(3), this->nodes.at(0));
            }

        } else {
            if ( this->nodes.at(0)->getPoint().getZ() != this->nodes.at(1)->getPoint().getZ() ) {
                std::swap(this->nodes.at(1),this->nodes.at(2));
            }
            if ( this->nodes.at(0)->getPoint().getX() != this->nodes.at(3)->getPoint().getX() ) {
                std::swap(this->nodes.at(3),this->nodes.at(1));
            }
        }
    }
}

bool Plane::checkXZ() {
    return this->nodes.at(0)->getPoint().getZ() == this->nodes.at(1)->getPoint().getZ() &&
           this->nodes.at(2)->getPoint().getZ() == this->nodes.at(3)->getPoint().getZ() &&
           this->nodes.at(0)->getPoint().getX() == this->nodes.at(3)->getPoint().getX() &&
           this->nodes.at(1)->getPoint().getX() == this->nodes.at(2)->getPoint().getX();
}

PlaneType Plane::getType() {
    return this->planeType;
}

bool Plane::operator==(const Plane &plane) const{
    for ( int i = 0; i < 4; ++i ) {
        if ( !(*this->nodes.at(i) == *plane.nodes.at(i)) ) {
            return false;
        }
    }
    return true;
}

bool Plane::checkIsCorrectPlane() {
    for ( int i = 0; i < 3; ++i ) {
        for ( int j = i + 1; j < 4; ++j ) {
            if ( *this->nodes.at(i) == *this->nodes.at(j) ) {
                return false;
            }
        }
    }

    return true;
}

bool Plane::areSuitsPlane(const Plane &plane) {
    int sameNodesCounter = 0;
    for ( int i = 0; i < 4; ++i ) {
        for ( int j = 0; j < 4; ++j ) {
            sameNodesCounter += *this->nodes.at(i) == *plane.nodes.at(j) ? 1 : 0;
        }
    }
    return sameNodesCounter == 2;
}

std::pair<bool, PlaneIntersections*> Plane::getPlaneIntersections(const Point &point) {
    // Создадим линии, описывающие грани ячейки
    Line* l1 = new Line(*this->nodes[0], *this->nodes[1]);
    Line* l2 = new Line(*this->nodes[1], *this->nodes[2]);
    Line* l3 = new Line(*this->nodes[2], *this->nodes[3]);
    Line* l4 = new Line(*this->nodes[3], *this->nodes[0]);

    // Исходя из типа ячейки будем искать пересечения
    switch (this->planeType) {
        case YZ: {
            // Произведем проверку, что точка находится на плоскости
            if (round(point.getX() * 100) / 100 != round(this->nodes[0]->getPoint().getX() * 100) / 100) {
                return std::make_pair(false, new PlaneIntersections());
            }
            // Создадим сканирующую линию по OY
            Line* scanLineY = new Line(Line::getScanLineOY(point));

            // Создадим сканирующую линию по OZ
            Line* scanLineZ = new Line(Line::getScanLineOZ(point));

            auto* maxZ = new Point(scanLineZ->foundIntersectionPoint(*l1).second);
            auto* maxY = new Point(scanLineY->foundIntersectionPoint(*l2).second);
            auto* minZ = new Point(scanLineZ->foundIntersectionPoint(*l3).second);
            auto* minY = new Point(scanLineY->foundIntersectionPoint(*l4).second);

            return std::make_pair(true, new PlaneIntersections(*new Point(0.0, 0.0, 0.0),
                                                                         *new Point(0.0, 0.0, 0.0),
                                                                         *new Point(*minY),
                                                                         *new Point(*maxY),
                                                                         *new Point(*minZ),
                                                                         *new Point(*maxZ)));
        }
        case XY: {
            // Произведем проверку, что точка находится на плоскости
            if (round(point.getZ() * 100) / 100 != round(this->nodes[0]->getPoint().getZ() * 100) / 100) {
                return std::make_pair(false, new PlaneIntersections());
            }
            // Создадим сканирующую линию по OY
            Line* scanLineY = new Line(Line::getScanLineOY(point));

            // Создадим сканирующую линию по OZ
            Line* scanLineX = new Line(Line::getScanLineOX(point));

            auto* maxY = new Point(scanLineY->foundIntersectionPoint(*l1).second);
            auto* maxX = new Point(scanLineX->foundIntersectionPoint(*l2).second);
            auto* minY = new Point(scanLineY->foundIntersectionPoint(*l3).second);
            auto* minX = new Point(scanLineX->foundIntersectionPoint(*l4).second);

            return std::make_pair(true, new PlaneIntersections(*minX, *maxX, *minY, *maxY, *new Point(), *new Point()));
        }
        case XZ: {
            // Произведем проверку, что точка находится на плоскости
            if (round(point.getY() * 100) / 100 != round(this->nodes[0]->getPoint().getY() * 100) / 100) {
                return std::make_pair(false, new PlaneIntersections());
            }
            // Создадим сканирующую линию по OY
            Line* scanLineX = new Line(Line::getScanLineOX(point));

            // Создадим сканирующую линию по OZ
            Line* scanLineZ = new Line(Line::getScanLineOZ(point));

            auto* maxZ = new Point(scanLineZ->foundIntersectionPoint(*l1).second);
            auto* maxX = new Point(scanLineX->foundIntersectionPoint(*l2).second);
            auto* minZ = new Point(scanLineZ->foundIntersectionPoint(*l3).second);
            auto* minX = new Point(scanLineX->foundIntersectionPoint(*l4).second);

            return std::make_pair(true, new PlaneIntersections(*minX, *maxX, *new Point(), *new Point(), *minZ, *maxZ));
        }
        default:
            return std::make_pair(false, new PlaneIntersections());
    }
}
