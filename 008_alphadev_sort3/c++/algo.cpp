// alphadev Sort

#include <stdio.h>

#include <iostream>

#include "../../utility/utility.hpp"

/*
1. Time  Complexity -
2. Space Complexity -
*/

constexpr size_t array_size = 3;
std::array<int, array_size> array_to_sort_mine = {1, 4, 3};
std::array<int, array_size> array_to_sort_official = {1, 4, 3};

template <size_t N>
void sort3(std::array<int, N> &array) {
    int A = array[0];
    int B = array[1];
    int C = array[2];

    array[0] = std::min(std::min(A, B), C);
    array[1] = std::max(std::min(A, C), B);
    array[2] = std::max(A, C);
}

int main() {
    sort3(array_to_sort_mine);
    std::sort(array_to_sort_official.begin(), array_to_sort_official.end());

    compare_array(array_to_sort_mine, array_to_sort_official);
}
