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

    } else {
        double deltaX = this->foundDeltaX();
        double deltaY = this->foundDeltaY();
        double deltaZ = this->foundDeltaZ();

        double minDelta = this->foundMinOfThree(deltaX, deltaY, deltaZ);

        if ( deltaX ==  minDelta ) {
            this->planeType = PlaneType::LEFT_RIGHT;

        } else if ( deltaY ==  minDelta ) {
            this->planeType = PlaneType::FRONT_BACK;

        } else if ( deltaZ ==  minDelta ) {
            this->planeType = PlaneType::TOP_BOTTOM;

        } else {
            this->planeType = PlaneType::ERR;
        }
    }
}

void Plane::mainNodesSort() {
    switch (this->planeType) {
        case PlaneType::LEFT_RIGHT:
            sortLEFT_RIGHT();
            break;
        case PlaneType::FRONT_BACK:
            sortFRONT_BACK();
            break;
        case PlaneType::TOP_BOTTOM:
            sortTOP_BOTTOM();
            break;
        default:
            break;
    }
}

void Plane::sortLEFT_RIGHT() {
    std::vector<std::pair<double, int>> xData;
    std::vector<std::pair<double, int>> yData;
    std::vector<std::pair<double, int>> zData;

    std::vector<int> resultPosition = std::vector<int>(4);

    xData.reserve(4);
    yData.reserve(4);
    zData.reserve(4);
    for (int i = 0; i < 4; ++i) {
        xData.emplace_back(this->nodes[i]->getPoint().getX(), i);
        yData.emplace_back(this->nodes[i]->getPoint().getY(), i);
        zData.emplace_back(this->nodes[i]->getPoint().getZ(), i);
    }

    std::sort(xData.begin(), xData.end());
    std::sort(yData.begin(), yData.end());
    std::sort(zData.begin(), zData.end());

    // Определяем первую вершину
    if (zData[2].second == yData[0].second || zData[2].second == yData[1].second) {
        resultPosition[0] = zData[2].second;
    } else {
        resultPosition[0] = zData[3].second;
    }

    // Определяем вторую вершину
    if (zData[2].second != resultPosition[0]) {
        resultPosition[1] = zData[2].second;
    } else {
        resultPosition[1] = zData[3].second;
    }

    // Определяем третью вершину
    if (zData[0].second == yData[2].second || zData[0].second == yData[3].second) {
        resultPosition[2] = zData[0].second;
    } else {
        resultPosition[2] = zData[1].second;
    }

    // Определяем четвертую вершину
    if (zData[0].second != resultPosition[2]) {
        resultPosition[3] = zData[0].second;
    } else {
        resultPosition[3] = zData[1].second;
    }

    auto oldNodes = std::vector<Node*>(this->nodes);
    // На данном этапе у нас есть массив отсортированных индексов вершин
    // Далее надо отсортировать настоящий массив вершин
    for (int i = 0; i < 4; ++i) {
        std::swap(this->nodes[i], oldNodes[resultPosition[i]]);
    }
}


void Plane::sortTOP_BOTTOM() {
    std::vector<std::pair<double, int>> xData;
    std::vector<std::pair<double, int>> yData;
    std::vector<std::pair<double, int>> zData;

    std::vector<int> resultPosition = std::vector<int>(4);

    xData.reserve(4);
    yData.reserve(4);
    zData.reserve(4);
    for (int i = 0; i < 4; ++i) {
        xData.emplace_back(this->nodes[i]->getPoint().getX(), i);
        yData.emplace_back(this->nodes[i]->getPoint().getY(), i);
        zData.emplace_back(this->nodes[i]->getPoint().getZ(), i);
    }

    std::sort(xData.begin(), xData.end());
    std::sort(yData.begin(), yData.end());
    std::sort(zData.begin(), zData.end());

    // Определяем первую вершину
    if (yData[2].second == xData[0].second || yData[2].second == xData[1].second) {
        resultPosition[0] = yData[2].second;
    } else {
        resultPosition[0] = yData[3].second;
    }

    // Определяем вторую вершину
    if (yData[2].second != resultPosition[0]) {
        resultPosition[1] = yData[2].second;
    } else {
        resultPosition[1] = yData[3].second;
    }

    // Определяем третью вершину
    if (yData[0].second == xData[2].second || yData[0].second == xData[3].second) {
        resultPosition[2] = yData[0].second;
    } else {
        resultPosition[2] = yData[1].second;
    }

    // Определяем четвертую вершину
    if (yData[0].second != resultPosition[2]) {
        resultPosition[3] = yData[0].second;
    } else {
        resultPosition[3] = yData[1].second;
    }

    auto oldNodes = std::vector<Node*>(this->nodes);
    // На данном этапе у нас есть массив отсортированных индексов вершин
    // Далее надо отсортировать настоящий массив вершин
    for (int i = 0; i < 4; ++i) {
        std::swap(this->nodes[i], oldNodes[resultPosition[i]]);
    }
}

