#ifndef INVALID_MOVE_EXCEPTION_H
#define INVALID_MOVE_EXCEPTION_H

#include <iostream>
#include <cstring>


void
copystr(const char* src, char* dest)
{
    if (std::strlen(src) == 0)
        throw long(2);
    strcpy(dest, src);
}

struct InvalidMoveException
{
    char* message;

    InvalidMoveException(const char* message)
    {
        this->message = new char[strlen(message) + 1];
        copystr(message, this->message);
    }
};

#endif