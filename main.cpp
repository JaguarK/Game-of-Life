/*
 * Author: Jaguar Kristeller
 * Date: June 13, 2015
 * Implementation of John Conway's "Game of Life" as a learning exercise in C++, Qt Creator, Git
 *  in preparation for making a self balancing inverted pendulum/segway robot using Q-learning reinforcement learning
 *  at the Universitaet Stuttgart Informatik Machinelles Lernen und Robotik Labor
*/

#include <iostream>
using namespace std;

#define SIZE 25


char ALIVE = '*';
char DEAD = ' ';


//refreshes terminal
void clearScreen() {
    cout << string( 20, '\n' );
}

//checks if cell is in map[][] to avoid checking neighbors of border cells that aren't on the map
bool isOnMap(int x, int y) {
    return ((y >= 0 && y < SIZE) && (x >= 0 && x < SIZE));
}

//counts the number of live cells around the center cell (x, y)
int numLiveNeighbors(char map[][SIZE], int x, int y) {
    //cycle [] contains offset values to all the neighboring cells to be cycled around using a for loop
    int cycle[] = { -1, -1, -1, 0, 1, 1, 1, 0, -1, -1 };
    int sum = 0;

    //cycles clockwise around the neighboring cells starting in the top left corner
    for(int i = 0; i < 8; ++i) {
        sum += (isOnMap(y + cycle[i], x + cycle[i + 2]) && map[y + cycle[i]][x + cycle[i + 2]] == ALIVE) ? 1 : 0;
    }
    return sum;
}

//populates the map with cells randomly chosen between live and dead
void fillMap(char map[][SIZE]) {
    for(int y = 0; y < SIZE; y++) {
        for(int x = 0; x < SIZE; x++) {
            map[y][x] = ((rand() % 2 == 1) ? ALIVE : DEAD);
        }
    }
}

void updateMap(char map[][SIZE]) {
    for(int y = 0; y < SIZE; y++) {
        for(int x = 0; x < SIZE; x++) {
            if( (map[y][x] == DEAD && numLiveNeighbors(map, x, y) == 3) ||
                (map[y][x] == ALIVE && (numLiveNeighbors(map, x, y) == 2 || numLiveNeighbors(map, x, y) == 3)))
            {   map[y][x] = ALIVE; }
            else { map[y][x] = DEAD; }
        }
    }
}

void printMap(char map[][SIZE]) {
    for(int y = 0; y < SIZE; y++) {
        for(int x = 0; x < SIZE; x++) {
            cout << map[y][x] << ' ';
        }
        cout << endl;
    }
}



int main()
{
    char map[SIZE][SIZE];
    string q = "";

    fillMap(map);

    while(q != "q") {
        printMap(map);
        updateMap(map);
        cin >> q;
        clearScreen();
    }
}





