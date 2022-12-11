
#include "Alchemize.h"
#include <iostream>

using namespace std;

Alchemize::Alchemize(int side)
  : side(side)
  , numplayers(2)
{
    matrix = new Item**[side];
    for (int i = 0; i < side; i++)
        matrix[i] = new Item*[side];
    // players = {Player('r'), Player('b')};
    players = new Player*[numplayers];
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
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] players;
}

void
Alchemize::init()
{
    while (true) {
        printBoard();
        printTurn();
        doTurn();
        if (isBoardFull()) {
            checkWinner();
            return;
        }
        nextTurn();
    }
}

void
Alchemize::nextTurn()
{
    turn++;
    if (turn == numplayers)
        turn = 0;
}

void
Alchemize::checkWinner()
{
    int redCrystals = countCrystals(*players[0]);
    int blueCrystals = countCrystals(*players[1]);

    if (redCrystals > blueCrystals) {
        cout << "Red won" << endl;
    } else if (redCrystals < blueCrystals) {
        cout << "Blue won" << endl;
    } else {
        cout << "The game ended with a tie" << endl;
    }
}

int
Alchemize::countCrystals(Player& player)
{
    int count = 0;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (matrix[i][j]->getLetter() == player.getLower()) {
                count++;
            }
        }
    }
    return count;
}

bool
Alchemize::isBoardFull()
{
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (matrix[i][j] == nullptr)
                return false;
        }
    }
    return true;
}

bool
Alchemize::isCellEmpty(int row, int col)
{
    return matrix[row][col] == nullptr;
}

void
Alchemize::printBoard()
{
    // I want to clear the screen according to system
#if defined(__APPLE__) || defined(__linux__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif // __APPLE__

    /// TODO: print board
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << matrix[i][j]->getLetter() << " ";
        }
    }
}

void
Alchemize::printTurn()
{
    cout << players[turn]->getCapital() << ":" << endl;
}

void
Alchemize::doTurn()
{
    int row, col;
    cin >> row >> col;
    col--;
    row--;

    if (row < 0 || row >= side || col < 0 || col >= side ||
        !isCellEmpty(row, col)) {
        cerr << "Invalid row/col index or non free cell" << endl;
    }

    matrix[row][col] = new Potion(*players[turn]);
    fillCrystals(row, col);
    // this is how to find out the type of item in the matrix
    // if (dynamic_cast<const Potion *>(matrix[row][col]));
}

void
Alchemize::fillCrystals(int row, int col)
{
    for (int i = row - 1; i < row + 1; i++) {
        for (int j = col - 1; j < col + 1; j++) {
            if (i >= side || j >= side || i < 0 || j < 0) {
                continue;
            }
            if (dynamic_cast<const Crystal*>(matrix[i][j]) ||
                isCellEmpty(i, j)) {
                updateCell(i, j);
            }
        }
    }
}

void
Alchemize::updateCell(int row, int col)
{
    int redPotions = 0;
    int bluePotions = 0;
    for (int i = row - 1; i < row + 1; i++) {
        for (int j = col - 1; j < col + 1; j++) {
            if (i >= side || j >= side || i < 0 || j < 0) {
                continue;
            }
            const Potion* temp = dynamic_cast<const Potion*>(matrix[i][j]);
            if (temp) {
                if (temp->getOwner() == players[0]) {
                    redPotions++;
                }
                if (temp->getOwner() == players[1]) {
                    bluePotions++;
                }
            }
        }
    }
    if (redPotions > 0 && bluePotions > 0) {
        matrix[row][col] = new Potion(*players[turn]);
    }
}