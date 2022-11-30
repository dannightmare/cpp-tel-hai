

class Player
{
public:
    Player() : letter('\0') {}
    Player(char letter) : letter(letter) {}

    // get the letter as capital
    char getCapital();
    // get the letter as lowercase
    char getLower();

private:
    char letter;
};