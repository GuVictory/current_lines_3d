//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_PLANE_H
#define CURRENTLINES3D_PLANE_H

#include <Node.h>
#include <PlaneType.h>
#include <vector>
#include "PlaneIntersections.h"

class Plane {
private:
    PlaneType planeType;
    std::vector<Node*> nodes;

    void setPlaneType();
    void mainNodesSort();
    void sortYZ();
    void sortXY();
    void sortXZ();

    bool checkYZ();
    bool checkXY();
    bool checkXZ();

    // Метод для определения имеет ли ячейка 4 уникальных узла или же они попарно совпадают
    bool checkIsCorrectPlane();
public:
    Plane(Node& n1,
          Node& n2,
          Node& n3,
          Node& n4);
    ~Plane();

    PlaneType getType();

    // Метод который позволяет определить могут ли две плоскости явзятся гранями одной ячейки
    bool areSuitsPlane(const Plane& plane);

    /*!
     * Метод, который позваляет определить точки пересечения сканирующих линий из point c с ребрами ячейки
     * @param point - точка на плоскости
     * @return если переданная точка находится в заданной области простасти, то позвращается true, PlaneIntersections
     *          иначе false, PlaneIntersections()
     */
    std::pair<bool, PlaneIntersections*> getPlaneIntersections(const Point& point);


    bool operator==(const Plane& plane) const;

    Node* V1() const {
        return this->nodes[0];
    }

    Node* V2() const {
        return this->nodes[1];
    }

    Node* V3() const {
        return this->nodes[2];
    }

    Node* V4() const {
        return this->nodes[3];
    }
};


#endif //CURRENTLINES3D_PLANE_H
