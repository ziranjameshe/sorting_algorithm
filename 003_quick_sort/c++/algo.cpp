// Quick Sort

#include <stdio.h>

#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity - The time  complexity of Quick Sort is: O(N * log(N)) for
average case and best case O(N^2) for worst case
2. Space Complexity - The space complexity of Quick Sort is O(1) because there
is no extra variable being used during sorting
*/

auto constexpr array_size = 31;
std::array<int, array_size> array_to_sort_mine = {};
std::array<int, array_size> array_to_sort_official = {};

int partition(std::array<int, array_size> &array_to_sort, int low, int high) {
    int pivot = array_to_sort[high];

    int i = low;

    for (size_t j = low; j < high; j++) {
        if (array_to_sort[j] < pivot) {
            std::swap(array_to_sort[i], array_to_sort[j]);
            i++;
        }
    }

    std::swap(array_to_sort[i], array_to_sort[high]);

    return i;
}

void quick_sort(std::array<int, array_size> &array_to_sort, int low, int high) {
    if (low < high) {
        int partition_index = partition(array_to_sort, low, high);

        quick_sort(array_to_sort, low, partition_index - 1);
        quick_sort(array_to_sort, partition_index + 1, high);
    }
}

auto main() -> int {
    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official);

    quick_sort(array_to_sort_mine, 0, array_size - 1);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
