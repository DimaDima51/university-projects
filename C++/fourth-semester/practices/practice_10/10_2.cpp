#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> A = {{1, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 1, 1},
                            {1, 0, 0, 1}};
    
    for (auto row : A) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << '\n';
    }
    
    return 0;
}