void Plane::sortFRONT_BACK() {
    std::vector<std::pair<double, int>> xData;
    std::vector<std::pair<double, int>> yData;
    std::vector<std::pair<double, int>> zData;

    std::vector<int> resultPosition = std::vector<int>(4);

    xData.reserve(4);
    yData.reserve(4);
    zData.reserve(4);
    for (int i = 0; i < 4; ++i) {
        xData.emplace_back(this->nodes[i]->getPoint().getX(), i);
        yData.emplace_back(this->nodes[i]->getPoint().getY(), i);
        zData.emplace_back(this->nodes[i]->getPoint().getZ(), i);
    }

    std::sort(xData.begin(), xData.end());
    std::sort(yData.begin(), yData.end());
    std::sort(zData.begin(), zData.end());

    // Определяем первую вершину
    if (zData[2].second == xData[0].second || zData[2].second == xData[1].second) {
        resultPosition[0] = zData[2].second;
    } else {
        resultPosition[0] = zData[3].second;
    }

    // Определяем вторую вершину
    if (zData[2].second != resultPosition[0]) {
        resultPosition[1] = zData[2].second;
    } else {
        resultPosition[1] = zData[3].second;
    }

    // Определяем третью вершину
    if (zData[0].second == xData[2].second || zData[0].second == xData[3].second) {
        resultPosition[2] = zData[0].second;
    } else {
        resultPosition[2] = zData[1].second;
    }

    // Определяем четвертую вершину
    if (zData[0].second != resultPosition[2]) {
        resultPosition[3] = zData[0].second;
    } else {
        resultPosition[3] = zData[1].second;
    }

    auto oldNodes = std::vector<Node*>(this->nodes);
    // На данном этапе у нас есть массив отсортированных индексов вершин
    // Далее надо отсортировать настоящий массив вершин
    for (int i = 0; i < 4; ++i) {
        std::swap(this->nodes[i], oldNodes[resultPosition[i]]);
    }
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
        case LEFT_RIGHT: {
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
        case TOP_BOTTOM: {
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
        case FRONT_BACK: {
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

double Plane::foundDeltaX() const {
    double deltaX01 = abs(this->nodes.at(0)->getPoint().getX() - this->nodes.at(1)->getPoint().getX()),
           deltaX12 = abs(this->nodes.at(1)->getPoint().getX() - this->nodes.at(2)->getPoint().getX()),
           deltaX23 = abs(this->nodes.at(2)->getPoint().getX() - this->nodes.at(3)->getPoint().getX());

    return this->foundMaxOfThree(deltaX01, deltaX12, deltaX23);
}

double Plane::foundDeltaY() const {
    double  deltaY01 = abs(this->nodes.at(0)->getPoint().getY() - this->nodes.at(1)->getPoint().getY()),
            deltaY12 = abs(this->nodes.at(1)->getPoint().getY() - this->nodes.at(2)->getPoint().getY()),
            deltaY23 = abs(this->nodes.at(2)->getPoint().getY() - this->nodes.at(3)->getPoint().getY());

    return this->foundMaxOfThree(deltaY01, deltaY12, deltaY23);
}

double Plane::foundDeltaZ() const {
    double  deltaZ01 = abs(this->nodes.at(0)->getPoint().getZ() - this->nodes.at(1)->getPoint().getZ()),
            deltaZ12 = abs(this->nodes.at(1)->getPoint().getZ() - this->nodes.at(2)->getPoint().getZ()),
            deltaZ23 = abs(this->nodes.at(2)->getPoint().getZ() - this->nodes.at(3)->getPoint().getZ());

    return this->foundMaxOfThree(deltaZ01, deltaZ12, deltaZ23);
}

double Plane::foundMaxOfThree(double a, double b, double c) const {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

double Plane::foundMinOfThree(double a, double b, double c) const {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}
