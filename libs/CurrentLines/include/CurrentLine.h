//
// Created by Виктория Губанова on 09.11.2020.
//

#ifndef CURRENTLINES3D_CURRENTLINE_H
#define CURRENTLINES3D_CURRENTLINE_H

#include <vector>
#include "Node.h"


class CurrentLine {
private:
    std::vector<Node> currentLine;
    double step;
public:
    CurrentLine(Node& node);
    CurrentLine(Node& node, double pstep);
    ~CurrentLine();

    Node& getNode();
    void addNode();
    void setFieldOfNewNode(double fieldX, double fieldY, double fieldZ);
    int getLength();
};


#endif //CURRENTLINES3D_CURRENTLINE_H
