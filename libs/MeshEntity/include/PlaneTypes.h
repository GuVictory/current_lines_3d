//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_PLANETYPES_H
#define CURRENTLINES3D_PLANETYPES_H

/// Тип плоскости зависит от того, какой гранью ячейки является плоскость,
/// XYZ рассматриваются как в ДСК
/*
 * | z
 * |  / y
 * | /
 * |/--------- z
*/
// В случае, если тип плоскости не определен, то ERR
enum PlaneType { YZ, XY, XZ, ERR };

#endif //CURRENTLINES3D_PLANETYPES_H
