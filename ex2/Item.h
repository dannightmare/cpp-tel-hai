
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