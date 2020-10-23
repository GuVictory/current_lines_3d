//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_PLANETYPE_H
#define CURRENTLINES3D_PLANETYPE_H

/// Тип плоскости зависит от того, какой гранью ячейки является плоскость,
/// XYZ рассматриваются как в ДСК
/*
 * | z
 * |  / y
 * | /
 * |/--------- x
*/
// В случае, если тип плоскости не определен, то ERR
enum PlaneType { YZ, XY, XZ, SAME_POINTS, ERR };

#endif //CURRENTLINES3D_PLANETYPE_H
