// Selection Sort

#include <iostream>
#include <stdio.h>
#include "../../utility/utility.h"

void insertion_sort(int array_to_sort[], int array_size) {

    int j;
    for (int i = 1; i < array_size; i++) {

        for (j = i; j > 0; j--) {

            if (array_to_sort[j - 1] > array_to_sort[j]) {

                std::swap(array_to_sort[j - 1], array_to_sort[j]);

            } else {

                break;
            }
        }
    }
}

int main() {

    const int array_size                   = 10;
    // int array_to_sort_mine[array_size]     = {25, 64, 333, 12, 22, 11};
    // int array_to_sort_official[array_size] = {25, 64, 333, 12, 22, 11};

    int array_to_sort_mine[array_size];
    int array_to_sort_official[array_size];

    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official, array_size);

    insertion_sort(array_to_sort_mine, array_size);
    std::sort(array_to_sort_official, array_to_sort_official + array_size);

    compare_array(array_to_sort_mine, array_to_sort_official, array_size);
}
