// Selection Sort

#include <iostream>
#include <stdio.h>
#include <../../utility/utility.cpp>

/*
    1. Time  Complexity - The time  complexity of Selection Sort is O(N^2) because there are two nested for loops
    2. Space Complexity - The space complexity of Selection Sort is O(1)   because one extra memory space is being used for storing a temporary variable of min_value_index.
*/

void selection_sort(int array_to_sort[], int array_size) {

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

    const int array_size                  = 10;
    // int array_to_sort_mine[array_size]     = {25, 64, 333, 12, 22, 11};
    // int array_to_sort_official[array_size] = {25, 64, 333, 12, 22, 11};

    int array_to_sort_mine[array_size];
    int array_to_sort_official[array_size];

    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official, array_size);

    selection_sort(array_to_sort_mine, array_size);
    std::sort(array_to_sort_official, array_to_sort_official + array_size);

    compare_array(array_to_sort_mine, array_to_sort_official, array_size);
}
