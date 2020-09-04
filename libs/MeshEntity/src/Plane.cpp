//
// Created by Виктория Губанова on 03.09.2020.
//

#include "Plane.h"
#include <iostream>

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
    if (this->nodes.at(0)->getPoint().getX() == this->nodes.at(1)->getPoint().getX() &&
        this->nodes.at(1)->getPoint().getX() == this->nodes.at(2)->getPoint().getX() &&
        this->nodes.at(2)->getPoint().getX() == this->nodes.at(3)->getPoint().getX()) {

        this->planeType = PlaneType::YZ;

    } else if (this->nodes.at(0)->getPoint().getZ() == this->nodes.at(1)->getPoint().getZ() &&
               this->nodes.at(1)->getPoint().getZ() == this->nodes.at(2)->getPoint().getZ() &&
               this->nodes.at(2)->getPoint().getZ() == this->nodes.at(3)->getPoint().getZ()) {

        this->planeType = PlaneType::XY;
    } else if (this->nodes.at(0)->getPoint().getY() == this->nodes.at(1)->getPoint().getY() &&
               this->nodes.at(1)->getPoint().getY() == this->nodes.at(2)->getPoint().getY() &&
               this->nodes.at(2)->getPoint().getY() == this->nodes.at(3)->getPoint().getY()) {

        this->planeType = PlaneType::XZ;
    } else {
        this->planeType = PlaneType::ERR;
        std::cout << "[PLANE ERROR]: created plane with unusual PlaneType" << std::endl;
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
