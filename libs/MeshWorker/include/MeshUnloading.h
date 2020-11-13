//
// Created by Виктория Губанова on 13.11.2020.
//

#ifndef CURRENTLINES3D_MESHUNLOADING_H
#define CURRENTLINES3D_MESHUNLOADING_H

#include <string>
#include "Node.h"
#include <utility>
#include <vector>

class MeshUnloading {
    std::string currentLineFilename;

public:
    explicit MeshUnloading(std::string currentLineFilename_p) : currentLineFilename(std::move(currentLineFilename_p)) {};
    MeshUnloading() : currentLineFilename("./currentLinesResult/resultCurrentLine.dot") {};

    void setFileToUnload(std::string currentLineFilename_p);
    void unloadCurrentLine(std::vector<Node*> currentLine);
};


#endif //CURRENTLINES3D_MESHUNLOADING_H
