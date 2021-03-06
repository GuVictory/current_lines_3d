//
// Created by Виктория Губанова on 31.08.2020.
//

#include <MeshLoader.h>

#include <utility>
#include <fstream>

MeshLoader::MeshLoader(std::string nodesFilename_p, std::string cellsFilename_p) {
    this->mesh = new Mesh();

    this->nodesFilename = std::move(nodesFilename_p);
    this->cellsFilename = std::move(cellsFilename_p);
}

MeshLoader::~MeshLoader() {
    delete this->mesh;
}

std::vector<Node> MeshLoader::loadNodes() {
    std::ifstream in(this->nodesFilename);

    if(!in) {
        std::cout << "Файл с узлами не может быть открыт!" << std::endl;
    }

    std::string line;

    // Считаем количество узлов
    getline(in, line);

    int numberOfNodes = std::stoi( line );

    std::vector<Node> nodes(numberOfNodes);

    std::vector<double> currentNodeData;

    for (int i = 0; i < numberOfNodes; ++i) {
        getline(in, line);
        this->tokenize(line, ' ', currentNodeData);

        // Строчка из файла имеет формат
        // id x y z field_x field_y field_z
        nodes[i].setId(int(currentNodeData[0]));
        nodes[i].setPoint(currentNodeData[1], currentNodeData[2], currentNodeData[3]);
        nodes[i].setField(currentNodeData[4], currentNodeData[5], currentNodeData[6]);
    }

    return nodes;
}

template<class T>
void MeshLoader::tokenize(std::string &str, char delim, std::vector<T> &out) {
    size_t start;
    size_t end = 0;
    out.clear();

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(std::stod(str.substr(start, end - start)));
    }
}

std::vector<std::tuple<long, long, long, long, long, long, long, long, long>> MeshLoader::loadCells() {
    std::ifstream in(this->cellsFilename);

    if(!in) {
        std::cout << "Файл с узлами не может быть открыт!" << std::endl;
    }

    std::string line;

    // Считаем количество ячеек
    getline(in, line);

    int numberOfCells = std::stoi( line );

    std::vector<std::tuple<long, long, long, long, long, long, long, long, long>> cells;

    std::vector<int> currentCellData;

    for (int i = 0; i < numberOfCells; ++i) {
        getline(in, line);
        this->tokenize(line, ' ', currentCellData);

        // id node1 node2 node3 node4 node5 node6 node7 node8
        cells.emplace_back(currentCellData[0],
                                        currentCellData[1],
                                        currentCellData[2],
                                        currentCellData[3],
                                        currentCellData[4],
                                        currentCellData[5],
                                        currentCellData[6],
                                        currentCellData[7],
                                        currentCellData[8]);
    }

    return cells;
}