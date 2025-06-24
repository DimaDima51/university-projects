#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main() {

    string s = "gghhk";

    try {
        s.replace(-2, 2, "hello", 3); 
        cout << "После replace: " << s << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    try {
        int num = stoi("abc"); // не число
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        // не может выделить память
        vector<int> v;
        v.reserve(1e12);
    }
    catch (const bad_alloc& e) {
        cout << e.what() << endl;
    }

    return 0;
}
