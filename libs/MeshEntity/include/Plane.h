//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_PLANE_H
#define CURRENTLINES3D_PLANE_H

#include <Node.h>
#include <PlaneType.h>
#include <vector>

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

    bool operator==(const Plane& plane) const;
};


#endif //CURRENTLINES3D_PLANE_H
