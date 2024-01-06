// Selection Sort

#include <stdio.h>

#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity - The time  complexity of Selection Sort is O(N^2) because
there are two nested for loops
2. Space Complexity - The space complexity of Selection Sort is O(1) because one
extra memory space is being used for storing a temporary variable of
min_value_index.
*/

auto constexpr array_size = 10;
std::array<int, array_size> array_to_sort_mine = {};
std::array<int, array_size> array_to_sort_official = {};

void selection_sort(std::array<int, array_size> &array_to_sort) {
    int min_value_index;

    for (int i = 0; i < array_size - 1; i++) {
        min_value_index = i;

        for (int j = i; j < array_size; j++) {
            if (array_to_sort[j] < array_to_sort[min_value_index]) {
                min_value_index = j;
            }
        }

        std::swap(array_to_sort[i], array_to_sort[min_value_index]);
    }
}

int main() {
    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official);

    selection_sort(array_to_sort_mine);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
