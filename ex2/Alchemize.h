
#include "Player.h"
#include "Item.h"
#include "Potion.h"
#include "Hole.h"
#include "Crystal.h"

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
private:
    int side;
    Item ***matrix;
    Player **players;
    int numplayers;
    int turn = 0;
    void init();
    void printBoard();
    void printTurn();
    void doTurn();
};