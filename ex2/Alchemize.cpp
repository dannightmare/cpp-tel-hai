
#include "Alchemize.h"
#include "Crystal.h"
#include <iostream>

using namespace std;

Alchemize::Alchemize(int side)
  : side(side)
  , numplayers(2)
{

    matrix = new Item**[side];
    for (int i = 0; i < side; i++) {
        matrix[i] = new Item*[side];
        for (int j = 0; j < side; j++) {
            matrix[i][j] = nullptr;
        }
    }

    // debug
    // cout << "Alchemize::Alchemize" << endl;
    players = new Player*[numplayers];
    players[0] = new Player('r');
    players[1] = new Player('b');

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
        if (isBoardFull()) {
            checkWinner();
            return;
        }
        // printTurn();
        while (!doTurn())
            ;
        
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
            if (matrix[i][j] == nullptr)
                continue;
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
    // AUTOTEST: doesn't like this
// #if defined(__APPLE__) || defined(__linux__)
//     system("clear");
// #elif defined(_WIN32) || defined(_WIN64)
//     system("cls");
// #endif // __APPLE__
    cout << "Red count: " << countCrystals(*players[0])
         << "\tBlue count: " << countCrystals(*players[1]) << endl;
    /// TODO: print board
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (matrix[i][j] == nullptr) {
                cout << "O\t";
                continue;
            }
            cout << matrix[i][j]->getLetter() << "\t";
        }
        cout << endl;
    }
}

void
Alchemize::printTurn()
{
    cout << players[turn]->getCapital() << ":" << endl;
}

bool
Alchemize::doTurn()
{
    cout << players[turn]->getCapital() << ":" << endl;
    int row, col;
    cin >> row >> col;
    col--;
    row--;

    if (row < 0 || row >= side || col < 0 || col >= side ||
        !isCellEmpty(row, col)) {
        cerr << "Invalid row/col index or non free cell" << endl;
        return false;
    }

    matrix[row][col] = new Potion(*players[turn]);
    fillCrystals(row, col);
    // this is how to find out the type of item in the matrix
    // if (dynamic_cast<const Potion *>(matrix[row][col]));

    return true;
}

void
Alchemize::fillCrystals(int row, int col)
{
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= side || j >= side || i < 0 || j < 0) {
                /// TODO: remove debug line
                // cout << "Debug fillCrystal out of bounds" << endl;
                continue;
            }
            if (dynamic_cast<const Crystal*>(matrix[i][j]) ||
                isCellEmpty(i, j)) {
                // cout << "Debug fillCrystals: " << i << " " << j << endl;
                updateCell(i, j);
            }
        }
    }
}

void
Alchemize::updateCell(int row, int col)
{
    /// TODO: Possibly unnecessary since the cell is already empty
    // if (dynamic_cast<const Hole*>(matrix[row][col])) {
    //     return;
    // }
    int redPotions = 0;
    int bluePotions = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
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
    // cout << "Debug location: " << row << " " << col << endl;
    // cout << "Debug pots: " << redPotions << " " << bluePotions << endl;
    if (redPotions > 0 && bluePotions > 0) {
        matrix[row][col] = new Crystal(*players[turn]);
    }
    if (redPotions > 1 || bluePotions > 1) {
        if (matrix[row][col] != nullptr) {
            delete matrix[row][col];
        }
        matrix[row][col] = new Hole();
    }
}