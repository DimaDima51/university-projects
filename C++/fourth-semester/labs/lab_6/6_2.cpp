#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class MySet {
    std::vector<T> elems;

public:
    // 1) Добавление элемента в множество
    void add(const T& value) {
        if (!contains(value))
            elems.push_back(value);
    }

    // 2) Удаление элемента из множества
    void remove(const T& value) {
        auto it = std::find(elems.begin(), elems.end(), value);
        if (it != elems.end())
            elems.erase(it);
    }

    // 3) Принадлежность элемента множеству
    bool contains(const T& value) const {
        return std::find(elems.begin(), elems.end(), value) != elems.end();
    }

    // 4) Пересечение множеств
    MySet intersect(const MySet& other) const {
        MySet result;
        for (const auto& e : elems)
            if (other.contains(e))
                result.add(e);
        return result;
    }

    // 5) Объединение множеств
    MySet unite(const MySet& other) const {
        MySet result = *this;
        for (const auto& e : other.elems)
            result.add(e);
        return result;
    }

    // 6) Разность множеств
    MySet difference(const MySet& other) const {
        MySet result;
        for (const auto& e : elems)
            if (!other.contains(e))
                result.add(e);
        return result;
    }

    void print() const {
        for (const auto& e : elems)
            std::cout << e << " ";
        std::cout << "\n";
    }
};


int main() {
    MySet<int> set1, set2;
    set1.add(1); set1.add(2); set1.add(3);
    set2.add(2); set2.add(3); set2.add(4);
    
    std::cout << "set1: ";
    set1.print(); // 1 2 3
    std::cout << "set2: ";
    set2.print(); // 2 3 4

    std::cout << "Пересечение: ";
    auto intersection = set1.intersect(set2);
    intersection.print(); // 2 3

    std::cout << "Объединение: ";
    auto union_set = set1.unite(set2);
    union_set.print(); // 1 2 3 4

    std::cout << "Разница: ";
    auto difference = set1.difference(set2);
    difference.print(); // 1

    set1.remove(2);
    std::cout << "set1 содержит 2? " << set1.contains(2) << "\n";
    std::cout << "set1 после удаления: ";
    set1.print(); // 1 3

    return 0;
}