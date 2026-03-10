#ifndef ASTAR_H
#define ASTAR_H

#include <vector>

struct Node {
    int x, y;
    int g, h, f;
    Node* parent;

    Node(int x, int y);
};

std::vector<Node> findPath(
    std::vector<std::vector<int>>& grid,
    Node start,
    Node goal
);

#endif
