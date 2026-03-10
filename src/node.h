#ifndef NODE_H
#define NODE_H

struct Node {
    int x;
    int y;

    int g;
    int h;
    int f;

    Node* parent;

    Node(int xPos, int yPos) {
        x = xPos;
        y = yPos;
        g = h = f = 0;
        parent = nullptr;
    }
};

#endif