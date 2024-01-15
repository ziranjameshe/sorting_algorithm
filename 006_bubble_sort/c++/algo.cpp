// Bubble Sort
#include <stdio.h>

#include <array>
#include <cmath>
#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity - The time  complexity of Bubble Sort is: O(N * log(N))
2. Space Complexity - The space complexity of Bubble Sort is O(1)
*/

// constexpr size_t array_size = 6;
// std::array<int, array_size> array_to_sort_mine = {25, 64, 333, 12, 22, 11};
// std::array<int, array_size> array_to_sort_official = {25, 64, 333, 12, 22,
// 11};

constexpr size_t array_size = 6;
std::array<int, array_size> array_to_sort_mine = {};
std::array<int, array_size> array_to_sort_official = {};

template <size_t N>
auto bubble_sort(std::array<int, N> &array) -> void {
    for (size_t i = 0; i < N - 1; i++) {
        // bool swapped = false;
        for (size_t j = 0; j < N - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                // swapped = true;
            }
        }
        // if (swapped == true) {
        //     break;
        // }
    }
}

int main() {
    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official);

    bubble_sort(array_to_sort_mine);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
