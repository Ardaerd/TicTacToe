#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>

using namespace std;

class Game {
    public:
      int **clicked;
      Game();
      void updateToArray();
      void init();
      void setCurrentItemData(int row,int column,int data);
      int getCurrentItemData(int row,int column);
      void printArray();
      int whoWin();
};

#endif //TICTACTOE_GAME_H
