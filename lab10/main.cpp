#include "Mule.h"

int
main(void)
{
    Animal** arrAnimal = new Animal*[6];

    arrAnimal[0] = new Donkey("EEEAAA", *new Gender(false));

    arrAnimal[1] = new Horse("Speed", *new Gender(false));

    arrAnimal[2] = new Mule("HULK", *new Gender(false));

    arrAnimal[3] = new Donkey("EEEAAA2", *new Gender(true));

    arrAnimal[4] = new Horse("Speed2", *new Gender(true));

    arrAnimal[5] = new Mule("HULK2", *new Gender(true));

    Animal* tmp;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if ((tmp = arrAnimal[i]->reproduce(*arrAnimal[j])) != nullptr) {
                tmp->speak();
            }
        }
    }

    return 0;
}