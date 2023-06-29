// Quick Sort

#include <iostream>
#include <stdio.h>
#include "../../utility/utility.cpp"

/*
    1. Time  Complexity - The time  complexity of Quick Sort is:
                                                                O(N * log(N)) for average case and best case
                                                                O(N^2)        for worst case
    2. Space Complexity - The space complexity of Quick Sort is O(1) because there is no extra variable being used during sorting
*/


void merge(int array_to_sort[], int low, int mid, int high) {

    int sub_array_left_size  = mid - low + 1;
    int sub_array_right_size = high - mid;

    int sub_array_left[sub_array_left_size];
    int sub_array_right[sub_array_right_size];

    for (int i = 0; i < sub_array_left_size; i++) {
        sub_array_left[i] = array_to_sort[low + i];
    }

    for (int i = 0; i < sub_array_right_size; i++) {
        sub_array_right[i] = array_to_sort[mid + i + 1];
    }

    int sub_array_left_index = 0, sub_array_right_index = 0;
    int merged_array_index = low;

    while (sub_array_left_index < sub_array_left_size && sub_array_right_index < sub_array_right_size) {

        if (sub_array_left[sub_array_left_index] <= sub_array_right[sub_array_right_index]) {

            array_to_sort[merged_array_index] = sub_array_left[sub_array_left_index];
            sub_array_left_index += 1;

        } else {

            array_to_sort[merged_array_index] = sub_array_right[sub_array_right_index];
            sub_array_right_index += 1;

        }

        merged_array_index += 1;

    }

    while (sub_array_left_index < sub_array_left_size) {
        array_to_sort[merged_array_index] = sub_array_left[sub_array_left_index];
        sub_array_left_index += 1;
        merged_array_index   += 1;
    }

    while (sub_array_right_index < sub_array_right_size) {
        array_to_sort[merged_array_index] = sub_array_right[sub_array_right_index];
        sub_array_right_index += 1;
        merged_array_index    += 1;
    }

}

void merge_sort(int array_to_sort[], int low, int high) {

    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;
    merge_sort(array_to_sort, low, mid);
    merge_sort(array_to_sort, mid + 1, high);
    merge(array_to_sort, low, mid, high);

}

int main() {

    const int array_size                   = 20;
    // int array_to_sort_mine[array_size]     = {25, 64, 333, 12, 22, 11};
    // int array_to_sort_official[array_size] = {25, 64, 333, 12, 22, 11};

    int array_to_sort_mine[array_size];
    int array_to_sort_official[array_size];

    fill_arrays_with_random_values(array_to_sort_mine, array_to_sort_official, array_size, 200);

    merge_sort(array_to_sort_mine, 0, array_size - 1);
    std::sort(array_to_sort_official, array_to_sort_official + array_size);

    compare_array(array_to_sort_mine, array_to_sort_official, array_size);
}
