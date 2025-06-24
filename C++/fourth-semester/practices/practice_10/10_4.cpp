#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef set<int, less<int>> type_set;

type_set operator*(const type_set& A, const type_set& B) {
    type_set I;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(I, I.begin()));
    return I;
}

int main() {
    type_set A = {1, 2, 3, 4};
    type_set B = {3, 4, 5, 6};
    type_set result = A * B;

    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << '\n';

    return 0;
}