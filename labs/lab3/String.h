//
// Created by Daniel Kusai on 15/11/2022.
//

#ifndef LAB3_STRING_H
#define LAB3_STRING_H


class String {
public:
    String();
    String(const char* str);
    void destroy();
    void assign(const char* str);
    void print() const;
    String copy() const;
    int length() const;
    char at(int index) const;
    String substring(int start, int end) const;
    String substring(int start) const;
    void replace(int index, char val);
    static bool equals(const String& string_a, const String& string_b);

private:
    int len;
    char* c_str;
};


#endif //LAB3_STRING_H
