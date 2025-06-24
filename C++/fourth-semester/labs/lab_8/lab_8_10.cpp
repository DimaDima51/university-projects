#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
struct GreaterThan {
    T m2;   // второй аргумент хранится здесь

    explicit GreaterThan(const T& threshold) : m2(threshold) { } // запоминаем второй аргумент

    // operator() принимает только m1 и сравнивает с сохранённым m2
    bool operator()(const T& m1) const {
        return m1 > m2; // эквивалент func(m1,m2)
    }
};

int main() {
    std::vector<int> v = { 1, 4, 2, 7, 5 };

    GreaterThan<int> greaterThan(3);

    auto it = std::find_if(v.begin(), v.end(), greaterThan);
    if (it != v.end())
        std::cout << "Первое число больше 3 это: " << *it << '\n';  // выведет 4

    return 0;
}
