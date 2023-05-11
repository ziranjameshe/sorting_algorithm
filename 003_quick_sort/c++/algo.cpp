// Quick Sort

#include <iostream>
#include <stdio.h>
#include "../../utility/utility.cpp"

/*
    1. Time  Complexity - The time  complexity of Quick Sort is O(N^2) because there are two nested for loops
    2. Space Complexity - The space complexity of Quick Sort is O(0)   because there is no extra variable being used during sorting
*/

int partition(int array_to_sort[], int low, int high) {

    int pivot = array_to_sort[high];

    int i = low;

    for (int j = low; j < high; j++) {

        if (array_to_sort[j] < pivot) {

            std::swap(array_to_sort[i], array_to_sort[j]);
            i++;
        }
    }

    std::swap(array_to_sort[i], array_to_sort[high]);

    return i;

}

void quick_sort(int array_to_sort[], int low, int high) {

    if (low < high) {

        int partition_index = partition(array_to_sort, low, high);

        quick_sort(array_to_sort, low, partition_index - 1);
        quick_sort(array_to_sort, partition_index + 1, high);
    }

}

int main() {

    const int array_size                   = 31;
    // int array_to_sort_mine[array_size]     = {25, 64, 333, 12, 22, 11};
    // int array_to_sort_official[array_size] = {25, 64, 333, 12, 22, 11};

    int array_to_sort_mine[array_size];
    int array_to_sort_official[array_size];

    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official, array_size, 1000);

    quick_sort(array_to_sort_mine, 0, array_size - 1);
    std::sort(array_to_sort_official, array_to_sort_official + array_size);

    compare_array(array_to_sort_mine, array_to_sort_official, array_size);
}
