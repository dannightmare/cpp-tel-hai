#ifndef ALCHEMIZE_H
#define ALCHEMIZE_H

#include "Crystal.h"
#include "Hole.h"
#include "Item.h"
#include "Player.h"
#include "Potion.h"

class Alchemize
{
  public:
    // c'tors
    // need arguments
    Alchemize() = delete;
    // default 2 players r and b
    Alchemize(int side);
    // non-default hook for more players UNUSED
    // Alchemize(int side, const char *letters, int numplayers);

    // d'tor
    ~Alchemize();

    // this is the only Alchemize and it is destroyed upon finishing
    // so I don't have a use for copy constructors
    // and same for copy operator=
    Alchemize& operator=(const Alchemize& rhs) = delete;
    Alchemize(Alchemize& other) = delete;
  private:
    int side;
    Item*** matrix;
    Player** players;
    int numplayers;
    int turn = 0;
    void init();
    void printBoard();
    void printTurn();
    bool doTurn();
    bool isBoardFull();
    void checkWinner();
    int countCrystals(Player& player);
    void nextTurn();
    bool isCellEmpty(int row, int col);
    void updateCell(int row, int col);
    void fillCrystals(int row, int col);
};

#endif // ALCHEMIZE_H