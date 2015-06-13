#include <iostream>
using namespace std;

#define SIZE 5

//int SIZE = 5;
char ALIVE = 'm';
char DEAD = ' ';


void fillMap(char map[SIZE][SIZE]) {
    for(int c = 0; c < SIZE; c++) {
        for(int r = 0; r < SIZE; r++) {
            cout << (map[c][r] = ((rand() % 2 == 1) ? 'm' : ' ')) << ' ';
        }
        cout << endl;
    }
}

void increment(int a[][1]) {
    a[0][0] = a[0][0] + 1;
    cout << "a in increment " << a[0][0] << endl;
}

void clearScreen() {
    cout << string( 20, '\n' );
}

int numNeighbors(char map[][SIZE], int c, int r) {
    int sum = 0;

    //left column
    sum += map[c-1][r-1] == ALIVE ? 1 : 0;
        cout << map[c-1][r-1] << endl;
    sum += map[c][r-1] == ALIVE ? 1 : 0;
        cout << map[c][r-1] << endl;
    sum += map[c+1][r-1] == ALIVE ? 1 : 0;
        cout << map[c+1][r-1] << endl;

    //middle column
    sum += map[c-1][r] == ALIVE ? 1 : 0;
        cout << map[c-1][r] << endl;
    sum += map[c+1][r] == ALIVE ? 1 : 0;
        cout << map[c+1][r] << endl;

    //right column
    sum += map[c-1][r+1] == ALIVE ? 1 : 0;
        cout << map[c-1][r+1] << endl;
    sum += map[c][r+1] == ALIVE ? 1 : 0;
        cout << map[c][r+1] << endl;
    sum += map[c+1][r+1] == ALIVE ? 1 : 0;
        cout << map[c+1][r+1] << endl;

    return sum;
}

int main()
{


    string q = "l";
    while(q != "q") {
//    int q[][1] = { {3} };
//    increment(q);
//    cout << "q in main " << q[0][0] << endl;

    char map[SIZE][SIZE];
    fillMap(map);
//    for(int c = 0; c < SIZE; c++) {
//        for(int r = 0; r < SIZE; r++) {
//            //cout << (map[c][r] = ((rand() % 2 == 1) ? 'm' : ' ')) << ' ';
//            map[c][r] = ((rand() % 2 == 1) ? 'm' : ' ');
//            cout << map[c][r] << ' ';
//        }
//        cout << endl;
//
//    }

    //char test[5][5];
    char test[5][5] = { { DEAD, DEAD, DEAD, DEAD, ALIVE },
                        { DEAD, DEAD, DEAD, DEAD, DEAD },
                        { DEAD, DEAD, DEAD, DEAD, DEAD },
                        { DEAD, DEAD, DEAD, DEAD, DEAD },
                        { DEAD, DEAD, DEAD, DEAD, DEAD }, };



    cout << map[1][1] << endl;
    cout << numNeighbors(test, 0, 0) << endl;
    cout << "SIZE: " << SIZE << endl;
    cin >> q;


////    char map[][SIZE];
////    fillMap(map);

//    int arr[5] = { 0, 1, 2, 3, 4 };
//    cout << sizeof(arr)/sizeof(arr[0]) << endl;

    clearScreen();
    }
}





