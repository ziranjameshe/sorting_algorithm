#include <iostream>
#pragma once

template <size_t N>
auto fill_arrays_with_random_values(std::array<int, N> &array_a,
                                    std::array<int, N> &array_b, int seed = 100)
    -> void {
    for (size_t i = 0; i < N; i++) {
        auto const random_value = std::rand() % seed;
        array_a[i] = random_value;
        array_b[i] = random_value;
    }

    std::copy(array_a.begin(), array_a.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");
}
template <size_t N>
auto compare_array(std::array<int, N> const &array_a,
                   std::array<int, N> const &array_b) -> bool {
    std::printf("Mine: ");
    std::copy(array_a.begin(), array_a.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n");

    std::printf("std : ");
    std::copy(array_b.begin(), array_b.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");

    for (int i = 0; i < N; i++) {
        if (array_a[i] != array_b[i]) {
            printf("array_a[%d] = %d != array_b[%d] = %d\n", i, array_a[i], i,
                   array_b[i]);
            printf("Fail!\n");
            return false;
        }
    }

    printf("Success!\n");
    return true;
}
