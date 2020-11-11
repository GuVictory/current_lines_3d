//
// Created by Виктория Губанова on 05.10.2020.
//

#ifndef CURRENTLINES3D_INTERPOLATOR_H
#define CURRENTLINES3D_INTERPOLATOR_H

#include "Node.h"

struct FirstInterpolationData {
    double uD, vD, wD, uE, vE, wE, uF, vF, wF,  uG, vG, wG;
    FirstInterpolationData(): uD(0), vD(0), wD(0), uE(0), vE(0), wE(0), uF(0), vF(0), wF(0), uG(0), vG(0), wG(0) {}
};

struct SecondInterpolationData {
    double uB, vB, wB, uC, vC, wC;
    SecondInterpolationData(): uB(0), vB(0), wB(0), uC(0), vC(0), wC(0) {}
};

struct ThirdInterpolationData {
    double uA, vA, wA;
    ThirdInterpolationData(): uA(0), vA(0), wA(0) {}
};

class Interpolator {

    // Переменные соотношений
    double tau, omega, gamma;

public:
    Interpolator(double ptau, double pomega, double pgamma);

    FirstInterpolationData firstInterpolation(const Node& V1,
                                              const Node& V2,
                                              const Node& V3,
                                              const Node& V4,
                                              const Node& V5,
                                              const Node& V6,
                                              const Node& V7,
                                              const Node& V8);

    SecondInterpolationData secondInterpolation(const Node& D,
                                                const Node& E,
                                                const Node& F,
                                                const Node& G);

    ThirdInterpolationData thirdInterpolation(const Node& B, const Node&C);
};


#endif //CURRENTLINES3D_INTERPOLATOR_H
