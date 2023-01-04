//
//  Author Daniel Kusai to Tel-Hai 321930489
//
#include <iostream>
#include <sstream>

using namespace std;

void rPrint() {
    string s;
    if (getline(cin, s)) {
        rPrint();
        cout << s << endl;
    }
}

bool string_to_int(string str, int &i) {
    try {
        int num = stoi(str);
        i = num;
        return true;
    }
    catch (invalid_argument invalidArgument) {
        return false;
    }
}

bool str_to_ints(const char *str, int *arr, int arrlen) {
    stringstream ss;
    ss << str;
    string s;
    int i = 0;
    while (!ss.eof() && i < arrlen) {
        ss >> s;
        if (!string_to_int(s, arr[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
//    rPrint();
    int arr[5];
    str_to_ints("123 321 543", arr, 5);
    cout << arr[0] << arr[1] << arr[2];     // 123321543

    return 0;
}
