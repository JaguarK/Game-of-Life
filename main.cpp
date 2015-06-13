#include <iostream>
using namespace std;

#define SIZE 5


char ALIVE = 'm';
char DEAD = ' ';


void fillMap(char map[SIZE][SIZE]) {
    for(int y = 0; y < SIZE; y++) {
        for(int x = 0; x < SIZE; x++) {
            cout << (map[y][x] = ((rand() % 2 == 1) ? 'm' : ' ')) << ' ';
        }
        cout << endl;
    }
}

void clearScreen() {
    cout << string( 20, '\n' );
}

bool isOnMap(int x, int y) {
    return ((y >= 0 && y < SIZE) && (x >= 0 && x < SIZE));
}

int numLiveNeighbors(char map[][SIZE], int x, int y) {
    int cycle[] = { -1, -1, -1, 0, 1, 1, 1, 0, -1, -1 };
    int sum = 0;

    for(int i = 0; i < 8; ++i) {
        sum += (isOnMap(y + cycle[i], x + cycle[i + 2]) && map[y + cycle[i]][x + cycle[i + 2]] == ALIVE) ? 1 : 0;
    }
    return sum;
}

int main()
{
    string q = "";

    while(q != "q") {

        char map[SIZE][SIZE];
        fillMap(map);

        //char test[5][5];
        char test[5][5] = { { ALIVE, ALIVE, DEAD, DEAD, ALIVE },
                            { ALIVE, ALIVE, DEAD, DEAD, ALIVE },
                            { ALIVE, DEAD, DEAD, DEAD, DEAD },
                            { DEAD, DEAD, DEAD, DEAD, DEAD },
                            { DEAD, DEAD, DEAD, DEAD, DEAD }, };

        cout << map[0][0] << endl;
        cout << numLiveNeighbors(map, 2, 1) << endl;
        cout << "SIZE: " << SIZE << endl;
        cin >> q;

        cout << isOnMap(4, 4);

        clearScreen();
    }
}





