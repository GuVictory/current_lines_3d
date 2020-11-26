//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_PLANETYPE_H
#define CURRENTLINES3D_PLANETYPE_H

/// Тип плоскости зависит от того, какой гранью ячейки является плоскость,
// В случае, если тип плоскости не определен, то ERR
// Если передаются в проскость одинковые узлы, то тип - SAME_POINTS
enum PlaneType { LEFT_RIGHT, TOP_BOTTOM, FRONT_BACK, SAME_POINTS, ERR };

#endif //CURRENTLINES3D_PLANETYPE_H
