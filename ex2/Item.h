#ifndef ITEM_H
#define ITEM_H


/**
 * This behaves like the interface for all items
 * on the matrix.
 */
class Item
{
public:
    virtual ~Item() = 0;
    virtual char getLetter() = 0;
};

#endif // ITEM_H