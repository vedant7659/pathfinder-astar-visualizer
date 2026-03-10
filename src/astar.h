#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include "node.h"

std::vector<Node> aStarSearch(
    std::vector<std::vector<int>>& grid,
    Node start,
    Node goal
);

#endif