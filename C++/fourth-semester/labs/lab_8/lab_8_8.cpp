// sort() принимает в третьем параметре бинарный предикат, который возвращает
// true если элемент a строго меньше b, иначе false

#include <algorithm>
#include <vector>
#include <iostream>

bool myLess(int a, int b) {
    return a < b;   // true, если a < b
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    std::sort(v.begin(), v.end(), myLess);
    for (int x : v) std::cout << x << ' ';  // 1 1 3 4 5 9
}
