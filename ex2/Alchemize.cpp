
#include <iostream>
#include "Alchemize.h"

using namespace std;

Alchemize::Alchemize(int side) : side(side), numplayers(2)
{
    matrix = new Item **[side];
    for (int i = 0; i < side; i++)
        matrix[i] = new Item *[side];
    // players = {Player('r'), Player('b')};
    players = new Player *[numplayers];
    *players[0] = Player('r');
    *players[1] = Player('b');

    init();
}

// Alchemize::Alchemize(int row, int col, const char *letters, int numplayers)
//     : row(row), col(col), numplayers(numplayers)
// {
// }

Alchemize::~Alchemize()
{
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] players;
}

void Alchemize::init()
{
    while (true)
    {
        printBoard();
        printTurn();
        doTurn();
        if (isBoardFull())
        {
            checkWinner();
            return;
        }
        nextTurn();
    }
}

void Alchemize::printBoard()
{
    // I want to clear the screen according to system
#ifdef __APPLE__ || __linux__
    system("clear");
#elif defined _WIN32 || defined _WIN64
    system("cls");
#endif // __APPLE__

    /// TODO: print board
}

void Alchemize::printTurn()
{
    cout << players[turn]->getCapital() << ":" << endl;
}

void Alchemize::doTurn()
{
    int row, col;
    cin >> row >> col;
    col--;
    row--;

    if (row < 0 || row >= side || col < 0 || col >= side || !isCellEmpty(row, col))
    {
        cerr << "Invalid row/col index or non free cell" << endl;
    }

    matrix[row][col] = new Potion(*players[turn]);
    if (dynamic_cast<const Potion *>(matrix[row][col]));
}