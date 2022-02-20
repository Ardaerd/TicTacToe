#include "Game.h"

Game :: Game() {
    init();
}


void Game::init() {

    this->clicked = new int*[3];
    for (int i = 0; i < 3; i++)
        this->clicked[i] = new int[3];

    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++)
            this->clicked[row][column] = -1;
    }
}


void Game::setCurrentItemData(int row, int column,int data) {
    this->clicked[row][column] = data;
}


int Game::getCurrentItemData(int row, int column) {
    return this->clicked[row][column];
}

void Game::printArray() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << clicked[row][column];
        }
        cout << endl;
    }
}


int Game::whoWin() {

    // For checking the horizontal places
    for (int i = 0; i < 3; i++) {
        int X_H = 0;
        int O_H = 0;
        int X_V = 0;
        int O_V = 0;
        for (int j = 0; j < 3; j++) {

            // Check horizontal places for X
            if (getCurrentItemData(j,i) == 1) {
                X_H++;
                if (X_H == 3)
                    return 1;
            }

            // Check verticle places for X
            if (getCurrentItemData(i,j) == 1) {
                X_V++;
                if (X_V == 3)
                    return 1;
            }

            // Check Cross places for X
            if ((getCurrentItemData(0,0) == 1) && (getCurrentItemData(1,1) == 1) && (getCurrentItemData(2,2) == 1) ||
                (getCurrentItemData(2,0) == 1) && (getCurrentItemData(1,1) == 1) && (getCurrentItemData(0,2) == 1)) {
                    return 1;
            }

            // Check horizontal places for O
            if (getCurrentItemData(j,i) == 0) {
                O_H++;
                if (O_H == 3)
                    return 0;
            }

            // Check verticle places for O
            if (getCurrentItemData(i,j) == 0) {
                O_V++;
                if (O_V == 3)
                    return 0;
            }

            // Check Cross places for O
            if ((getCurrentItemData(0,0) == 0) && (getCurrentItemData(1,1) == 0) && (getCurrentItemData(2,2) == 0) ||
                (getCurrentItemData(2,0) == 0) && (getCurrentItemData(1,1) == 0) && (getCurrentItemData(0,2) == 0)) {
                    return 0;
            }

        }
    }

    return -1;
}



