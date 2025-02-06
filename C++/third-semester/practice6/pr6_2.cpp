/*
Написать рекурсивную функцию вычисления суммы элементов одномерного массива.
*/

#include <iostream>

int sumArray(int arr[], int size) {
    if (size == 0) return 0;
    return arr[size - 1] + sumArray(arr, size - 1);
}

/*
                        1 2 3 4 5
    5                   1 2 3 4
    4 + 5               1 2 3
    3 + 4 + 5           1 2
    2 + 3 + 4 + 5       1
    1 + 2 + 3 + 4 + 5   0
*/

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int result = sumArray(arr, sizeof(arr) / sizeof(arr[0]));
    std::cout << "Сумма элементов массива: " << result << '\n';

    return 0;
}
