//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENT_LINES_3D_LINE_H
#define CURRENT_LINES_3D_LINE_H

#include <Node.h>
#include <iostream>

class Line {
private:
    Node* firstNode;
    Node* secondNode;

public:
    Line();
    Line(const Node& n1, const Node& n2);
    Line(double x1, double y1, double z1, double x2, double y2, double z2);

    ~Line();

    double len();

    bool operator==(const Line& line) const;

    friend std::ostream& operator<<(std::ostream &out, const Line &line);
};


#endif //CURRENT_LINES_3D_LINE_H
