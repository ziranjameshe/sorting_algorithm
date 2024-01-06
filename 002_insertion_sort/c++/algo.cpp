// Insertion Sort

#include <stdio.h>

#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity - The time  complexity of Insertion Sort is O(N^2) because
there are two nested for loops
2. Space Complexity - The space complexity of Insertion Sort is O(0) because
there is no extra variable being used during sorting
*/

auto constexpr array_size = 10;
std::array<int, array_size> array_to_sort_mine = {};
std::array<int, array_size> array_to_sort_official = {};

auto insertion_sort(std::array<int, array_size> &array_to_sort) -> void {
    for (int i = 1; i < array_size; i++) {
        for (int j = i; j > 0; j--) {
            if (array_to_sort[j - 1] > array_to_sort[j]) {
                std::swap(array_to_sort[j - 1], array_to_sort[j]);

            } else {
                break;
            }
        }
    }
}

auto main() -> int {
    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official);

    insertion_sort(array_to_sort_mine);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
