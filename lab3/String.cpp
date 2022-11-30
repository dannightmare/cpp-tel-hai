//
// Created by Daniel Kusai on 15/11/2022.
//

#include "String.h"
#include <cstring>
#include <iostream>

String::String() {
    len = 0;
    c_str = strndup("", 0);
}

String::String(const char *str) {
    len = strlen(str);
    c_str = strndup(str, len);
}

void String::destroy() {
    delete[] c_str;
}

void String::assign(const char *str) {
    delete[] c_str;
    c_str = strdup(str);
    len = strlen(c_str);
}

void String::print() const {
    std::cout << c_str << std::endl;
}

String String::copy() const {
    return *new String(c_str);
}

int String::length() const {
    return len;
}

char String::at(int index) const {
    return c_str[index];
}

String String::substring(int start, int end) const {
    return *new String(strndup(c_str + start, end - start));
}

String String::substring(int start) const {

    if(start >= length()) {
        std::cerr<<"start in larger than length";
        exit(1);
    }
    return substring(start, length());
}

void String::replace(int index, char val) {
    if(index >= length()) {
        std::cerr<<"index larger than length";
        exit(2);
    }
    c_str[index] = val;
}

bool String::equals(const String &string_a, const String &string_b) {
    if(string_a.length() != string_b.length()) return false;
    if(!strcmp(string_a.c_str, string_b.c_str)) return true;
    return false;
}