#include <iostream>

template <typename T>
int findIndex(const T* array, int size, const T& target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int intArray[5] = {10, 20, 30, 40, 50};
    int targetInt = 30;
    std::cout << "Индекс элемента " << targetInt << " : " << findIndex(intArray, 5, targetInt) << '\n';

    std::string stringArray[3] = {"cat", "mouse", "dog"};
    std::string targetStr = "cat";
    std::cout << "Индекс элемента " << targetStr << " : " << findIndex(stringArray, 3, targetStr) << '\n';

    return 0;
}
