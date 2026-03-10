#include "astar.h"
#include <queue>
#include <cmath>
#include <set>

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct CompareNode {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

std::vector<Node> aStarSearch(
    std::vector<std::vector<int>>& grid,
    Node start,
    Node goal
) {

    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openList;
    std::set<std::pair<int,int>> closedList;

    Node* startNode = new Node(start.x,start.y);
    openList.push(startNode);

    int rows = grid.size();
    int cols = grid[0].size();

    while(!openList.empty()) {

        Node* current = openList.top();
        openList.pop();

        if(current->x == goal.x && current->y == goal.y) {

            std::vector<Node> path;

            while(current != nullptr) {
                path.push_back(*current);
                current = current->parent;
            }

            return path;
        }

        closedList.insert({current->x,current->y});

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int i=0;i<4;i++) {

            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if(nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                continue;

            if(grid[nx][ny] == 1)
                continue;

            if(closedList.count({nx,ny}))
                continue;

            Node* neighbor = new Node(nx,ny);

            neighbor->g = current->g + 1;
            neighbor->h = heuristic(*neighbor,goal);
            neighbor->f = neighbor->g + neighbor->h;

            neighbor->parent = current;

            openList.push(neighbor);
        }
    }

    return {};
}