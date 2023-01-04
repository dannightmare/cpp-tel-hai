#include <iostream>
#include "String.h"

bool isPalindromeRec(String str) {
    if(str.length() <= 1) return true;
    if(str.at(0) == str.at(str.length() - 1)) {
        return isPalindromeRec(str.substring(1, str.length() - 1));
    }
    return false;
}

int main() {
    String strarr[3];

    for (int i = 1; i < 3; i++) {
        strarr[i] = strarr[0].copy();
    }

    strarr[0].assign("STR1");
    strarr[1].assign("STR2");
    strarr[2].assign("STR3");

    for (int i = 0; i < 3; i++) {
        strarr[i].print();
    }

    strarr[0].assign("Hello olleH");    // odd
    strarr[1].assign("asddsa");         // even
    strarr[2].assign("not a pal");      // not a palindrome

    std::cout << isPalindromeRec(strarr[0]) << std::endl;
    std::cout << isPalindromeRec(strarr[1]) << std::endl;
    std::cout << isPalindromeRec(strarr[2]) << std::endl;

    return 0;
}
