// Shell Sort
#include <stdio.h>

#include <array>
#include <cmath>
#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity - The time  complexity of Shell Sort is: O(N^2)
2. Space Complexity - The space complexity of Shell Sort is O(1)
*/

// constexpr size_t array_size = 6;
// std::array<int, array_size> array_to_sort_mine = {25, 64, 333, 12, 22, 11};
// std::array<int, array_size> array_to_sort_official = {25, 64, 333, 12, 22,
// 11};

constexpr size_t array_size = 91;
std::array<int, array_size> array_to_sort_mine = {};
std::array<int, array_size> array_to_sort_official = {};

template <size_t N>
auto shell_sort(std::array<int, N> &array) -> void {
    for (int interval = N / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < N; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp;
                 j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

int main() {
    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official);

    shell_sort(array_to_sort_mine);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
