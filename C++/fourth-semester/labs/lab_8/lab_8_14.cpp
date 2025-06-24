// Адаптируемый функтор – это функтор, который позволяет указывать
// типы аргументов и возвращаемого значения, чтобы его могли
// использовать объекты адаптеров функций.
// Binder1st и binder2nd – это функциональные адаптеры,
// которые связывают заданное значение с первым или вторым параметром заданной функции.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> nums = {1, 5, 2, 8, 3, 6, 9};
    int threshold1 = 5;

    std::cout << "nums: ";
    for (int num : nums) {
        std::cout << num << " ";
    }

    // Использование bind1st для создания унарного предиката: threshold1 < num
    auto it = std::remove_if(nums.begin(), nums.end(), std::bind1st(std::less<int>(), threshold1));

    nums.erase(it, nums.end());

    std::cout << "\nПосле удаления элементов меньше " << threshold1 << ": ";
    for (int num : nums) {
        std::cout << num << " ";
    }

    std::vector<int> nums5 = {1, 5, 2, 8, 3, 6, 9};

    std::cout << "\nnums5: ";
    for (int num : nums5) {
        std::cout << num << " ";
    }

    // Использование bind2nd для создания унарного предиката: num < threshold1
    auto it2 = std::remove_if(nums5.begin(), nums5.end(), std::bind2nd(std::less<int>(), threshold1));

    nums5.erase(it2, nums5.end());

    std::cout << "\nПосле удаления элементов больше " << threshold1 << ": ";
    for (int num : nums5) {
        std::cout << num << " ";
    }

    return 0;
}
