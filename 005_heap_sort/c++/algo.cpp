// Heap Sort
#include <stdio.h>

#include <array>
#include <cmath>
#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity - The time  complexity of Heap Sort is: O(N * log(N))
2. Space Complexity - The space complexity of Heap Sort is O(1)
*/

// constexpr size_t array_size = 6;
// std::array<int, array_size> array_to_sort_mine = {25, 64, 333, 12, 22, 11};
// std::array<int, array_size> array_to_sort_official = {25, 64, 333, 12, 22,
// 11};

constexpr size_t array_size = 9;
std::array<int, array_size> array_to_sort_mine = {};
std::array<int, array_size> array_to_sort_official = {};

template <size_t N>
auto heapify(std::array<int, N> &array, size_t n, int i) -> void {
    auto const left = 2 * i + 1;
    auto const right = 2 * i + 2;

    auto max = i;
    if (left < n && array[left] > array[i]) {
        max = left;
    }

    if (right < n && array[right] > array[max]) {
        max = right;
    }

    if (max != i) {
        std::swap(array[i], array[max]);
        heapify(array, n, max);
    }
}

template <size_t N>
auto build_max_heap(std::array<int, N> &array) -> void {
    for (int i = N / 2; i >= 0; i--) {
        heapify(array, N, i);
    }
}

template <size_t N>
auto heap_sort(std::array<int, N> &array) -> void {
    build_max_heap(array);

    for (int i = N - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official);

    heap_sort(array_to_sort_mine);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
