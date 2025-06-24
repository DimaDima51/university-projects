#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> list1 = {9, 4, 5, 6, 3, 8, 5, 9, 0, 4};
    
    // Выводим исходный список
    cout << "Исходный список: ";
    for (auto elem : list1) {
        cout << elem << " ";
    }
    cout << '\n';

    list1.sort();

    cout << "После сортировки: ";
    for (auto elem : list1) {
        cout << elem << " ";
    }
    cout << '\n';

    list1.unique();

    cout << "После unique: ";
    for (auto elem : list1) {
        cout << elem << " ";
    }
    cout << '\n';

    int element;
    cout << "Удалить элемент: ";
    cin >> element;
    list1.remove(element);
    cout << "После удаления " << element << ": ";
    for (auto elem : list1) {
        cout << elem << " ";
    }
    cout << '\n';

    list<int> list2 = {1, 6, 8};
    
    list1.merge(list2);
    cout << "После merge с {1, 6, 8}: ";
    for (auto elem : list1) {
        cout << elem << " ";
    }
    cout << '\n';
    
    cout << "Второй список после merge (пуст): ";
    for (auto elem : list2) {
        cout << elem << " ";
    }
    cout << '\n';

    return 0;
}