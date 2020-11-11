//
// Created by Виктория Губанова on 05.10.2020.
//

#include "Interpolator.h"

Interpolator::Interpolator(double ptau, double pomega, double pgamma) :
tau(ptau), omega(pomega), gamma(pgamma) {}

FirstInterpolationData
Interpolator::firstInterpolation(const Node &V1, const Node &V2, const Node &V3, const Node &V4, const Node &V5,
                                 const Node &V6, const Node &V7, const Node &V8) {
    FirstInterpolationData result;

    result.uD = this->tau * V1.getField().getX() + (1 - this->tau) * V4.getField().getX();
    result.vD = this->tau * V1.getField().getY() + (1 - this->tau) * V4.getField().getY();
    result.wD = this->tau * V1.getField().getZ() + (1 - this->tau) * V4.getField().getZ();

    result.uE = this->tau * V5.getField().getX() + (1 - this->tau) * V8.getField().getX();
    result.vE = this->tau * V5.getField().getY() + (1 - this->tau) * V8.getField().getY();
    result.wE = this->tau * V5.getField().getZ() + (1 - this->tau) * V8.getField().getZ();

    result.uF = this->tau * V2.getField().getX() + (1 - this->tau) * V3.getField().getX();
    result.vF = this->tau * V2.getField().getY() + (1 - this->tau) * V3.getField().getY();
    result.wF = this->tau * V2.getField().getZ() + (1 - this->tau) * V3.getField().getZ();

    result.uG = this->tau * V6.getField().getX() + (1 - this->tau) * V7.getField().getX();
    result.vG = this->tau * V6.getField().getY() + (1 - this->tau) * V7.getField().getY();
    result.wG = this->tau * V6.getField().getZ() + (1 - this->tau) * V7.getField().getZ();

    return result;
}

SecondInterpolationData Interpolator::secondInterpolation(const Node &D, const Node &E, const Node &F, const Node &G) {
    SecondInterpolationData result;

    result.uB = this->omega * D.getField().getX() + (1 - this->omega) * E.getField().getX();
    result.vB = this->omega * D.getField().getY() + (1 - this->omega) * E.getField().getY();
    result.wB = this->omega * D.getField().getZ() + (1 - this->omega) * E.getField().getZ();

    result.uC = this->omega * F.getField().getX() + (1 - this->omega) * G.getField().getX();
    result.vC = this->omega * F.getField().getY() + (1 - this->omega) * G.getField().getY();
    result.wC = this->omega * F.getField().getZ() + (1 - this->omega) * G.getField().getZ();

    return result;
}

ThirdInterpolationData Interpolator::thirdInterpolation(const Node &B, const Node &C) {
    ThirdInterpolationData result;

    result.uA = this->gamma * B.getField().getX() + (1 - this->gamma) * C.getField().getX();
    result.vA = this->gamma * B.getField().getY() + (1 - this->gamma) * C.getField().getY();
    result.wA = this->gamma * B.getField().getZ() + (1 - this->gamma) * C.getField().getZ();

    return result;
}

