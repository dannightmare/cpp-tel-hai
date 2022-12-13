#include <iostream>

#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
  public:
    Robot();
    virtual ~Robot();
    Robot& operator=(const Robot& other);
    Robot(const Robot& other);
    Robot(int speed, int chance);

    // move operators are not needed

    int getLocation() const { return location; }
    int getSpeed() const { return speed; }
    int getChance() const { return chance; }
    void setLocation(int loc) { location = loc; }
    void setSpeed(int s) { speed = s; }
    void setChance(int s) { chance = s; }

    virtual char getLetter() const { return 'R'; }

    virtual void move(std::string& str);

  private:
    int location;
    int speed;
    int chance;
};

#endif // ROBOT_H