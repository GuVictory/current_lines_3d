//
// Created by Виктория Губанова on 04.09.2020.
//

#ifndef CURRENTLINES3D_EDGEVALUES_H
#define CURRENTLINES3D_EDGEVALUES_H

struct EdgeValues {
    double min;
    double max;
    bool same;

    EdgeValues(double minP, double maxP) : max(maxP), min(minP), same(maxP == minP) {}
};

#endif //CURRENTLINES3D_EDGEVALUES_H
