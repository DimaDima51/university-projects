#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>*> A;

    for (int i = 0; i < 4; ++i) {
        vector<int>* ptr = new vector<int>(2);
        (*ptr)[0] = i % 2;
        (*ptr)[1] = 1 - i % 2;
        A.push_back(ptr);
    }

    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < (*A[i]).size(); ++j) {
            cout << (*(A[i]))[j] << " ";
        }
        cout << '\n';
    }

    for (auto ptr : A) {
        delete ptr;
    }

    return 0;
}