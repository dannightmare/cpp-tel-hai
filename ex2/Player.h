#ifndef PLAYER_H
#define PLAYER_H

class Player
{
  public:
    // Player()
    //   : letter('\0')
    // {
    // }
    Player() = delete;
    Player(char letter)
      : letter(letter)
    {
    }

    // copy constructor
    Player(const Player& other)
      : letter(other.letter){}

    // operator=
    Player& operator=(const Player& other)
    {
        if(this != &other) {
            letter = other.letter;
        }
        return *this;
    }

    // get the letter as capital
    char getCapital() const;
    // get the letter as lowercase
    char getLower() const;



  private:
    char letter;
};

#endif // PLAYER_H