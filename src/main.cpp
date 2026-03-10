#include <SFML/Graphics.hpp>
#include <vector>
#include "astar.h"

const int ROWS = 20;
const int COLS = 20;
const int CELL_SIZE = 30;

int main() {

    sf::RenderWindow window(
        sf::VideoMode(COLS*CELL_SIZE,ROWS*CELL_SIZE),
        "A* Pathfinding Visualizer"
    );

    std::vector<std::vector<int>> grid(
        ROWS,std::vector<int>(COLS,0)
    );

    Node start(0,0);
    Node goal(ROWS-1,COLS-1);

    auto path = aStarSearch(grid,start,goal);

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for(int i=0;i<ROWS;i++) {
            for(int j=0;j<COLS;j++) {

                sf::RectangleShape cell(
                    sf::Vector2f(CELL_SIZE-1,CELL_SIZE-1)
                );

                cell.setPosition(j*CELL_SIZE,i*CELL_SIZE);
                cell.setFillColor(sf::Color::White);

                window.draw(cell);
            }
        }

        for(auto &node : path) {

            sf::RectangleShape cell(
                sf::Vector2f(CELL_SIZE-1,CELL_SIZE-1)
            );

            cell.setPosition(node.y*CELL_SIZE,node.x*CELL_SIZE);
            cell.setFillColor(sf::Color::Green);

            window.draw(cell);
        }

        window.display();
    }
}