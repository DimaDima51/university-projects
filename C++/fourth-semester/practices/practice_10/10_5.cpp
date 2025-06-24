#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef set<int, less<int>> type_set;

// Оператор для объединения двух множеств
type_set operator+(const type_set& A, const type_set& B) {
    type_set I;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(I, I.begin()));
    return I;
}

int main() {
    type_set A = {1, 2, 3, 4};
    type_set B = {3, 4, 5, 6};
    
    cout << "Множество A: ";
    for (auto elem : A) cout << elem << " ";
    cout << endl;
    
    cout << "Множество B: ";
    for (auto elem : B) cout << elem << " ";
    cout << endl;
    
    type_set C = A + B;
    
    cout << "Объединение A и B: ";
    for (auto elem : C) cout << elem << " ";
    cout << endl;

    return 0;
}

/*

Функция operator+ корректно объединяет два множества с помощью алгоритма set_union, а затем возвращает новое множество, содержащее все уникальные элементы из обоих исходных множеств.

*/